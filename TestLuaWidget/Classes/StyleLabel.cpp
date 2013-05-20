#include "StyleLabel.h"
#include "CCLuaEngine.h"

StyleLabel::StyleLabel(void)
:m_fLineWidth(0.25f)
,m_bDrawBottomLine(true)
,m_bTouchEnabled(false)
,m_nTouchPriority(0)
{
	ccColor4F c = {255, 255, 255, 255};
	m_lineColor = c;
}

StyleLabel::~StyleLabel(void)
{
}
void StyleLabel::setLineColor(ccColor4F lineColor)
{
	m_lineColor = lineColor;
}
void StyleLabel::setLineWidth(float lineWidth)
{
	m_fLineWidth = lineWidth;
}
void StyleLabel::setDrawBottomLine(bool enable)
{
	m_bDrawBottomLine = enable;
}
StyleLabel* StyleLabel::create(void)
{
	StyleLabel * pRet = new StyleLabel();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}
StyleLabel* StyleLabel::create(const char* str, const char* fontName, float fontSize)
{
	StyleLabel * pRet = new StyleLabel();
	if (pRet && pRet->initWithString(str, fontName, fontSize))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}
void StyleLabel::draw()
{
	CCLabelTTF::draw();
	if (m_bDrawBottomLine)
	{
		glLineWidth(m_fLineWidth);
		ccDrawColor4B(m_lineColor.r, m_lineColor.g, m_lineColor.b, m_lineColor.a);
		ccDrawLine( ccp(0, 0), ccp(getContentSize().width, 0));
	}
}
void StyleLabel::onEnter()
{
	CCLabelTTF::onEnter();
	setTouchEnabled(m_bTouchEnabled);
}
void StyleLabel::onExit()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->removeDelegate(this);
	CCLabelTTF::onExit();
}
void StyleLabel::registerScriptClickHandler(LUA_FUNCTION nHandler)
{
	unregisterScriptClickHandler();
	m_nScriptClickHandler = nHandler;
}
void StyleLabel::unregisterScriptClickHandler(void)
{
	if (m_nScriptClickHandler)
	{
		CCScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(m_nScriptClickHandler);
		m_nScriptClickHandler = 0;
	}
}
void StyleLabel::registerWithTouchDispatcher()
{
	CCTouchDispatcher* pDispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
	pDispatcher->addTargetedDelegate(this, m_nTouchPriority, true);
}
void StyleLabel::setTouchPriority(int priority)
{
	if (m_nTouchPriority != priority)
	{
		m_nTouchPriority = priority;

		if( m_bTouchEnabled)
		{
			setTouchEnabled(false);
			setTouchEnabled(true);
		}
	}
}
int StyleLabel::getTouchPriority()
{
	return m_nTouchPriority;
}
void StyleLabel::setPerformClickEnable(bool enable)
{
	m_bTouchEnabled = enable;
}
bool StyleLabel::isTouchEnabled()
{
	return m_bTouchEnabled;
}
void StyleLabel::setTouchEnabled(bool enabled)
{
		m_bTouchEnabled =enabled;
		if (m_bRunning)
		{
			if (enabled)
			{
				this->registerWithTouchDispatcher();
			}
			else
			{
				CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
			}
		}
}
bool StyleLabel::contaisTouchLocation(CCTouch* touch)
{
	CCPoint point = m_pParent->convertTouchToNodeSpace(touch);
	CCRect bBox = this->boundingBox();
	return bBox.containsPoint(point);

}
bool StyleLabel::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	return contaisTouchLocation(touch);
}
void StyleLabel::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

}
void StyleLabel::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	if (contaisTouchLocation(touch))
	{
		
		if (m_eScriptType == kScriptTypeLua)
		{
			int nHandler = this->getScriptClickHandler();
			if (nHandler)
			{
				CCLuaStack* m_stack =  CCLuaEngine::defaultEngine()->getLuaStack();
				m_stack->pushCCObject(this, "StyleLabel");
				int ret = m_stack->executeFunctionByHandler(nHandler, 1);
				m_stack->clean();
			}
		}
		//CCLOG("Click");
	}
}
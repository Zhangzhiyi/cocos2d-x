#include "CCStyleLabel.h"
#include "CCLuaEngine.h"

CCStyleLabel::CCStyleLabel(void)
:m_fLineWidth(0.25f)
,m_bDrawBottomLine(true)
,m_bTouchEnabled(false)
,m_nTouchPriority(0)
{
	ccColor4F c = {255, 255, 255, 255};
	m_lineColor = c;
}

CCStyleLabel::~CCStyleLabel(void)
{
}
void CCStyleLabel::setLineColor(ccColor4F lineColor)
{
	m_lineColor = lineColor;
}
void CCStyleLabel::setLineWidth(float lineWidth)
{
	m_fLineWidth = lineWidth;
}
void CCStyleLabel::setDrawBottomLine(bool enable)
{
	m_bDrawBottomLine = enable;
}
CCStyleLabel* CCStyleLabel::create(void)
{
	CCStyleLabel * pRet = new CCStyleLabel();
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
CCStyleLabel* CCStyleLabel::create(const char* str, const char* fontName, float fontSize)
{
	CCStyleLabel * pRet = new CCStyleLabel();
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
void CCStyleLabel::draw()
{
	CCLabelTTF::draw();
	if (m_bDrawBottomLine)
	{
		glLineWidth(m_fLineWidth);
		ccDrawColor4B(m_lineColor.r, m_lineColor.g, m_lineColor.b, m_lineColor.a);
		ccDrawLine( ccp(0, 0), ccp(getContentSize().width, 0));
	}
}
void CCStyleLabel::onEnter()
{
	CCLabelTTF::onEnter();
	setTouchEnabled(m_bTouchEnabled);
}
void CCStyleLabel::onExit()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->removeDelegate(this);
	CCLabelTTF::onExit();
}
void CCStyleLabel::registerScriptClickHandler(int nHandler)
{
	unregisterScriptClickHandler();
	m_nScriptClickHandler = nHandler;
}
void CCStyleLabel::unregisterScriptClickHandler(void)
{
	if (m_nScriptClickHandler)
	{
		CCScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(m_nScriptClickHandler);
		m_nScriptClickHandler = 0;
	}
}
void CCStyleLabel::registerWithTouchDispatcher()
{
	CCTouchDispatcher* pDispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
	pDispatcher->addTargetedDelegate(this, m_nTouchPriority, true);
}
void CCStyleLabel::setTouchPriority(int priority)
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
int CCStyleLabel::getTouchPriority()
{
	return m_nTouchPriority;
}
void CCStyleLabel::setPerformClickEnable(bool enable)
{
	m_bTouchEnabled = enable;
}
bool CCStyleLabel::isTouchEnabled()
{
	return m_bTouchEnabled;
}
void CCStyleLabel::setTouchEnabled(bool enabled)
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
bool CCStyleLabel::contaisTouchLocation(CCTouch* touch)
{
	CCPoint point = m_pParent->convertTouchToNodeSpace(touch);
	CCRect bBox = this->boundingBox();
	return bBox.containsPoint(point);

}
bool CCStyleLabel::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	return contaisTouchLocation(touch);
}
void CCStyleLabel::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

}
void CCStyleLabel::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	if (contaisTouchLocation(touch))
	{
		
		if (m_eScriptType == kScriptTypeLua)
		{
			int nHandler = this->getScriptClickHandler();
			if (nHandler)
			{
				CCLuaStack* m_stack =  CCLuaEngine::defaultEngine()->getLuaStack();
				m_stack->pushCCObject(this, "CCStyleLabel");
				int ret = m_stack->executeFunctionByHandler(nHandler, 1);
				m_stack->clean();
			}
		}
		//CCLOG("Click");
	}
}
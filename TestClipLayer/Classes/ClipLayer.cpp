#include "ClipLayer.h"


ClipLayer::ClipLayer(void):
m_bClipingAble(false)
//,m_ViewSize(CCDirector::sharedDirector()->getWinSize())
{
		
}
ClipLayer::~ClipLayer(void)
{
}
bool ClipLayer::init()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	return initWithViewSize(winSize);
}
bool ClipLayer::initWithViewSize(const CCSize& viewSize)
{
	if (CCLayer::init())
	{
		m_ViewSize = viewSize;
		return true;
	}
	return false;
}
ClipLayer* ClipLayer::create(const CCSize& viewSize)
{
	ClipLayer* pLayer = new ClipLayer();
	if (pLayer && pLayer->initWithViewSize(viewSize))
	{
		pLayer->autorelease();
		return pLayer;
	}
	CC_SAFE_DELETE(pLayer);
	return NULL;
}
void ClipLayer::onEnter()
{
	CCLayer::onEnter();
	setTouchEnabled(true);

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSprite* background = CCSprite::create("background.png");
	background->setPosition(ccp(size.width/2, size.height/2));
	this->addChild(background);
}
void ClipLayer::setClipingAble(bool clipingAble)
{
	m_bClipingAble = clipingAble;
}
void ClipLayer::setClipingRect(const CCRect& clipingRect)
{
	m_ClipingRect = clipingRect;
}
void ClipLayer::visit()
{
	if (!isVisible())
	{
		return;
	}
	if (this->m_bClipingAble)
	{
		kmGLPushMatrix();
		glEnable(GL_SCISSOR_TEST); // 开启显示指定区域
		float x = this->getPositionX();
		float y = this->getPositionY();
		//CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCPoint screenPos = this->convertToWorldSpace(CCPointZero);//获取ClipLayer在世界坐标系的起始位置
		//注意剪切的位置是相对于世界坐标系的, 不是相对于ClipLayer本身坐标系，所以当改变ClipLayer的position的时候为了不改变剪切的内容就要获取ClipLayer在世界坐标系的起始位置
		CCEGLView::sharedOpenGLView()->setScissorInPoints(screenPos.x, screenPos.y,  m_ViewSize.width, m_ViewSize.height);
		//glScissor(size.width/2, size.height/2,  size.width/2, size.height/2); // 只显示当前窗口的区域
		CCLayer::visit(); // 调用父类的visit()方法
		glDisable(GL_SCISSOR_TEST); // 禁用
		kmGLPopMatrix();
	}
	else
	{
		CCLayer::visit();
	}
	
}
void ClipLayer::setViewSize(const CCSize& viewSize)
{
	m_ViewSize = viewSize;
	//如果不设置ContentSize就算剪切了还是返回CCLayer整个屏幕宽高大小，而锚点是基于ContentSize的；设置一下ContentSize，锚点是基于剪切剩下的部分空间的，这样方便改变位置
	this->setContentSize(viewSize);
}
//获取ClipLayer在世界坐标系的起始位置和大小, 此方法参考CCScrollView源码
CCRect ClipLayer::getViewRect()
{
	CCPoint screenPos = this->convertToWorldSpace(CCPointZero);
	return CCRectMake(screenPos.x, screenPos.y, m_ViewSize.width, m_ViewSize.height);
}
void ClipLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}
bool ClipLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point = pTouch->getLocation();
	//CCLOG("ccTouchBegan x:%d, y:%d", (int)point.x, (int)point.y);
	// 因为剪切的部分是基于世界坐标系的，而boundingBox()返回的CCRect是基于父节点坐标系的，所以不能用这种方法
	//CCRect bBox = boundingBox();//如果不设置ContentSize就算剪切了还是返回CCLayer整个屏幕宽高大小
	CCRect bBox = getViewRect();
	if (!bBox.containsPoint(this->convertToWorldSpace(this->convertToNodeSpace(point))))
	{
		return false;
	}
	CCPoint localAxis = this->convertToNodeSpace(point);
	CCLOG("localAxis ccTouchBegan x:%d, y:%d",  (int)localAxis.x, (int)localAxis.y);
	return true;
}
void ClipLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point = pTouch->getLocation();
	//CCLOG("ccTouchMoved x:%d, y:%d", (int)point.x, (int)point.y);

	CCPoint localAxis = this->convertToNodeSpace(point);
	CCLOG("localAxis ccTouchMoved x:%d, y:%d",  (int)localAxis.x, (int)localAxis.y);

}
void ClipLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}
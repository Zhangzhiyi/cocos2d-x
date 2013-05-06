#include "ClipLayer.h"


ClipLayer::ClipLayer(void):
m_bClipingAble(false)
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
		m_bClipingAble = false;
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
	m_bClipingAble = true;
	this->setContentSize(viewSize);
}
//获取ClipLayer在世界坐标系的起始位置和大小, 此方法参考CCScrollView源码
CCRect ClipLayer::getViewRect()
{
	CCPoint screenPos = this->convertToWorldSpace(CCPointZero);
	return CCRectMake(screenPos.x, screenPos.y, m_ViewSize.width, m_ViewSize.height);
}
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
		glEnable(GL_SCISSOR_TEST); // ������ʾָ������
		float x = this->getPositionX();
		float y = this->getPositionY();
		//CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCPoint screenPos = this->convertToWorldSpace(CCPointZero);//��ȡClipLayer����������ϵ����ʼλ��
		//ע����е�λ�����������������ϵ��, ���������ClipLayer��������ϵ�����Ե��ı�ClipLayer��position��ʱ��Ϊ�˲��ı���е����ݾ�Ҫ��ȡClipLayer����������ϵ����ʼλ��
		CCEGLView::sharedOpenGLView()->setScissorInPoints(screenPos.x, screenPos.y,  m_ViewSize.width, m_ViewSize.height);
		//glScissor(size.width/2, size.height/2,  size.width/2, size.height/2); // ֻ��ʾ��ǰ���ڵ�����
		CCLayer::visit(); // ���ø����visit()����
		glDisable(GL_SCISSOR_TEST); // ����
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
//��ȡClipLayer����������ϵ����ʼλ�úʹ�С, �˷����ο�CCScrollViewԴ��
CCRect ClipLayer::getViewRect()
{
	CCPoint screenPos = this->convertToWorldSpace(CCPointZero);
	return CCRectMake(screenPos.x, screenPos.y, m_ViewSize.width, m_ViewSize.height);
}
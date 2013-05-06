#include "TouchLayer.h"


TouchLayer::TouchLayer(const char* title, const ccColor4B& color)
{
	m_strTitle = title;
	CCLayerColor::initWithColor(color);
}


TouchLayer::~TouchLayer(void)
{
}
void TouchLayer::onEnter()
{
	CCLayerColor::onEnter();
	setTouchEnabled(true);
}
void TouchLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}
bool TouchLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point = pTouch->getLocation();
	CCRect bBox = boundingBox();//返回的相对于父节点的CCRect
	CCPoint parentAxis = this->m_pParent->convertToNodeSpace(point);//所以这个点要用父节点的坐标系	
	if (!bBox.containsPoint(parentAxis))
	{
		return false;
	}
	CCPoint localAxis = this->convertToNodeSpace(point);
	CCLOG("%s ccTouchBegan x:%d, y:%d", m_strTitle.c_str(), (int)point.x, (int)point.y);
	CCLOG("%s localAxis ccTouchBegan x:%d, y:%d", m_strTitle.c_str(), (int)localAxis.x, (int)localAxis.y);
	CCLOG("%s parentAxis ccTouchBegan x:%d, y:%d", m_strTitle.c_str(), (int)parentAxis.x, (int)parentAxis.y);
	return true;
}
void TouchLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point = pTouch->getLocation();
	CCLOG("%s ccTouchMoved x:%d, y:%d", m_strTitle.c_str(), (int)point.x, (int)point.y);
	CCPoint localAxis = this->convertToNodeSpace(point);
	CCPoint parentAxis = convertToNodeSpace(point);
	CCLOG("%s localAxis ccTouchMoved x:%d, y:%d", m_strTitle.c_str(), (int)localAxis.x, (int)localAxis.y);
	CCLOG("%s parentAxis ccTouchMoved x:%d, y:%d", m_strTitle.c_str(), (int)parentAxis.x, (int)parentAxis.y);
}
void TouchLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}
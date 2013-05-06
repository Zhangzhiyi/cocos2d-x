#ifndef __TOUCH_LAYER_H__
#define __TOUCH_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

class TouchLayer : public CCLayerColor
{
public:
	TouchLayer(const char* title, const ccColor4B& color);
	~TouchLayer(void);
	virtual void onEnter();

	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	std::string m_strTitle;
};

#endif
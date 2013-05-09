#ifndef __CC_STYLE_LABEL_H__
#define __CC_STYLE_LABEL_H__
#include "cocos2d.h"

USING_NS_CC;

class CCStyleLabel : public CCLabelTTF, public CCTargetedTouchDelegate
{
public:
	CREATE_FUNC(CCStyleLabel);
	CCStyleLabel(void);
	virtual ~CCStyleLabel(void);
	virtual void onEnter();
	virtual void onExit();
	virtual void draw();	
	static CCStyleLabel* create(const char* string, const char* fontName, float fontSize);
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

	void setIsTouch(bool enable);
	virtual bool isTouchEnabled();
	virtual void setTouchEnabled(bool value);
	virtual void setTouchPriority(int priority);
	virtual int getTouchPriority();

	void registerWithTouchDispatcher(void);

	bool contaisTouchLocation(CCTouch* touch);
protected:
	//float m_fLineWidth;
	//ccColor4F m_lineColor;
	bool m_bTouchEnabled;
	CC_SYNTHESIZE(bool, m_bDrawBottomLine, DrawBottomLine);
	CC_SYNTHESIZE(float, m_fLineWidth, LineWidth);
	CC_SYNTHESIZE(ccColor4F, m_lineColor, LineColor);
private:
	int m_nTouchPriority;
	//int  excuteScriptTouchHandler(int nEventType, CCTouch *pTouch);
};
#endif

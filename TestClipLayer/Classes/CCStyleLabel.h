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

	void setDrawBottomLine(bool enable);
	bool isDrawBottomLine(){return m_bDrawBottomLine;}
	void setLineWidth(float lineWidth);
	float getLineWidth(){return m_fLineWidth;}
	void setLineColor(ccColor4F lineColor);
	ccColor4F getLineColor(){return m_lineColor;}

	/** Register menu handler script function */
	//virtual void registerScriptClickHandler(int nHandler);
	//virtual void unregisterScriptClickHandler(void);
	//int getScriptClickHandler() { return m_nScriptClickHandler; };
private:
	int m_nTouchPriority;
	bool m_bTouchEnabled;
	bool m_bDrawBottomLine;
	float m_fLineWidth;
	ccColor4F m_lineColor;

	int  m_nScriptClickHandler;
	//int  excuteScriptTouchHandler(int nEventType, CCTouch *pTouch);
};
#endif

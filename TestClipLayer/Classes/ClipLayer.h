#ifndef __CLIP_LAYER_H__
#define __CLIP_LAYER_H__
#include "cocos2d.h"
USING_NS_CC;
class ClipLayer : public CCLayer
{
public:
	ClipLayer(void);
	~ClipLayer(void);

	virtual void onEnter();

	virtual void visit();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	//static ClipLayer* create();
	CREATE_FUNC(ClipLayer);
	static ClipLayer* create(const CCSize& viewSize);
	virtual bool init();
	virtual bool initWithViewSize(const CCSize& viewSize);

	CCSize getViewSize(){return m_ViewSize;};
	void setViewSize(const CCSize& viewSize);
	CCRect getViewRect();

	CCRect getClipingRect(){return m_ClipingRect;};
	void setClipingRect(const CCRect& clipingRect);
	bool getClipingAble(){return m_bClipingAble;};
	void setClipingAble(bool clipingAble);
private:
	CCSize m_ViewSize;
	CCRect m_ClipingRect;
	bool m_bClipingAble;
};

#endif

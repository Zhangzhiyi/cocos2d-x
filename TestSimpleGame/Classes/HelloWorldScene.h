#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
class HelloWorld : public cocos2d::CCLayer
{
public:
	HelloWorld(void);
	~HelloWorld(void);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    virtual void onEnter();
	virtual void onExit();
	virtual void update(float delta);
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	void addEnemySprite(float dt);

	void enemyMoveCompletion(CCNode* pTagget);
	CCSprite* player;
	CCArray* enemies;
	CCArray* bullets;
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
protected:
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	
};

#endif  // __HELLOWORLD_SCENE_H__
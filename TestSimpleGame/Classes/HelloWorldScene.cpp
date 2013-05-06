#include "HelloWorldScene.h"
#include "VisibleRect.h"
#include "ccMacros.h"
#include "support/CCPointExtension.h"
#include <stdlib.h>
#include <time.h>
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
enum{
	KTagEnemy = 1,
	KTagBullet,
};

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}
HelloWorld::HelloWorld(void)
{
	enemies = CCArray::create(); 
	//Object created by 'create' method is an autorelease object, if you want to keep the object, you should invoke array->retain() after 'create'.And don't forget to 'release' it when you don't want to use it.
	enemies->retain();
	bullets = CCArray::create();
	bullets->retain();

	CCArray* test = CCArray::create();
	test->addObject(CCInteger::create(1));
	test->addObject(CCInteger::create(2));
	test->addObject(CCInteger::create(3));
	test->addObject(CCInteger::create(4));
	//CCObject* pObject = NULL;
	//CCARRAY_FOREACH(test, pObject)
	//{
	//	CCInteger* integer = (CCInteger*)pObject;
	//	
	//	if (integer->getValue() == 2)
	//	{
	//		test->removeObject(pObject); //1 4 4
	//	}
	//	else
	//	{
	//		CCLOG("%d", integer->getValue());
	//	}
	//	
	//}
	for (int i = 0; i < test->count(); i++)
	{
		CCInteger* integer = (CCInteger*)test->objectAtIndex(i);
		if (integer->getValue() == 2)
		{
			test->removeObject(integer); //1 3 4 这个输出正确值
			i -- ;
		}
		else
		{
			CCLOG("%d", integer->getValue());
		}
	}
	CCInteger* integer1 = CCInteger::create(1);
	CCInteger* integer2 = CCInteger::create(2);
	CCInteger* integer3 = CCInteger::create(3);

	CCArray* test1 = CCArray::create();
	test1->addObject(integer1);
	test1->addObject(integer2);
	test1->addObject(integer3);
	CCArray* test2 = CCArray::create();
	test2->addObject(integer1);
	test2->addObject(integer2);
	test2->addObject(integer3);

	test1->removeObject(integer1);
	CCInteger* integer4 = CCInteger::create(3);
}
HelloWorld::~HelloWorld(void)
{
	enemies->release();
	bullets->release();
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));

        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        CCSprite* pSprite = CCSprite::create("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);

		player = CCSprite::create("Player2.png");
		player->setPosition(ccp(VisibleRect::left().x + player->getContentSize().width/2, VisibleRect::left().y));
		this->addChild(player);
		
        bRet = true;
    } while (0);

    return bRet;
}
void HelloWorld::addEnemySprite(float dt)
{
	unschedule(schedule_selector(HelloWorld::addEnemySprite));
	CCSprite* target = CCSprite::create("Target.png");
	int minY = target->getContentSize().height/2;
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	int maxY = winSize.height - target->getContentSize().height/2;
	
	srand ((unsigned)time(NULL));
	//CCLOG("random:%f", CCRANDOM_0_1());
	int actualY = CCRANDOM_0_1()*(maxY - minY + 1) + minY;
	target->setPosition(ccp(winSize.width + target->getContentSize().width/2, actualY));
	this->addChild(target);
	target->setTag(KTagEnemy);
	enemies->addObject(target);

	int minDuration = 4.0;
	int maxDuration = 8.0;
	//srand ((unsigned)time(NULL));
	int actualDuration = CCRANDOM_0_1()*(maxDuration - minDuration + 1) + minDuration;

	//CCLOG("actualY:%d,actualDuration:%d", actualY, actualDuration);
	CCMoveTo* moveTo = CCMoveTo::create(actualDuration, ccp(-target->getContentSize().width/2, actualY));
	CCSequence* sequence = CCSequence::create(moveTo, 
		CCCallFuncN::create(this, callfuncN_selector(HelloWorld::enemyMoveCompletion)), NULL);
	target->runAction(sequence);
	
	int minTime = 1;
	int maxTime = 2;
	int time = (CCRANDOM_0_1() * (maxTime- minTime + 1))+ minTime;
	//CCLOG("time:%d", time);
	schedule(schedule_selector(HelloWorld::addEnemySprite), time);
}
void HelloWorld::enemyMoveCompletion(CCNode* pTarget)
{
	if (pTarget->getTag() == KTagEnemy)
	{
		enemies->removeObject(pTarget);
	}
	else if (pTarget->getTag() == KTagBullet)
	{
		bullets->removeObject(pTarget);
	}
	CCSprite* sprite = (CCSprite*)pTarget;
	this->removeChild(sprite, true);
}
void HelloWorld::onEnter()
{
	CCLayer::onEnter();
	this->setTouchMode(kCCTouchesOneByOne);//没有这句默认是注册CCStandardTouchDelegate事件了，可以跳入源码看
	this->setTouchEnabled(true);
	scheduleUpdate();
	schedule(schedule_selector(HelloWorld::addEnemySprite), 3.0f);
}
void HelloWorld::onExit()
{
	unscheduleUpdate();
	unschedule(schedule_selector(HelloWorld::addEnemySprite));
	CCLayer::onExit();
}
void HelloWorld::update(float delta)
{
	CCArray* deleteBullets = CCArray::create();
	CCArray* deleteEnemies = CCArray::create();
	CCObject* pBullet = NULL;
	CCARRAY_FOREACH(bullets, pBullet)
	{
		CCSprite* bullet = (CCSprite*)pBullet;
		if (bullet)
		{
			CCRect bulletBound = CCRectMake(bullet->getPositionX() - bullet->getContentSize().width/2,
											bullet->getPositionY() - bullet->getContentSize().height/2,
											bullet->getContentSize().width,
											bullet->getContentSize().height);
			CCObject* pEnemy = NULL;
			CCARRAY_FOREACH(enemies, pEnemy)
			{
				CCSprite* enemy = (CCSprite*)pEnemy;
				if (enemy)
				{
					CCRect enemyBound = CCRectMake(enemy->getPositionX() - enemy->getContentSize().width/2,
												   enemy->getPositionY() - enemy->getContentSize().height/2,
												   enemy->getContentSize().width,
												   enemy->getContentSize().height);

					if (bulletBound.intersectsRect(enemyBound))
					{
						//deleteEnemies->addObject(enemy);
						deleteBullets->addObject(bullet);
						this->removeChild(enemy, true);
						enemies->removeObject(pEnemy);
						break;
					}
				}
			}
		}
	}
	CCObject* delBullet = NULL;
	CCARRAY_FOREACH(deleteBullets, delBullet)
	{
		CCSprite* bullet = (CCSprite*)delBullet;
		this->removeChild(bullet, true);
		bullets->removeObject(delBullet);
	}
}
bool HelloWorld::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCPoint point = touch->getLocation();
	CCLOG("ccTouchBegan x:%d, y:%d", (int)point.x, (int)point.y);
	
	return true;
}
void HelloWorld::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

}
void HelloWorld::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCPoint point = touch->getLocation();
	CCLOG("ccTouchEnded x:%d, y:%d", (int)point.x, (int)point.y);

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite* bullet = CCSprite::create("Projectile2.png");
	bullet->setPosition(player->getPosition());
	this->addChild(bullet);
	bullet->setTag(KTagBullet);
	bullets->addObject(bullet);
	

	int offX = point.x - bullet->getPositionX();
	int offY = point.y - bullet->getPositionY();

	if (!offX) return;
	 
	int realX = winSize.width + bullet->getContentSize().width/2;
	double ratio = (double)offY/offX;
	int realY = ratio * realX + bullet->getPositionY();

	int length = ccpLength(ccp(realX, realY));
	float velocity =480/1; // 4807pixels/1sec
	float realMoveDuration = length/velocity;

	bullet->runAction(CCSequence::create(CCMoveTo::create(realMoveDuration, ccp(realX, realY)), CCCallFuncN::create(this, callfuncN_selector(HelloWorld::enemyMoveCompletion)), NULL));

	SimpleAudioEngine::sharedEngine()->playEffect("pew-pew-lei.caf");
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}


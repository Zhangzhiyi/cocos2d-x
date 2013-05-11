#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "actions/CCActionInterval.h"
#include "Obj/Obj_Unit.h"
#include "Scene/MapScene.h"
#include "Scene/MapBackground.h"
#include "Obj/Obj_Animal.h"
#include "Obj/Effect/UnitEffect.h"
USING_NS_CC;


CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    
    HelloWorld *layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

void HelloWorld::mySchedule(float time)
{
}

void HelloWorld::mySchedule2(float time)
{
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    pCloseItem->setAnchorPoint(ccp(0,0));
	pCloseItem->setPosition(origin.x,origin.y);
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

	CCSprite* pSprite = CCSprite::create();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	pSprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));

    this->addChild(pSprite, 0,333);

	//²âÊÔ
	//add background
	MapScene::sharedMapScene()->setMapSize(4492,2885);
	this->addChild(MapScene::sharedMapScene(),-1,444);
	Obj_Animal* pAnimal = Obj_Animal::create();
	pAnimal->setPosition(512,384);
	pAnimal->initPart(410101,PART_BODY);
	MapScene::sharedMapScene()->addUnit(pAnimal);
	MapScene::sharedMapScene()->setHero(pAnimal);

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			Obj_Animal* pMonster = Obj_Animal::create();
			pMonster->setPosition(j*300,i*300);
			pMonster->initPart(410120,PART_BODY);
			MapScene::sharedMapScene()->addUnit(pMonster);
		}
	}

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			Obj_Animal* pMonster = Obj_Animal::create();
			pMonster->initPart(410101,PART_BODY);
			pMonster->setPosition(j*100,i*100);
			CCPoint* pPoint = new CCPoint(MapBackground::sharedMapBackground()->getMapWidth() *(float)rand() / RAND_MAX ,MapBackground::sharedMapBackground()->getMapHeight() * (float)rand() / RAND_MAX);
			pPoint->autorelease();
			pMonster->setPath(pPoint,(MoveEndCallBackFunc)(&HelloWorld::moveOverCallback),this);
			MapScene::sharedMapScene()->addUnit(pMonster);
		}
	}

	Obj_Animal* pMonster = Obj_Animal::create();
	pMonster->setPosition(1024,768);
	MapScene::sharedMapScene()->addUnit(pMonster);

	UnitEffect* pUnitEffect = UnitEffect::create();
	pUnitEffect->setPosition(1000,500);
	pUnitEffect->init("chuansongmen");
	MapScene::sharedMapScene()->addUnit(pUnitEffect);

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("honghuangtianlongyin.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("jingganglianhuanzhan.plist");

	CCArray* pPath = CCArray::create();
	CCPoint* pPoint = new CCPoint(1000,1000);
	pPoint->autorelease();
	pPath->addObject(pPoint);
	pAnimal->setPath(pPath);
	

	this->schedule(schedule_selector(HelloWorld::mySchedule),30,kCCRepeatForever,20);
	this->schedule(schedule_selector(HelloWorld::mySchedule2));
	this->scheduleUpdate();
    return true;
}

void HelloWorld::moveOverCallback(CCObject* pTarget)
{
	CCPoint pPoint((float)MapBackground::sharedMapBackground()->getMapWidth() *rand() / RAND_MAX ,(float)MapBackground::sharedMapBackground()->getMapHeight() * rand() / RAND_MAX);
	Obj_Animal* pAnimal = dynamic_cast<Obj_Animal*>(pTarget);
	if(pAnimal != NULL)
	{
		pAnimal->setPath(pPoint,(MoveEndCallBackFunc)(&HelloWorld::moveOverCallback),this);
	}
}

void HelloWorld::moveToCallback()
{
}

void HelloWorld::update(float dt)
{
	static int x = 0;
	static int y = 0;

	x++;
	y++;
	//MapBackground::sharedMapBackground()->center(x,y);
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

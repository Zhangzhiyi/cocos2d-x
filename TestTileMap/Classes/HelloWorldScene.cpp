#include "HelloWorldScene.h"

using namespace cocos2d;

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
void HelloWorld::onEnter()
{
	CCLayer::onEnter();
	setTouchEnabled(true);
}
void HelloWorld::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
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
        //this->addChild(pMenu, 1);

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

		pTileMap = CCTMXTiledMap::create("tilemap.tmx");
		pTileMap->setPosition(CCPointZero);
		this->addChild(pTileMap, 1);
		CCTMXObjectGroup* objects = pTileMap->objectGroupNamed("Objects");
		CCDictionary* spawnPoint = objects->objectNamed("SpawnPoint");
		int x = spawnPoint->valueForKey("x")->intValue();
		int y = spawnPoint->valueForKey("y")->intValue();

		player = CCSprite::create("player.png");
		player->setPosition(ccp(x, y));
		pTileMap->addChild(player);
		setViewPointCenter(ccp(x, y));
        bRet = true;
    } while (0);

    return bRet;
}
void HelloWorld::setViewPointCenter(const CCPoint& point)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	int x = max(point.x, winSize.width/2);
	int y = max(point.y, winSize.height/2);
	x = min(x, (pTileMap->getMapSize().width * pTileMap->getTileSize().width) - winSize.width/2);
	y = min(y, (pTileMap->getMapSize().height * pTileMap->getTileSize().height) - winSize.height/2);
	CCPoint actualPoint = ccp(x, y);
	CCPoint centerPoint = ccp(winSize.width/2, winSize.height/2);
	CCPoint viewPoint = ccpSub(centerPoint, actualPoint);

	pTileMap->setPosition(viewPoint);
}
bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}
void HelloWorld::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point = pTouch->getLocation();
	//CCLOG("ccTouchMoved x:%d, y:%d", (int)point.x, (int)point.y);

}
void HelloWorld::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
		CCPoint point = pTileMap->convertTouchToNodeSpace(pTouch);
		CCLOG("ccTouchMoved x:%d, y:%d", (int)point.x, (int)point.y);
		CCPoint playerPoint = player->getPosition();
		CCPoint diff = ccpSub(point, playerPoint);
		if (abs(diff.x) > abs(diff.y))
		{
			if (diff.x > 0)
			{
				playerPoint.x += pTileMap->getTileSize().width;
			}
			else
			{
				playerPoint.x -= pTileMap->getTileSize().width;
			}
		}
		else
		{
			if (diff.y > 0)
			{
				playerPoint.y +=pTileMap->getTileSize().height;
			}
			else
			{
				playerPoint.y -= pTileMap->getTileSize().height;
			}	
		}
		if (playerPoint.x >= 0 && playerPoint.y >= 0 
			&& playerPoint.x <= (pTileMap->getMapSize().width * pTileMap->getTileSize().width)
			&& playerPoint.y <= (pTileMap->getMapSize().height * pTileMap->getTileSize().height))
		{
			player->setPosition(playerPoint);
		}
		setViewPointCenter(player->getPosition());
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}


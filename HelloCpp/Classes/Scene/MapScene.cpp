#include "MapScene.h"
#include "MapBackground.h"
#include "Obj/Effect/UnitEffect.h"
#include "Obj/Animal_One.h"

USING_NS_CC;

static MapScene* m_gMapScene = 0;

MapScene::MapScene()
{
	m_mapWidth = m_mapHeight = 0;
	m_allLayer = m_lowEffectLayer = m_units = m_highEffectLayer = 0;
	m_allArray = m_dropThingArray = m_collectArray =  m_monsterArray = m_petArray = m_roleArray = m_npcArray = 0;
	m_hero = 0;
}
MapScene::~MapScene()
{
	CC_SAFE_RELEASE(m_allLayer);
	CC_SAFE_RELEASE(m_lowEffectLayer);
	CC_SAFE_RELEASE(m_units);
	CC_SAFE_RELEASE(m_highEffectLayer);
	CC_SAFE_RELEASE(m_hero);
}

MapScene* MapScene::sharedMapScene()
{
	if(m_gMapScene == 0)
	{
		m_gMapScene = new MapScene();
		m_gMapScene->init();
	}
	return m_gMapScene;
}

bool MapScene::init()
{

	this->addChild(MapBackground::sharedMapBackground());
	m_allLayer = CCNode::create();
	m_allLayer->retain();
	this->addChild(m_allLayer);
	m_allLayer->setScaleY(-1.0f);
	m_allLayer->setPositionY(CCDirector::sharedDirector()->getWinSize().height);

	m_lowEffectLayer = MapNode::create();
	m_lowEffectLayer->retain();
	m_allLayer->addChild(m_lowEffectLayer);

	m_units = MapNode::create();
	m_units->retain();
	m_allLayer->addChild(m_units);

	m_highEffectLayer = MapNode::create();
	m_highEffectLayer->retain();
	m_allLayer->addChild(m_highEffectLayer);

	//所有的unit管理器
	m_allArray = CCArray::create();
	m_allArray->retain();
	m_monsterArray = CCArray::create();
	m_monsterArray->retain();
	m_roleArray = CCArray::create();
	m_roleArray->retain();
	m_petArray = CCArray::create();
	m_petArray->retain();
	m_npcArray = CCArray::create();
	m_npcArray->retain();
	m_collectArray = CCArray::create();
	m_collectArray->retain();
	m_dropThingArray = CCArray::create();
	m_dropThingArray->retain();

	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);

	this->scheduleUpdate();
	return true;
}

void MapScene::center(float x, float y)
{
	CCSize win_size = CCDirector::sharedDirector()->getWinSize();
	
	int resultX = win_size.width / 2 - x;
	int resultY = win_size.height / 2 + y;

	if(resultX > 0) 
		resultX = 0;
	else if(resultX < win_size.width - m_mapWidth)
		resultX = win_size.width - m_mapWidth;

	if(resultY < win_size.height)
		resultY = win_size.height;
	else if(resultY > m_mapHeight)
		resultY = m_mapHeight;

	m_allLayer->setPosition(resultX,resultY);

	MapBackground::sharedMapBackground()->center(x,y);
}

void MapScene::setMapSize(int width, int height)
{
	this->m_mapWidth = width;
	this->m_mapHeight = height;
	MapBackground::sharedMapBackground()->setMapSize(width,height);
}

void MapScene::update(float dt)
{
	if(this->getParent() == NULL || this->isVisible() == false)
		return;

	CCObject* pElement = NULL;
	CCARRAY_FOREACH(m_allArray,pElement)
	{
		pElement->update(dt);
	}
}

UnitEffect* MapScene::addEffect(const char* plist, float px /* = 0.0f */, float py /* = 0.0f */, int count /* = -1 */, float totalTime /* = 1.0f */)
{
	UnitEffect* pEffect = UnitEffect::create();
	pEffect->init(plist,px,py,count,totalTime,callfuncO_selector(MapScene::addEffectCallback),this);
	this->addUnit(pEffect);
	return pEffect;
}

void MapScene::addEffectCallback(cocos2d::CCObject* pTarget)
{
	TextureEffect* pTexture = dynamic_cast<TextureEffect*>(pTarget);
	if(pTexture != NULL)
	{
		UnitEffect* pUnitEffect = dynamic_cast<UnitEffect*>(pTexture->getParent());
		if(pUnitEffect != NULL)
			removeUnit(pUnitEffect);
	}
}



void MapScene::removeUnit(Obj_Unit* pUnit)
{
	m_allArray->removeObject(pUnit);
	CCArray* pArray = getArrayByType(pUnit->getType());
	if(pArray != NULL)
	{
		pArray->removeObject(pUnit);
	}

	m_units->removeChild(pUnit,true);
}

void MapScene::addUnit(Obj_Unit* pUnit)
{
	m_allArray->addObject(pUnit);
	CCArray* pArray = getArrayByType(pUnit->getType());
	if(pArray != NULL)
	{
		pArray->addObject(pUnit);
	}

	m_units->addChild(pUnit);
}

CCArray* MapScene::getArrayByType(OBJ_TYPE type)
{
	switch(type)
	{
	case TYPE_ROLE:
		return m_roleArray;
		break;
	case TYPE_MONSTER:
		return m_monsterArray;
		break;
	case TYPE_PET:
		return m_petArray;
		break;
	case TYPE_WAITER:
		return NULL;
		break;
	case TYPE_DROP_THING:
		return m_dropThingArray;
		break;
	case TYPE_STALL_BOARD:
		return NULL;
		break;
	case TYPE_NPC:
		return m_npcArray;
		break;
	case TYPE_COLLECT:
		return m_collectArray;
		break;
	default:
		return NULL;
	}

	return NULL;
}

void MapScene::moveOverCallback(cocos2d::CCObject* pObject)
{
	Obj_Unit* pUnit = dynamic_cast<Obj_Unit*>(pObject);
	if(pUnit != NULL)
		pUnit->setAction(ACTION_ATTACK);
	CCPoint destPoint = pUnit->getDirPoint(100);
	UnitEffect* pEffect = this->addEffect("honghuangtianlongyin",0,0,1,1);
	pEffect->setPosition(destPoint);
}

bool MapScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CC_UNUSED_PARAM(pEvent);
	CCPoint worldPos = pTouch->getLocation();

	CCPoint allLayerPos = m_allLayer->convertToNodeSpace(worldPos);

	/*if(m_hero->touchCatch(worldPos))
	{
		CCLOG("hello touched....");
	}
	else
		CCLOG("hello not touched....");
	*/

	CCObject* pTemp;

	CCArray* allChildren = m_units->getChildren();

	if(allChildren != NULL && allChildren->count() > 0)
	{
		CCARRAY_FOREACH_REVERSE(allChildren,pTemp)
		{	
			Obj_Animal* pAnimal = dynamic_cast<Obj_Animal*>(pTemp);
			if(pAnimal != m_hero && pAnimal != NULL && pAnimal->touchCatch(worldPos) == true)
			{	
				m_hero->doAttack(pAnimal);
				return true;
			}
		}
	}
	

	if(m_hero != NULL)
	{
		CCPoint pPoint(allLayerPos);
		m_hero->setTargetAnimal(NULL);
		m_hero->setPath(&pPoint,(MoveEndCallBackFunc)(&MapScene::moveOverCallback),this);
	}

	return false;
}

void MapScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}

void MapScene::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}



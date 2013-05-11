#ifndef MAP_SCENE_H
#define MAP_SCENE_H

#include "cocos2d.h"
#include "MapNode.h"
#include "Obj/Obj_Unit.h"
#include "Obj/Obj_Animal.h"
USING_NS_CC;
class UnitEffect;
class MapScene: public cocos2d::CCLayer
{
public:
	MapScene();
	~MapScene();

public:
	static MapScene* sharedMapScene();

	virtual bool init();

	void center(float x, float y);

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void setMapSize(int width, int height);

	CC_SYNTHESIZE_RETAIN(Obj_Animal*,m_hero,Hero);

	void moveOverCallback(cocos2d::CCObject* pObject);

	//循环、对象管理、相关
public:
	virtual void update(float dt);
	void addUnit(Obj_Unit* pUnit);
	void removeUnit(Obj_Unit* pUnit);
	virtual UnitEffect* addEffect(const char* plist, float px = 0.0f, float py = 0.0f, 
		int count = -1, float totalTime = 1.0f);

	void addEffectCallback(cocos2d::CCObject* pTarget);
	
	cocos2d::CCArray* getArrayByType(OBJ_TYPE type);
private:
	cocos2d::CCArray* m_allArray;
	cocos2d::CCArray* m_monsterArray;
	cocos2d::CCArray* m_roleArray;
	cocos2d::CCArray* m_petArray;
	cocos2d::CCArray* m_npcArray;
	cocos2d::CCArray* m_collectArray;
	cocos2d::CCArray* m_dropThingArray;
private:
	cocos2d::CCNode* m_allLayer;

	MapNode* m_lowEffectLayer;
	MapNode* m_units;
	MapNode* m_highEffectLayer;

	int m_mapWidth;
	int m_mapHeight;
};


#endif
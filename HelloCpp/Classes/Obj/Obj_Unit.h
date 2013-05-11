#ifndef OBJ_UNIT_H
#define OBJ_UNIT_H
#include "base_nodes/CCNode.h"

#define PI 3.1415926

enum OBJ_ACTION
{
	ACTION_FAULT = -1,
	ACTION_DEFAULT = 0,
	ACTION_STAND = 0,
	ACTION_DEAD,
	ACTION_RUN,
	ACTION_ATTACK,
	ACTION_ATTACK_ARROW,
	ACTION_ATTACK_CAST,
	ACTION_HIT,
	ACTION_SIT,
};

enum OBJ_STATUS
{
	STATUS_NORMAL = 0,
	STATUS_DEAD = 1,
	STATUS_RIDING = 2,
	STATUS_EXCHANGE = 3,
	STATUS_ON_HOOK = 4,
	STATUS_STALL = 5,
	STATUS_TRAINING = 6,
	STATUS_COLLECT = 7,
};

enum OBJ_DIR
{
	DIR_TOP = 0,
	DIR_TOP_RIGHT = 1,
	DIR_RIGHT = 2,
	DIR_BOTTOM_RIGHT = 3,
	DIR_BOTTOM = 4,
	DIR_BOTTOM_LEFT = 5,
	DIR_LEFT = 6,
	DIR_TOP_LEFT=7,
	DIR_NUM = 8,
};

//Obj类型，分为怪物，NPC，人物等
enum OBJ_TYPE
{
	TYPE_UNKNOW = 0,
	TYPE_ROLE = 1,
	TYPE_MONSTER = 2,
	TYPE_PET = 3,
	TYPE_WAITER = 4,
	TYPE_DROP_THING = 5,
	TYPE_STALL_BOARD = 6,
	TYPE_NPC = 8,
	TYPE_COLLECT = 9,
	TYPE_SERVER_NPC = 10,
	TYPE_TRAP = 11,
	TYPE_STATUE = 12,
};

class cocos2d::CCArray;
class cocos2d::CCPoint;
class cocos2d::CCObject;

class Obj_Unit : public cocos2d::CCNode
{
public:
	Obj_Unit();
	virtual ~Obj_Unit();

public:
	//static Obj_Unit* create();
	virtual bool init();
	virtual void update(float dt);

	virtual void initPart(int skinid, int part) = 0;

	virtual bool touchCatch(cocos2d::CCPoint& point);

	virtual void doAttack(Obj_Unit* pUnit) = 0;

	virtual void addEffect(const char* plist, float px = 0.0f, float py = 0.0f, 
		int count = -1, float totalTime = 1.0f,cocos2d::SEL_CallFuncO endFunc = NULL, cocos2d::CCObject* pTarget = NULL, bool front = true);

	void addEffectCallback(cocos2d::CCObject* pTarget);
public:
	virtual void setAction(OBJ_ACTION action = ACTION_STAND);
	OBJ_ACTION getAction(){return m_action;}
	
	cocos2d::CCPoint getDirPoint(float length);
public:
	CC_SYNTHESIZE(float,m_Id,Id);
	CC_SYNTHESIZE(OBJ_DIR,m_dir,Dir);

	CC_SYNTHESIZE(OBJ_TYPE, m_type,Type);

	CC_PROPERTY(OBJ_STATUS,m_status,Status);

	OBJ_ACTION m_action;
	cocos2d::CCArray* m_pEffects;
};

#endif
#ifndef ANIMAL_H
#define ANIMAL_H

#include "cocoa/CCObject.h"
#include "Obj_Unit.h"

enum ANIMAL_TYPE
{
	ANIMAL_TYPE_ONE,
	ANIMAL_TYPE_MULTIPLE,
};

enum ANIMAL_PART
{
	PART_SHADOW = 0,
	PART_EFFECT = 1,
	PART_HORSE = 2,
	PART_WING = 3,
	PART_BODY = 4,
	PART_BIRD = 5,
	PART_HAIR = 6,
	PART_WEAPON = 7,
	PART_WEAPON_EFFECT = 8,
	PARTS_NUM,
};

class Animal : public cocos2d::CCObject
{
public:
	Animal();
	~Animal();

	static Animal* create(Obj_Unit* pParent,ANIMAL_TYPE type);

	void update(float dt,OBJ_ACTION action, OBJ_DIR dir);

	virtual void doUpdate(float time, OBJ_ACTION action, OBJ_DIR dir) = 0;
	
	virtual bool initPart(int skinid, ANIMAL_PART part = PART_BODY) = 0;
	virtual bool init() = 0;
	
	virtual float getDurationByAction(OBJ_ACTION action);

	virtual void reset();

	virtual void setUnitParent(Obj_Unit* pParent)
	{
		m_pParent = pParent;
	}
	Obj_Unit* getUnitParent(){return m_pParent;}
protected:
	Obj_Unit* m_pParent;
protected:
	float m_elapsed;
	float m_duration;
	OBJ_ACTION m_durationAction;
};



#endif

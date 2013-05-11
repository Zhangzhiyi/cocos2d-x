#ifndef ANIMAL_ONE_H
#define ANIMAL_ONE_H

#include "Animal.h"
#include "sprite_nodes/CCSprite.h"
#include "Obj_Unit.h"

class Animal_One: public Animal, public cocos2d::CCSprite
{
public:
	Animal_One();
	~Animal_One();

	static Animal* create(Obj_Unit* pParent);

	virtual bool initPart(int skinid, ANIMAL_PART part = PART_BODY);

	virtual void doUpdate(float time, OBJ_ACTION action, OBJ_DIR dir);
	virtual bool init();

public:


private:
	char* m_skinKey;
};

#endif
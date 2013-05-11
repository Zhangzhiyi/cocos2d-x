#include "Animal.h"
#include "Animal_One.h"
USING_NS_CC;

Animal::Animal():m_elapsed(0),m_duration(0),m_pParent(0),m_durationAction(ACTION_FAULT)
{

}

Animal::~Animal()
{

}

Animal* Animal::create(Obj_Unit* pParent,ANIMAL_TYPE type)
{
	Animal* pResult = 0;
	if(type == ANIMAL_TYPE_ONE)
		pResult = new Animal_One();
	else
		return 0;
	pResult->autorelease();
	pResult->init();
	return pResult;
}

void Animal::update(float dt,OBJ_ACTION action, OBJ_DIR dir)
{
	m_elapsed += dt;
	OBJ_ACTION parentAction = m_pParent->getAction();

	if(m_elapsed >= m_duration)
	{
		if(parentAction == ACTION_STAND || parentAction == ACTION_RUN || parentAction == ACTION_SIT)
		{
			m_elapsed = 0;
		}
		else
			m_pParent->setAction(ACTION_STAND);
	}

	float time = m_elapsed / m_duration;
	doUpdate(time, action , dir);
}

float Animal::getDurationByAction(OBJ_ACTION action)
{
	switch(action)
	{
		case ACTION_STAND:
			return 1.0f;
			break;
		case ACTION_RUN:
			return 0.8f;
			break;
		case ACTION_ATTACK:
		case ACTION_ATTACK_ARROW:
		case ACTION_ATTACK_CAST:
			return 0.8f;
			break;
		case ACTION_SIT:
			return 0.8f;
			break;
		case ACTION_HIT:
			return 0.3f;
			break;
		case ACTION_DEAD:
			return 0.8f;
			break;
	}

	return 0.8f;
}

void Animal::doUpdate(float dt,OBJ_ACTION action, OBJ_DIR dir)
{

}

void Animal::reset()
{
	if(m_durationAction == m_pParent->getAction())
		return;
	m_duration = getDurationByAction(m_pParent->getAction());
	m_durationAction = m_pParent->getAction();
	m_elapsed = 0;
}
#include "Obj_Unit.h"
#include "cocos2d.h"
#include "cocoa/CCArray.h"
#include "Obj/Effect/TextureEffect.h"
#include "cocoa/CCGeometry.h"
#include "Obj_Unit.h"

USING_NS_CC;

Obj_Unit::Obj_Unit():m_Id(0),m_action(ACTION_STAND),m_type(TYPE_UNKNOW),m_dir(DIR_TOP)
{
	m_pEffects = NULL;
}

Obj_Unit::~Obj_Unit()
{
	CC_SAFE_RELEASE_NULL(m_pEffects);
}

/*Obj_Unit* Obj_Unit::create()
{
	Obj_Unit* result = new Obj_Unit();
	if(result == 0 || result->init() == false)
	{
		return 0;
	}
	result->autorelease();

	return result;
}*/

bool Obj_Unit::init()
{
	this->setScaleY(-1.0f);
	return true;
}

void Obj_Unit::setAction(OBJ_ACTION action /* = ACTION_STAND */)
{
	this->m_action = action;
}

OBJ_STATUS Obj_Unit::getStatus()
{
	return m_status;
}
void Obj_Unit::setStatus(OBJ_STATUS var)
{
	m_status = var;	
}

void Obj_Unit::update(float dt)
{

}

void Obj_Unit::addEffect(const char* plist, float px /* = 0.0f */, float py /* = 0.0f */, int count /* = -1 */, float totalTime /* = 1.0f */,SEL_CallFuncO endFunc /* = NULL */, cocos2d::CCObject* pTarget /* = NULL */, bool front /* = true */)
{
	TextureEffect* pResult  = TextureEffect::create();
	pResult->init(plist,true,px,py,totalTime,count,callfuncO_selector(Obj_Unit::addEffectCallback),this);
	if(front)
		pResult->_setZOrder(1);
	else
		pResult->_setZOrder(-1);

	this->addChild(pResult);
}
void Obj_Unit::addEffectCallback(cocos2d::CCObject* pTarget)
{
	TextureEffect* pEffect = dynamic_cast<TextureEffect*>(pTarget);
	if(pEffect != NULL)
		this->removeChild(pEffect,true);
}

bool Obj_Unit::touchCatch(cocos2d::CCPoint& point)
{
	return false;
}

CCPoint Obj_Unit::getDirPoint(float length)
{
	CCPoint result(this->getPositionX(),this->getPositionY());
	switch(m_dir)
	{
	case DIR_TOP:
		result.y -= length;
		break;
	case DIR_TOP_RIGHT:
		result.x +=length*sqrt(2.0f);
		result.y -=length*sqrt(2.0f);
		break;
	case DIR_RIGHT:
		result.x += length;
		break;
	case DIR_BOTTOM_RIGHT:
		result.x +=length*sqrt(2.0f);
		result.y +=length*sqrt(2.0f);
		break;
	case DIR_BOTTOM:
		result.y +=length;
		break;
	case DIR_BOTTOM_LEFT:
		result.x -=length*sqrt(2.0f);
		result.y +=length*sqrt(2.0f);
		break;
	case DIR_LEFT:
		result.x -=length;
		break;
	case DIR_TOP_LEFT:
		result.x -=length* sqrt(2.0f);
		result.y -=length* sqrt(2.0f);
	}

	return result;
}


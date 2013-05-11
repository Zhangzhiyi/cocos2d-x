#ifndef UNIT_EFFECT_H
#define UNIT_EFFECT_H
#include "cocos2d.h"
#include "TextureEffect.h"
#include "Obj/Obj_Unit.h"

USING_NS_CC;
class UnitEffect : public Obj_Unit
{
public:
	UnitEffect();
	virtual ~UnitEffect();

	static UnitEffect* create();

	virtual bool init();

	virtual void initPart(int skinid, int part){}

	virtual void update(float dt);

	virtual void doAttack(Obj_Unit* pUnit)
	{

	}

	virtual void init(const char* plist, float px = 0.0f, float py = 0.0f, 
		int count = -1, float totalTime = 1.0f,cocos2d::SEL_CallFuncO callback = NULL, cocos2d::CCObject* pTarget = NULL);

private:
	CC_SYNTHESIZE_READONLY(TextureEffect*,m_pTextureEffect,TextureEffect);

};


#endif
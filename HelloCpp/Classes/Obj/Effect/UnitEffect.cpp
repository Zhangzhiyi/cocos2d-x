#include "UnitEffect.h"

USING_NS_CC;
UnitEffect::UnitEffect()
{
	m_pTextureEffect = TextureEffect::create();
	m_pTextureEffect->retain();
}

UnitEffect::~UnitEffect()
{
	CC_SAFE_RELEASE_NULL(m_pTextureEffect);
}

bool UnitEffect::init()
{
	return Obj_Unit::init();
}

UnitEffect* UnitEffect::create()
{
	UnitEffect* pResult = new UnitEffect();
	if(pResult && pResult->init())
	{
		pResult->autorelease();
		return pResult;
	}
	return pResult;
}

void UnitEffect::init(const char* plist, float px /* = 0.0f */, float py /* = 0.0f */, int count /* = -1 */, float totalTime /* = 1.0f */,cocos2d::SEL_CallFuncO callback /* = NULL */, cocos2d::CCObject* pTarget /* = NULL */)
{
	m_pTextureEffect->init(plist,false,px,py,totalTime,count,callback,pTarget);
	this->addChild(m_pTextureEffect);
}

void UnitEffect::update(float dt)
{
	if(m_pTextureEffect != NULL)
		m_pTextureEffect->update(dt);
}

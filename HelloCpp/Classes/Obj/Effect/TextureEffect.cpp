#include "TextureEffect.h"


USING_NS_CC;

TextureEffect::TextureEffect()
{
	m_pKey = 0;
	m_isLoop = false;
	m_totalTime = 0.0f;
	m_count = -1;
	m_callback = NULL;
	m_target = NULL;
	m_elapsed = 0.0f;
}

TextureEffect::~TextureEffect()
{
	CC_SAFE_DELETE(m_pKey);
	m_callback = NULL;
	if(m_target != NULL)
		CC_SAFE_RELEASE_NULL(m_target);
}

TextureEffect* TextureEffect::create(const char* plist /* = 0 */)
{
	TextureEffect* pResult = new TextureEffect();
	if(pResult && pResult->init())
	{
		pResult->setKey(plist);
		pResult->autorelease();
		return pResult;
	}
	return NULL;
}

bool TextureEffect::init()
{
	bool result = CCSprite::init();
	this->setAnchorPoint(ccp(256.0f/512,1 - 305.0f/512));
	return result;
}

void TextureEffect::init(const char* plist, bool isSelfLoop, float px, float py, 
						 float totalTime /* = 1.5f */,int count /* = -1 */, 
						 cocos2d::SEL_CallFuncO callback /* = NULL */,cocos2d::CCObject* pTarget /* = NULL */)
{
	setKey(plist);
	setIsLoop(isSelfLoop);
	this->setPosition(ccp(px,py));
	this->m_totalTime = totalTime;
	this->m_count = count;
	this->m_callback = callback;
	this->m_target = pTarget;
	if(m_target != NULL)
		m_target->retain();

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(m_pKey);
	m_elapsed = 0;
}

void TextureEffect::reset()
{

}

void TextureEffect::setIsLoop(bool value)
{
	if(m_isLoop == true && value == false)
		this->unscheduleUpdate();
	else if(m_isLoop == false && value == true)
		this->scheduleUpdate();
	m_isLoop = value;
}

void TextureEffect::update(float dt)
{
	m_elapsed += dt;
	if(m_elapsed >= m_totalTime)
	{
		if(m_count == -1 || --m_count > 0)
			m_elapsed = 0;
		else
		{
			if(m_target != NULL && m_callback != NULL)
			{
				(m_target->*m_callback)(this);
			}
			return;
		}
	}

	float time = m_elapsed / m_totalTime;
	CCSpriteFrame* pSpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->getSpriteFrameByIndex(m_pKey,time,0,0);
	if(pSpriteFrame != NULL)
		this->setDisplayFrame(pSpriteFrame);
}
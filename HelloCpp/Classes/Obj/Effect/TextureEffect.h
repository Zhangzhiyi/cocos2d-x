#ifndef TEXTURE_EFFECT_H
#define TEXTURE_EFFECT_H
#include "cocos2d.h"
USING_NS_CC;

class TextureEffect : public cocos2d::CCSprite
{
public:
	TextureEffect();
	virtual ~TextureEffect();

	static TextureEffect* create(const char* plist = 0);
	virtual bool init();
	virtual void init(const char* plist, bool isSelfLoop, float px, float py, 
		float totalTime = 1.5f,int count = -1, cocos2d::SEL_CallFuncO callback = NULL,cocos2d::CCObject* pTarget = NULL);
public:
	void reset();
	virtual void update(float dt);

	void setKey(const char* pKey)
	{
		if(m_pKey != NULL)
			CC_SAFE_DELETE_ARRAY(m_pKey);
		if(pKey == NULL)
			return;
		int keyLen = strlen(pKey) + 6;
		if(keyLen == 0)
			return;
		m_pKey = new char[keyLen + 1];
		m_pKey[keyLen] = 0;
		sprintf(m_pKey,"%s.plist",pKey);
	}
	const char* getKey(){return m_pKey;}

	void setIsLoop(bool value);
	bool getIsLoop(){return m_isLoop;}
private:
	char* m_pKey;
	bool m_isLoop;
	float m_elapsed;
	float m_totalTime;
	int m_count;
	cocos2d::SEL_CallFuncO m_callback;
	cocos2d::CCObject* m_target;
};

#endif
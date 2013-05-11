#include "Animal_One.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "support/CCPointExtension.h"

USING_NS_CC;
Animal_One::Animal_One()
{
	m_skinKey = NULL;
}

Animal_One::~Animal_One()
{
	CC_SAFE_DELETE(m_skinKey);
}

Animal* Animal_One::create(Obj_Unit* pParent)
{
	Animal_One* pResult = new Animal_One();
	if(pResult && pResult->init())
	{
		pResult->setUnitParent(pParent);
		pParent->addChild(pResult);
		return pResult;
	}
	return 0;
}

bool Animal_One::init()
{
	CCSprite::init();
	m_skinKey = new char[50];
	memset(m_skinKey,0,sizeof(char) * 50);
	this->setAnchorPoint(ccp(256.0f/512,1 - 305.0f/512));
	return true;
}

bool Animal_One::initPart(int skinid, ANIMAL_PART part /* = PART_BODY */)
{
	sprintf(m_skinKey,"%d.plist",skinid);
	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(m_skinKey);

	return true;
}

void Animal_One::doUpdate(float time, OBJ_ACTION action, OBJ_DIR dir)
{
	if(m_skinKey != NULL)
	{
		if(dir >= 5)
		{
			dir = (OBJ_DIR)(DIR_NUM - dir);
			this->setScaleX(-1);
		}
		else
		{
			this->setScaleX(1);
		}
		CCSpriteFrame* pSpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->getSpriteFrameByIndex(m_skinKey,time,action,dir);
		if(pSpriteFrame != NULL)
			this->setDisplayFrame(pSpriteFrame);
	}
}
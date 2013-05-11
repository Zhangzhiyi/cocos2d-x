#ifndef SPRITE_FRAME_UTIL_H
#define SPRITE_FRAME_UTIL_H
#include "cocos2d.h"

class SpriteFrameUtil 
{
public:
	SpriteFrameUtil();
	virtual ~SpriteFrameUtil();

	static SpriteFrameUtil* sharedSpriteFrameUtil();

public:
	void spriteFramesWithFileName(const char* pszPlist);
};

#endif
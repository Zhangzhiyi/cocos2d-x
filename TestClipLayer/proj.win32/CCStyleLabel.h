#ifndef __CC_STYLE_LABEL_H__
#define __CC_STYLE_LABEL_H__
#include "cocos2d.h"
USING_NS_CC;

class CCStyleLabel : public CCLabelTTF
{
public:
	CCStyleLabel(void);
	~CCStyleLabel(void);
	virtual void draw();

	CREATE_FUNC(CCStyleLabel);

	static CCStyleLabel* create(const char* string, const char* fontName, float fontSize);
};
#endif

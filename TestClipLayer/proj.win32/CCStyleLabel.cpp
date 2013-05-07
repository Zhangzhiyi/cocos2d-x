#include "CCStyleLabel.h"


CCStyleLabel::CCStyleLabel(void)
{
}

CCStyleLabel::~CCStyleLabel(void)
{
}
//CCStyleLabel* CCStyleLabel::create()
//{
//	CCStyleLabel * pRet = new CCStyleLabel();
//	if (pRet && pRet->init())
//	{
//		pRet->autorelease();
//	}
//	else
//	{
//		CC_SAFE_DELETE(pRet);
//	}
//	return pRet;
//}
CCStyleLabel* CCStyleLabel::create(const char* string, const char* fontName, float fontSize)
{
	CCStyleLabel * pRet = new CCStyleLabel();
	if (pRet && pRet->initWithString(string, fontName, fontSize))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}
void CCStyleLabel::draw()
{
	CCLabelTTF:draw();
}

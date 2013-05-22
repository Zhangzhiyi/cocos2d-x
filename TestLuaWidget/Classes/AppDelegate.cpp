#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "cocos2dx_support/luaj/LuaJavaBridge.h"
#endif

using namespace CocosDenshion;

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    pDirector->setOpenGLView(pEGLView);

	CCSize designSize = CCSizeMake(800, 480);
	CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();

	if (screenSize.height > 320)
	{
		//CCSize resourceSize = CCSizeMake(960, 640);
		//pDirector->setContentScaleFactor(resourceSize.height/designSize.height);
	}
	pEGLView->setDesignResolutionSize(designSize.width, designSize.height, kResolutionNoBorder);



    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // register lua engine
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
	
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
			LuaJavaBridge::luabindingOpen(pEngine->getLuaStack()->getLuaState());
	#endif
    std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("luascript/Global.lua");
    pEngine->executeScriptFile(path.c_str());

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();

    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();

    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

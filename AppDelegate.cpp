//
//  bugAppDelegate.cpp
//  bug
//
//  Created by pat on 13-3-1.
//  Copyright __MyCompanyName__ 2013�? All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "HelloWorldScene.h"
//#include "TestLayer.h"
#include "LoadingScene.h"
#include "GameMarcos.h"
#include "GameManager.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    
    pDirector->setOpenGLView(pEGLView);
    
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
    CCSize framSize = pEGLView->getFrameSize();
    
    
    CCFileUtils::sharedFileUtils()->setResourceDirectory(hongMiResource.directory);
	CCString mm;
	mm = CCFileUtils::sharedFileUtils()->getResourceDirectory();

	CCLOG("curent URL: %s", mm);

    pDirector->setContentScaleFactor(hongMiResource.size.width/designResolutionSize.width);
    

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene =  new LoadingScene();//TestLayer::scene();//
    // run
    pDirector->runWithScene(pScene);

    return true;
}



// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be paused
     CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
     CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

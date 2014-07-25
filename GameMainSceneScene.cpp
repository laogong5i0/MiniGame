//
//  GameMainSceneScene.cpp
//  bug
//
//  Created by pat on 13-3-6.
//
//

#include "GameMainSceneScene.h"
#include "GameMarcos.h"

bool GameMainSceneScene::init(){
    CCLOG("game mainScene scene init();");
    CCNodeLoaderLibrary *ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader("GameMianSceneLayer", GameMainScenelayerLoader::loader());
    
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    CCNode * ccNode = ccbReader->readNodeGraphFromFile("main.ccbi", this);
	ccNode->setTag(TAG_RUNNING_LAYER);
    ccbReader->autorelease();
    
    if(ccNode!=NULL){
        this->addChild(ccNode);
    }
    
    return true;
}
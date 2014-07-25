//
//  MenuScene.cpp
//  bug
//
//  Created by pat on 13-3-5.
//
//

#include "MenuScene.h"
#include "gamemarcos.h"

MenuScene::MenuScene(){
    init();
}

bool MenuScene::init(){
    CCLOG("Menu scene init");
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("MenuLayer", MenuLayerLoader::loader());
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    
    /* Read a ccbi file. */
    CCNode * node = ccbReader->readNodeGraphFromFile("menu.ccbi", this);
    node->setTag(TAG_RUNNING_LAYER);
    ccbReader->release();
    
    if(node != NULL) {
        this->addChild(node);
    }
    return true;
    
}
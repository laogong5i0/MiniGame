
//  LoadingScene.cpp
//  bug
//
//  Created by pat on 13-3-1.
//
//
#include "LoadingScene.h"
#include "GameMarcos.h"
#include "LoadingLayerLoader.h"


USING_NS_CC;
USING_NS_CC_EXT;

LoadingScene::LoadingScene(){
    CCLabelTTF * label = CCLabelTTF::create("test", "arial", 30);
    label->setPositionX(CCDirector::sharedDirector()->getWinSizeInPixels().width/2);
    label->setPositionY(CCDirector::sharedDirector()->getWinSizeInPixels().height/2);
    this->addChild(label);
    init();
}

void LoadingScene::menucall(CCObject* sender){
	CCLOG("menu log");
}

bool LoadingScene::init(){
    CCLOG("loading scene init");
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    		
    ccNodeLoaderLibrary->registerCCNodeLoader("LoadingLayer", LoadingLayerLoader::loader());
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    
    /* Read a ccbi file. */
    CCNode * node = ccbReader->readNodeGraphFromFile("comic.ccbi", this);
    node->setTag(TAG_RUNNING_LAYER);
    ccbReader->release();

    
    if(node != NULL) {
        this->addChild(node);
        static char s;
        sprintf(&s, "loading node %f, %f", node->getPositionX(), node->getPositionY());
        CCLOG("%s", &s);
        sprintf(&s, "loading node: scale %f", node->getScale());
        CCLOG("%s", &s);
        sprintf(&s, "loading node: contentsize %f, %f", node->getContentSize().width, node->getContentSize().height);
        CCLOG("%s", &s);
    }
    
    //CCDirector::sharedDirector()->replaceScene(this);
    return true;
}


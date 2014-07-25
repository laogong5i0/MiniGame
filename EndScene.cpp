//
//  EndScene.cpp
//  bug
//
//  Created by pat on 13-12-13.
//
//

#include "EndScene.h"
#include "GameMarcos.h"

bool EndScene:: init(){
    CCLOG("Game End Scene init();");
    
    CCNodeLoaderLibrary *ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader("EndLayer", EndLayerLoader::loader());
    
    cocos2d::extension::CCBReader* ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    CCNode* node = ccbReader->readNodeGraphFromFile("end.ccbi", this);
    node->setTag(TAG_RUNNING_LAYER);
    ccbReader->release();
    if (node != NULL) {
        this->addChild(node);
    }		
    
    return true;
}
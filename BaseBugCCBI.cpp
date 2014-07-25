//
//  BaseBugCCBI.cpp
//  bug
//
//  Created by pat on 13-9-10.
//
//

#include "BaseBugCCBI.h"

USING_NS_CC;
USING_NS_CC_EXT;

BaseBugCCBI::BaseBugCCBI():mAnimationManager(NULL){
    
}

BaseBugCCBI::~BaseBugCCBI(){
    this->release();
}

void BaseBugCCBI::completedAnimationSequenceNamed(const char *name){
    if(strcmp(name, "death")==0){
        LogicEventStruct event;
        event.name = BUG_DEATH;
        event.data = this->getParent();
        GameManager::getInstance()->sendLogicNotify(event);
    }
}

void BaseBugCCBI::setAnimationManager(cocos2d::extension::CCBAnimationManager *pAnimationManager){
    CC_SAFE_RELEASE_NULL(mAnimationManager);
    mAnimationManager = pAnimationManager;
    mAnimationManager->setDelegate(this);
    CC_SAFE_RETAIN(mAnimationManager);
}

void BaseBugCCBI::playAnimation(cocos2d::CCString name){
    CC_ASSERT(mAnimationManager);
    mAnimationManager->runAnimations(name.m_sString.c_str());
}



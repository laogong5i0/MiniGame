//
//  BaseBugCCBI.h
//  bug
//
//  Created by pat on 13-9-10.
//
//

#ifndef __bug__BaseBugCCBI__
#define __bug__BaseBugCCBI__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "gamemanager.h"
#include "LogicObserver.h"


USING_NS_CC;
USING_NS_CC_EXT;

class BaseBugCCBILoader;

class BaseBugCCBI : public cocos2d::CCSprite

, cocos2d::extension::CCBAnimationManagerDelegate
{
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
public:
    
    BaseBugCCBI();
    virtual ~BaseBugCCBI();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(BaseBugCCBI, create);
    
    void setAnimationManager(cocos2d::extension::CCBAnimationManager *pAnimationManager);
    void completedAnimationSequenceNamed(const char *name);
    void playAnimation(CCString name);
};


#endif /* defined(__bug__BaseBugCCBI__) */

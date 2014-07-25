//
//  StatusLayer.h
//  bug
//
//  Created by pat on 13-10-21.
//
//

#ifndef __bug__StopLayer__
#define __bug__StopLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

class StatusLayer: public CCLayer{
    CCScale9Sprite* BGSprite;
    CCSprite* playerBut;
    CCSprite* pauseBut;
    
    CCScale9Sprite* createBackgroun();
public:
    static StatusLayer* create();
    bool init();
    virtual void onEnter();
    void playCallback(CCObject* pSender);
    virtual bool ccTouchBegan(CCTouch* pTouches, CCEvent* pEvent);
    
};

#endif /* defined(__bug__StopLayer__) */

//
//  StopLayer.cpp
//  bug
//
//  Created by pat on 13-10-21.
//
//

#include "StatusLayer.h"

StatusLayer* StatusLayer::create(){
    StatusLayer* sl = new StatusLayer();
    sl->init();
    return sl;
}

bool StatusLayer::init(){
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    
    BGSprite = createBackgroun();
    BGSprite->setPosition(ccp(s.width/2, s.height/2));
    
    CCLayerColor* bg = CCLayerColor::create(ccc4(0, 0, 0, 150), s.width, s.height);
    CCMenuItemImage* play = CCMenuItemImage::create("yellow_edit.png", "green_edit.png", this, menu_selector(StatusLayer::playCallback));
    CCMenu* menu = CCMenu::createWithItem(play);
    
    
    this->addChild(bg);
    this->addChild(BGSprite);
    this->addChild(menu);
    
    //setTouchEnabled(true);
    return CCLayer::init();
}

void StatusLayer::onEnter(){
    setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);
    CCLog("status layer onEnter");
    //bool b= isTouchEnabled();
    CCLayer::onEnter();
}


CCScale9Sprite* StatusLayer::createBackgroun(){
    CCScale9Sprite* sprite = CCScale9Sprite::create("yellow_edit.png");//,CCRectMake(0, 0, 28, 28), CCRectMake(8, 8, 12, 12));//, CCRectMake(0, 0, s.width, s.height)
    sprite->setContentSize(CCSizeMake(180,100));
    return sprite;
}

void StatusLayer::playCallback(cocos2d::CCObject *pSender){
    GameManager::getInstance()->resume();
    GameManager::getInstance()->setGameStatus(GAMEING);
}

bool StatusLayer::ccTouchBegan(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent){
    CCLog("status layer touch began");
    return true;
}


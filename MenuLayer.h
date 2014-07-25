//
//  Menue.h
//  bug
//
//  Created by pat on 13-3-4.
//
//

#ifndef __bug__Menue__
#define __bug__Menue__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameMainSceneScene.h"
#include "GameManager.h"

class MenuLayer
: public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MenuLayer, create);
    
    static cocos2d::CCScene * scene();
    
    MenuLayer();
    virtual ~MenuLayer();
	bool init();
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, cocos2d::CCString * pMemberVariableName, cocos2d::CCNode * pNode);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName);
    
    void startBtnClick(cocos2d::CCObject * object);
    virtual void ccTouchesBegan(cocos2d::CCSet * pTouch, cocos2d::CCEvent * pEvent);
    virtual bool ccTouchBegan(cocos2d::CCTouch * pTouch, cocos2d::CCEvent * pEvent);
    
    virtual void update(float deita);

	virtual void keyMenuClicked();
private:
    cocos2d::CCMenuItemImage * startBtn;
    //cocos2d::CCLabelTTF * labelTxt;
};


#endif /* defined(__bug__Menue__) */

//
//  LoadingLayer.h
//  bug
//
//  Created by pat on 13-3-1.
//
//

#ifndef __bug__LoadingLayer__
#define __bug__LoadingLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"


class LoadingLayer
: public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LoadingLayer, create);
    
    LoadingLayer();
    virtual ~LoadingLayer();
    void openTest(const char * pCCBFileName, const char * pCCNodeName = NULL, cocos2d::extension::CCNodeLoader * pCCNodeLoader = NULL);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, cocos2d::CCString * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);

    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

    void ccTouchesBegan(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchesEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchesMoved(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
    void moveBG();
    void makeMenu(float t);
    void skipHandler(CCObject* object);

private:
    cocos2d::CCProgressTimer* loadProgress;
    cocos2d::CCSprite * background;
    cocos2d::CCSprite * scrollBar;
    cocos2d::CCSprite* scrollBarBG;
    cocos2d::CCNode* loadNode;
cocos2d::CCLabelTTF * scrollTxt;
    float criticalValue;
    float hasTouchMove;
    cocos2d::CCPoint pointBegan;
    long getCurrentTime();

};
#endif /* defined(__bug__LoadingLayer__) */

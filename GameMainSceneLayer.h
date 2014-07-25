//
//  GameScene.h
//  bug
//
//  Created by pat on 13-3-5.
//
//

#ifndef __bug__GameScene__
#define __bug__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "LogicObserver.h"
//#include "BaseBug.h"
#include "ScoreManager.h"
#include "BugManager.h"
//#include "GameManager.h"

USING_NS_CC;
USING_NS_CC_EXT;


class GameMainSceneLayer : public cocos2d::CCLayer
, public LogicObserver
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    cocos2d::CCArray *bugList;
    cocos2d::CCSprite * cake;
    BugManager* m_bugManager;
    CCControlButton* m_stopBut;
    
    CCControlButton* createStopBut();
    cocos2d::CCSprite * scoreIcon;
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameMainSceneLayer, create);
    GameMainSceneLayer();
    virtual void onEnter();
    virtual ~GameMainSceneLayer();
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, cocos2d::CCString * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, cocos2d::CCString * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, cocos2d::CCString * pSelectorName);
    bool init();
    //virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *pTouches, CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch *pTouches, CCEvent* pEvent);
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent * pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent * PEvent);
    virtual void logicHandler(LogicEventStruct event);
    
    void stopButAction(CCObject* sender, CCControlEvent controlEvent);
    void update(CCTime dt);

	// The back key clicked
	virtual void keyBackClicked();
	// The menu key clicked. only available on wophone & android
	virtual void keyMenuClicked();
};

class CCBReader;

class GameMainScenelayerLoader : public cocos2d::extension::CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameMainScenelayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameMainSceneLayer);
};



#endif /* defined(__bug__GameScene__) */

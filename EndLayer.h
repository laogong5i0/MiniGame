//
//  EndLayer.h
//  bug
//
//  Created by pat on 13-12-13.
//
//

#ifndef __bug__EndLayer__
#define __bug__EndLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

class EndLayer : public CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public CCNodeLoaderListener{
    
private:
    CCLabelTTF* hScoreLabel;
    CCLabelTTF* scoreLabel;
    int mScore;
    
public:
    EndLayer();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(EndLayer, create)
    bool init();
	virtual void onEnter();
    virtual void onNodeLoaded(CCNode* pNode, CCNodeLoader* pNodeLoader);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, CCString * pMemberVariableName, CCNode* pNode);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, CCString * pSelectorName);
    virtual extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, CCString * pSelectorName);
    
    void playAgain(CCObject* obj);
    void showMenu(CCObject* obj);
	void keyMenuClicked();
};

class CCBReader;

class EndLayerLoader: public CCLayerLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(EndLayerLoader, loader);
protected:
CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(EndLayer);
};

#endif /* defined(__bug__EndLayer__) */

//
//  Menue.cpp
//  bug
//
//  Created by pat on 13-3-4.
//
//

#include "MenuLayer.h"
#include "MenuLayerLoader.h"
#include "GameMarcos.h"

//#include "GameEnum.h"

USING_NS_CC;
USING_NS_CC_EXT;

MenuLayer::MenuLayer(): startBtn(NULL){

}

MenuLayer::~MenuLayer(){}

CCScene * MenuLayer::scene(){
	CCScene * scene = CCScene::create();
	CCLayer * layer = MenuLayer::create();
	scene->addChild(layer);
	return scene;
}



void MenuLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader){
	//labelTxt->setString("hah, you will start game!");
	//labelTxt->setPositionY(100);
	this->scheduleUpdate();
	startBtn->setPositionY(100);

}

void MenuLayer::update(float deita){
	//CCLOG("menu layer update()");
}


bool MenuLayer::onAssignCCBMemberVariable(CCObject *pTarget, CCString *pMemberVariableName, CCNode *pNode){
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "startBtn", CCMenuItemImage *, this->startBtn);
	//CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "labelTxt", CCLabelTTF *, this->labelTxt);
	return false;
}


SEL_MenuHandler MenuLayer::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName){
	CCLOG("on resolved ccb ccMenu item selector");
	CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "startBtnClick", MenuLayer::startBtnClick);
	return NULL;
}

void MenuLayer::startBtnClick(CCObject * object){
	CCLOG("start button has been click");
	GameManager::getInstance()->PlayerNewGame();
}

SEL_CCControlHandler MenuLayer::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName){
	return NULL;
}

void MenuLayer::ccTouchesBegan(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent){
	CCLOG("cc touches began");
}
	
bool MenuLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
	CCLog("cc touch began");
	return true;
}

void MenuLayer::keyMenuClicked()
{
	if(CCDirector::sharedDirector()->getRunningScene()->getChildByTag(TAG_CONFIG_MENU_LAYER)==NULL){
		GameManager::getInstance()->displayMeue();
		GameManager::getInstance()->pauseGame();
	}else{
		GameManager::getInstance()->displayNotMenu();
		GameManager::getInstance()->resume();
	}
}

bool MenuLayer::init()
{
	this->setKeypadEnabled(true);
	return CCLayer::init();
}

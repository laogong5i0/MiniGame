//
//  EndLayer.cpp
//  bug
//
//  Created by pat on 13-12-13.
//
//

#include "EndLayer.h"
#include "GameMarcos.h"

EndLayer::EndLayer():mScore(0)
,hScoreLabel(NULL)
,scoreLabel(NULL){
}
bool EndLayer::init(){
	GameManager* GManager = GameManager::getInstance();
	ScoreManager* scoreManager = GManager->getScoreManager();
	mScore = scoreManager->getScore();
	this->setKeypadEnabled(true);
	return true;
}

void EndLayer::onEnter(){
	CCLayer::onEnter();
	ScoreManager *scoreManager = GameManager::getInstance()->getScoreManager();
	int hScore = scoreManager->getHeightScore();
	if(mScore>hScore){
		hScore = mScore;
		scoreManager->setHeightScore(hScore);
	}
	CCString *hscoreStr = CCString::createWithFormat("%d", hScore);
	this->hScoreLabel->setString(hscoreStr->getCString());
}

void EndLayer::onNodeLoaded(CCNode* pNode, CCNodeLoader* pNodeLoader){
	static char buffer;
	sprintf(&buffer, "%d", mScore);
	this->scoreLabel->setString(&buffer);
	
}

bool EndLayer::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, cocos2d::CCString *pMemberVariableName, cocos2d::CCNode *pNode){
	
	CCLOG("current object: %s", pMemberVariableName->getCString());
	if(pMemberVariableName->m_sString == "hScoreLabel"){
		CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "hScoreLabel", CCLabelTTF *, this->hScoreLabel);
	}
	if(pMemberVariableName->m_sString == "scoreLabel"){
		CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreLabel", CCLabelTTF *, this->scoreLabel);
	}
	return true;
}

SEL_MenuHandler EndLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, CCString * pSelectorName){
	if(pSelectorName->m_sString == "playAgain"){
		CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "playAgain", EndLayer::playAgain);
	}
	if(pSelectorName->m_sString == "menu"){
		CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menu", EndLayer::showMenu);
	}
	return NULL;
}

extension::SEL_CCControlHandler EndLayer::onResolveCCBCCControlSelector(CCObject * pTarget, CCString * pSelectorName){
	return NULL;
}

void EndLayer::playAgain(CCObject* obj){
	GameManager::getInstance()->PlayerNewGame();
}

void EndLayer::showMenu(CCObject* obj){
	
}

void EndLayer::keyMenuClicked()
{
	if(CCDirector::sharedDirector()->getRunningScene()->getChildByTag(TAG_CONFIG_MENU_LAYER)==NULL){
		GameManager::getInstance()->displayMeue();
		GameManager::getInstance()->pauseGame();
	}else{
		GameManager::getInstance()->displayNotMenu();
		GameManager::getInstance()->resume();
	}
}

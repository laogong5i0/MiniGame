//
//  GameScene.cpp
//  bug
//
//  Created by pat on 13-3-5.
//
//

#include "GameMainSceneLayer.h"
#include "GameMarcos.h"

USING_NS_CC;
USING_NS_CC_EXT;

GameMainSceneLayer::GameMainSceneLayer():cake(NULL)
, scoreIcon(NULL)
, bugList(new CCArray())
, m_bugManager(NULL){
	
}
GameMainSceneLayer::~GameMainSceneLayer(){
	//CC_SAFE_DELETE(m_stopBut);
	//CC_SAFE_DELETE(cake);
	//CC_SAFE_DELETE(bugList);
	//CC_SAFE_DELETE(m_bugManager);
	GameManager::getInstance()->removeLogicObserver(this);
	//CCLayer::~CCLayer();
}
bool GameMainSceneLayer::init(){
	CCLOG("game main scene layer init();5");
	//this->setTouchEnabled(true);gh
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	
	GameManager::getInstance()->setCurrentLayer(this);
	GameManager::getInstance()->addLogicObserver(this);
	m_bugManager = BugManager::create();
	//m_stopBut = createStopBut();
	//m_stopBut->setAnchorPoint(ccp(0.5f, 0.5f));
	//m_stopBut->setPosition(ccp(s.width-150, s.height-150));
	
	//this->schedule(schedule_selector(GameMainSceneLayer::update));
	this->setKeypadEnabled(true);
	return CCLayer::init();
}

void GameMainSceneLayer::onEnter(){
	CCLayer::onEnter();
	GameManager::getInstance()->setCurrentLayer(this);
	
	this->addChild(m_bugManager);
	GameManager::getInstance()->getScoreManager()->setScore(0);
	
	/*this->addChild(m_stopBut);*/
}

//void GameMainSceneLayer::registerWithTouchDispatcher(){
	//CCDirector * pDirector = CCDirector::sharedDirector();
	//pDirector->getTouchDispatcher()->addTargetedDelegate(this, INT_MIN+1, false);
	//pDirector->getTouchDispatcher()->addStandardDelegate(this, INT_MIN);
//}
bool GameMainSceneLayer::ccTouchBegan(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent){
	CCLOG("cc touch began");
	return true;
}

void GameMainSceneLayer::ccTouchEnded(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent){
	CCLOG("cc touch ended");
}

void GameMainSceneLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
	CCLOG("Game main Scene touches began");
	/*if(!pTouches || !pTouches->count())return;
	CCTouch * touch = (CCTouch*)(pTouches->anyObject());
	CCPoint p = CCPointMake(touch->getLocation().x, touch->getLocation().y);
	//loaderBug(p);//->setPosition(touch->getLocation().x, touch->getLocation().y);
	
	//this->cake->runAction(CCMoveTo::create(2, ccp(0,0)));
	GameManager* gameM = GameManager::getInstance();
	LogicEventStruct event;
	event.name = BUG_MOVE_END;
	gameM->sendLogicNotify(event);*/
	
	//GameManager::getInstance()->gameOver();
}

void GameMainSceneLayer::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *PEvent){
	//CCLOG("Game main Scene touches ended");
	
}

bool GameMainSceneLayer::onAssignCCBMemberVariable(CCObject * pTarget, cocos2d::CCString * pMemberVariableName, cocos2d::CCNode * pNode){
	//CCLOG("gameScene on assign ccb member variable");
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "cake", CCSprite *, this->cake);
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreIcon", CCSprite *, this->scoreIcon);
	return false;
}

void GameMainSceneLayer::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader){
	//CCLOG("gameScene on node loaded");
	this->setTouchEnabled(true);
	this->setTouchMode(cocos2d::kCCTouchesAllAtOnce);
	
	CCPoint scoreIconPoint = this->scoreIcon->getPosition();
	float width = this->scoreIcon->getContentSize().width;
	CCPoint p = ccp((scoreIconPoint.x+ width), scoreIconPoint.y);
	GameManager::getInstance()->getScoreManager()->addScoreTo(this, p);
}

cocos2d::SEL_MenuHandler GameMainSceneLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, cocos2d::CCString * pSelectorName){
	//CCLOG("gameScene on resolve ccb ccMenu item selector");
	return NULL;
}
cocos2d::extension::SEL_CCControlHandler GameMainSceneLayer::onResolveCCBCCControlSelector(CCObject * pTarget, cocos2d::CCString * pSelectorName){
	//CCLOG("gameScene on resolve ccb control selector");
	return NULL;
}

void GameMainSceneLayer::logicHandler(LogicEventStruct event){
	//CCLOG("Observer name: %f", event.name);
}

CCControlButton* GameMainSceneLayer::createStopBut(){
	CCScale9Sprite* stopBackgrundBut = CCScale9Sprite::create("button.png");
	CCScale9Sprite* stopBackgrundHighlightedBut = CCScale9Sprite::create("buttonhighlighted.png");
	CCLabelTTF* stopTitleBut = CCLabelTTF::create("Stop", "Arial", 30);
	stopTitleBut->setColor(ccc3(159,168,176));
	
	CCControlButton* stopBut = CCControlButton::create(stopTitleBut, stopBackgrundBut);
	stopBut->setBackgroundSpriteForState(stopBackgrundHighlightedBut, CCControlStateHighlighted);
	stopBut->setTitleColorForState(ccWHITE, CCControlStateHighlighted);

	stopBut->addTargetWithActionForControlEvents(this, cccontrol_selector(GameMainSceneLayer::stopButAction), CCControlEventTouchDown);
	return stopBut;
}

void GameMainSceneLayer::stopButAction(cocos2d::CCObject *sender, CCControlEvent controlEvent){
	GameManager* GManager = GameManager::getInstance();
	if(GManager->getGameStatus()!=GAME_PAUSE){
		GManager->pauseGame();
		GManager->setGameStatus(GAME_PAUSE);
	}else{
		GManager->resume();
		GManager->setGameStatus(GAMEING);
	}
}

void GameMainSceneLayer::update(CCTime dt){
	CCArray* bugList = m_bugManager->getChildren();
	CCObject* _bug;
	//GameManager* GManager = GameManager::getInstance();
	CCARRAY_FOREACH(bugList, _bug){
		BaseBug* bug = (BaseBug*) _bug;
		if(this->cake->boundingBox().intersectsRect(bug->boundingBox())){
			m_bugManager->removeBug(bug);
			bug=NULL;
			//GManager->gameOver();
			bugList=NULL;
			return;
		}
	}
	bugList = NULL;
}

void GameMainSceneLayer::keyBackClicked()
{
	
	
}

void GameMainSceneLayer::keyMenuClicked()
{
	if(CCDirector::sharedDirector()->getRunningScene()->getChildByTag(TAG_CONFIG_MENU_LAYER)==NULL){
		GameManager::getInstance()->displayMeue();
		GameManager::getInstance()->pauseGame();
	}else{
		GameManager::getInstance()->displayNotMenu();
		GameManager::getInstance()->resume();
	}
}

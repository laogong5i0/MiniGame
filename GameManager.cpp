//
//  GameManager.cpp
//  bug
//
//  Created by pat on 13-9-5.
//
//


#include "GameManager.h"
#include "GameMainSceneScene.h"
#include "SimpleAudioEngine.h"
#include "ConfigMenu.h"
#include "Statuslayer.h"
#include "EndScene.h"
#include "GameMarcos.h"

GameManager* GameManager::m_instance = NULL;
GameManager::GameManager():m_currentLayer(NULL)
, m_scoreManager(NULL)
, m_statusLayer(NULL)
//, m_mainScene(NULL)
{
	init();
}


GameManager* GameManager::getInstance(){
	if(!m_instance){
		m_instance = new GameManager();
	}
	return m_instance;
}

void GameManager::init(){
	m_logicManager = LogicManager::create();
	m_scoreManager = new ScoreManager();
	
	
}


void GameManager::setCurrentLayer(CCLayer* layer){
	if(m_currentLayer==layer)
		return;
	m_currentLayer = layer;
}
CCLayer* GameManager::getCurrentLayer(){
	return m_currentLayer;
}

void GameManager::addLogicObserver(LogicObserver *observer){
	m_logicManager->addObserver(observer);
}

void GameManager::removeLogicObserver(LogicObserver *observer){
	m_logicManager->removeObserver(observer);
}

void GameManager::sendLogicNotify(LogicEventStruct event){
	m_logicManager->notify(event);
}

ScoreManager* GameManager::getScoreManager(){
	CCAssert(m_scoreManager!=NULL, "The ScoreManager should be add to GameManager.");
	return m_scoreManager;
}

void GameManager::setScoreManager(ScoreManager* manager){
	m_scoreManager = manager;
}

GameStatus GameManager::getGameStatus(){
	return m_gameStatus;
}
void GameManager::setGameStatus(GameStatus status){
	m_gameStatus = status;
}


void GameManager::pauseGame(){
	CCDirector::sharedDirector()->pause();
	CCLog("current Game Status: %d", m_gameStatus);
	//if(m_gameStatus == GAMEING){
	//	if(m_statusLayer==NULL)
	//		m_statusLayer = StatusLayer::create();
	//	getCurrentLayer()->addChild(m_statusLayer);
	//}
}
void GameManager::resume(){
	CCLOG("resume game");
	CCDirector::sharedDirector()->resume();
	/*if(m_statusLayer->getParent()!=NULL){
		getCurrentLayer()->removeChild(m_statusLayer, false);
	}*/
}
void GameManager::restartGame(){
	CCLOG("restart game");
}
void GameManager::PlayerNewGame(){
	CCLOG("player new game");
	CCScene * ccScene = GameMainSceneScene::create();
	CCDirector::sharedDirector()->replaceScene(ccScene);
	GameManager::getInstance()->setGameStatus(GAMEING);

}
void GameManager::gameOver(){
	CCLOG("game over2");
	CCScene * ccScene = EndScene::create();
	CCDirector::sharedDirector()->replaceScene(ccScene);
	//CCDirector::sharedDirector()->pushScene(ccScene);
	GameManager::getInstance()->setGameStatus(GAME_OVER);
}

void GameManager::playerBackgroundMusic()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("tinyapple.mp3", true);
	CCUserDefault::sharedUserDefault()->setBoolForKey(CONFIG_KEY_HAS_MUSIC, true);
	CCUserDefault::sharedUserDefault()->flush();
}

void GameManager::stopBackgroundMusic()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	CCUserDefault::sharedUserDefault()->setBoolForKey(CONFIG_KEY_HAS_MUSIC, false);
	CCUserDefault::sharedUserDefault()->flush();
}

void GameManager::displayMeue()
{
	CCScene* scene = CCDirector::sharedDirector()->getRunningScene();//this->getCurrentScene();
	ConfigMenu *configMenu = ConfigMenu::create();
	configMenu->setTag(TAG_CONFIG_MENU_LAYER);
	scene->addChild(configMenu);
}

void GameManager::displayNotMenu()
{
	CCScene* scene = CCDirector::sharedDirector()->getRunningScene();//this->getCurrentScene();
	scene->removeChildByTag(TAG_CONFIG_MENU_LAYER, true);
}

bool GameManager::isHavaSaveFile()
{
	if(!CCUserDefault::sharedUserDefault()->getBoolForKey( CONFIG_HAS_XML_FILE)){
		CCUserDefault::sharedUserDefault()->setBoolForKey( CONFIG_HAS_XML_FILE, true);
		CCUserDefault::sharedUserDefault()->setIntegerForKey( CONFIG_KEY_HEIGHT_SCORE, 0);
		CCUserDefault::sharedUserDefault()->setBoolForKey( CONFIG_KEY_HAS_MUSIC, true);
		CCUserDefault::sharedUserDefault()->flush();
		return false;
	}else{
		return true;
	}
}

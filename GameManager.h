//
//  GameManager.h
//  bug
//
//  Created by pat on 13-9-5.
//
//

#ifndef __bug__GameManager__
#define __bug__GameManager__

#include <iostream>
#include "cocos2d.h"
#include "LogicManager.h"
#include "ScoreManager.h"

//#include "GameMainSceneScene.h"


USING_NS_CC;
class LogicManager;
class StatusLayer;
//class GameMainSceneScene;

class GameManager : public CCObject{
    
    GameManager();
    static GameManager* m_instance;
    GameStatus m_gameStatus;
    CCLayer* m_currentLayer;
	CCScene* m_currentScene;
    LogicManager* m_logicManager;
    ScoreManager* m_scoreManager;
    StatusLayer* m_statusLayer;
    //GameMainSceneScene* m_mainScene;
    
public:
    static GameManager* getInstance();
    
    void init();
    
    void setCurrentLayer(CCLayer* layer);
    CCLayer* getCurrentLayer();
    void addLogicObserver(LogicObserver* observer);
    void removeLogicObserver(LogicObserver* observer);
    void sendLogicNotify(LogicEventStruct event);
    
    ScoreManager* getScoreManager();
    void setScoreManager(ScoreManager* manager);
    
    GameStatus getGameStatus();
    void setGameStatus(GameStatus status);
    
    void pauseGame();
    void PlayerNewGame();
    void resume();
    void restartGame();
    void gameOver();
    void playerBackgroundMusic();
	void stopBackgroundMusic();
	void displayMeue();
	void displayNotMenu();
	bool isHavaSaveFile();

    
};


#endif /* defined(__bug__GameManager__) */

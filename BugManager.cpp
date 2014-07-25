//
//  BugManager.cpp
//  bug
//
//  Created by pat on 13-9-12.
//
//

#include "BugManager.h"

BugManager::BugManager():m_interval(3)
, m_bugList(NULL){
    
}

BugManager::~BugManager(){
    GameManager::getInstance()->removeLogicObserver(this);
}

bool BugManager::init(){
    GameManager::getInstance()->addLogicObserver(this);
    m_bugFactory = new BugFactory();
    this->schedule(schedule_selector(BugManager::makeRandomBug), m_interval);
    makeRandomBug(0.0f);
    return true;
}

CCPoint BugManager::makeRandomPoint(){
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    float randX = CCRANDOM_0_1()*(int)s.width;
	float randY = CCRANDOM_0_1()*(int)s.height;
    CCPoint p = CCPointMake(randX, randY);
    CCRect rect = CCRectMake(s.width/2-100, s.width/2-80, 200, 160);
    if(rect.containsPoint(p)){
        p = makeRandomPoint();
    }
    return p;
}

void BugManager::makeRandomBug(float t){
    CCPoint p = makeRandomPoint();
    createBugToPoint(p);
    //return NULL;
}

void BugManager::createBugToPoint(CCPoint point){
    BaseBug* bug = m_bugFactory->randomMakeABug();
	bug->setScale(1.2);
    bug->setPosition(point);
    this->addChild(bug);
}

void BugManager::removeBug(BaseBug *bug){
    this->removeChild(bug,true);
    bug->cleanup();
}

void BugManager::logicHandler(LogicEventStruct event){
    switch (event.name) {
        case BUG_MOVE_END:
            
            removeBug((BaseBug*)event.data);
            GameManager::getInstance()->gameOver();
            break;
        case BUG_DEATH:
            CCLOG("Receive BUG_DEATH message in BugManager");
            removeBug((BaseBug*)event.data);
            //GameManager::getInstance()->getScoreManager()->addScore(2);
            break;
        default:
            break;
    }
}

CCArray* BugManager::getBugList(){
    return NULL;
}
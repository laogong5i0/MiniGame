//
//  ScoreManager.cpp
//  bug
//
//  Created by pat on 13-10-15.
//
//

#include "ScoreManager.h"


USING_NS_CC;

ScoreManager::ScoreManager():m_score(0){
    init();
}

ScoreManager::~ScoreManager(){
    CC_SAFE_RELEASE(this);
    //CC_SAFE_DELETE(this);
}

void ScoreManager::updateScore(){
    char tem[20];
    sprintf(tem, "Score: %d", m_score);
    m_scoreSprite->setString(tem);
}

void ScoreManager::init(){
    m_scoreSprite = CCLabelBMFont::create("Score: 0", "arial-unicode-26.fnt");
	m_scoreSprite->retain();
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    m_scoreSprite->setPosition(ccp(s.width/2, s.height-40));
}

int ScoreManager::getScore(){
    return m_score;
}
void ScoreManager::setScore(int score){
    m_score = score;
    updateScore();
}
void ScoreManager::addScore(int value){
    m_score +=value;
    updateScore();
}

void ScoreManager::addScoreTo(cocos2d::CCLayer *layer, cocos2d::CCPoint& _p){
    CCAssert(layer!=NULL, "The score sprite must be non-nil");
    m_scoreSprite->setPosition(_p);
    layer->addChild(m_scoreSprite);
    m_scoreSprite->retain();
}

int ScoreManager::getHeightScore()
{
	return CCUserDefault::sharedUserDefault()->getIntegerForKey("HeightScore");
}
void ScoreManager::setHeightScore(int score)
{
	CCUserDefault::sharedUserDefault()->setIntegerForKey("HeightScore", score);
	CCUserDefault::sharedUserDefault()->flush();
}
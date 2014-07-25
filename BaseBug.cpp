//
//  BaseBug.cpp
//  bug
//
//  Created by pat on 13-9-9.
//
//

#include "BaseBug.h"
#include "SimpleAudioEngine.h"

#define EACH_BUG_SCORE 2
#define TAG_BUG_SCORE 1

BaseBug::BaseBug():m_HP(6)
, m_speed(40)
, m_fileName("bug-1.ccbi")
, m_bug(NULL)
, m_actionTag(1){
    //init();
}

BaseBug::~BaseBug(){
    CCAssert(m_bug, "The bug is a NULL object");
    m_bug->release();
}


BaseBug* BaseBug::create(float hp, float speed, CCString fileName){
    BaseBug *pSprite = new BaseBug();
    if (pSprite && pSprite->init(hp, speed, fileName))
    {
        pSprite->autorelease();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

bool BaseBug::init(float hp, float speed, CCString fileName){
    m_HP = hp;
    m_speed = speed;
    m_fileName = fileName;
    return CCSprite::init();
}

void BaseBug::loaderBug(CCPoint point){
    CCBAnimationManager* pAnimationManager = NULL;
    CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader("BaseBugCCBI", BaseBugCCBILoader::loader());
    
    cocos2d::extension::CCBReader* ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    CCNode* node = ccbReader->readNodeGraphFromFile(m_fileName.m_sString.c_str(), this, &pAnimationManager);
    ccbReader->autorelease();
    m_bug = (BaseBugCCBI*)node;
    m_bug->setAnimationManager(pAnimationManager);
    this->addChild(m_bug);
    
    
}

void BaseBug::moveToPoint(cocos2d::CCPoint point){
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    //CCNode* parent = this;//(CCSprite*)this->getParent();
    float _xSpace = abs(this->getPositionX()-size.width/2);
    float _ySpace = abs(this->getPositionY()-size.height/2);
    float space = sqrt(_xSpace*_xSpace+_ySpace*_ySpace);
    CCActionInterval* action = CCMoveTo::create(space/m_speed, CCPointMake(size.width/2, size.height/2));
    //action->setTag(1);
    CCFiniteTimeAction* finiteAction = CCSequence::create(action, CCCallFunc::create(this, callfunc_selector(BaseBug::onMoveEnd)), NULL);
    this->runAction(finiteAction);
    finiteAction->setTag(m_actionTag);
}

void BaseBug::stopMove(){
    this->stopActionByTag(m_actionTag);
	
}

void BaseBug::onMoveEnd(){
    LogicEventStruct event;
    event.name = BUG_MOVE_END;
    event.data = this;
    GameManager::getInstance()->sendLogicNotify(event);
}

void BaseBug::byPress(){
    m_bug->setScale(1.0f);
    CCActionInterval* action = CCScaleBy::create(0.05f, 0.9f);
    CCActionInterval* actionReverse = action->reverse();
    CCFiniteTimeAction* finiteAction = CCSequence::create(action, actionReverse,NULL);
    m_bug->runAction(finiteAction);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("press.mp3");
    showFlower();
}

void BaseBug::rotationToPoint(cocos2d::CCPoint point){
    CCSprite* parent = m_bug;//(CCSprite*)this->getParent();
    float ratian = atan2f(point.x- parent->getPositionX(), point.y - parent->getPositionY());
    parent->setRotation(ratian*180/M_PI);
}

bool BaseBug::hasDie(){
    if(m_HP<=0)
        return true;
    return false;
}

bool BaseBug::containsTouchLocation(cocos2d::CCTouch * pTouch){
    CC_ASSERT(m_bug);
    CCSize s = m_bug->getContentSize();
    CCRect rect = CCRectMake(-s.width/2, -s.height/2, s.width, s.height);
    CCPoint nodePoint = convertTouchToNodeSpaceAR(pTouch);
    return rect.containsPoint(nodePoint);
}


void BaseBug::onEnter(){
    //接收对象, 优先级，ture时阻止其他类的move and end
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, CC_MAX_TOUCHES,true);
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    CCPoint p = ccp(s.width/2, s.height/2);
    p = convertToNodeSpace(p);
    loaderBug(p);
    rotationToPoint(p);
    moveToPoint(p);
    CCSprite::onEnter();
}

void BaseBug::onExit(){
    
}

bool BaseBug::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *event){
    if(hasDie()) return false;
    if(containsTouchLocation(pTouch)){
        this->m_HP -= 1;
        byPress();
		this->stopMove();
        if(hasDie()){
			GameManager::getInstance()->getScoreManager()->addScore(EACH_BUG_SCORE);
			addScoreAnimation();
            m_bug->playAnimation("death");
        }
        return true;
    }
    return false;
}

void BaseBug::ccTouchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *event){
    
}

void BaseBug::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *event){
    if(!hasDie()){
		CCSize s = CCDirector::sharedDirector()->getWinSize();
		CCPoint p = convertToNodeSpace(ccp(s.width/2, s.height/2));
		moveToPoint(p);
	}
}

void BaseBug::showFlower(){
    CCString filename = "flower-0.ccbi";
    CCNodeLoaderLibrary* loaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    loaderLibrary->registerCCNodeLoader("CCParticleSystemQuad", CCParticleSystemQuadLoader::loader());
    cocos2d::extension::CCBReader* ccbReader = new cocos2d::extension::CCBReader(loaderLibrary);
    CCNode* node = ccbReader->readNodeGraphFromFile(filename.m_sString.c_str());
    CCParticleSystemQuad* emitter = (CCParticleSystemQuad*) node;
    this->addChild(emitter);
}

void BaseBug::addScoreAnimation()
{
	CCString *str = CCString::createWithFormat("+%d", EACH_BUG_SCORE);
	CCLabelTTF* textStr = CCLabelTTF::create(str->getCString(), "Arial", 40);
	textStr->setPosition(ccp(this->getPositionX(), this->getPositionY()+40));
	textStr->setColor(ccRED);
	this->getParent()->addChild(textStr);
	textStr->setTag(TAG_BUG_SCORE);
	CCActionInterval* action = CCMoveTo::create(0.8f, CCPointMake(this->getPositionX(), this->getPositionY()+80));
	CCActionInterval* fadeOut = CCFadeOut::create(0.8f);
	CCFiniteTimeAction* action2 = CCSequence::create(CCMoveTo::create(0.8f, CCPointMake(this->getPositionX(), this->getPositionY()+80)), 
		CCCallFunc::create(this, callfunc_selector(BaseBug::scoreAnimationEnd)), 
		NULL);
	CCAction* act = CCSpawn::create( fadeOut, action2, NULL);

	textStr->runAction(act);
	
}

void BaseBug::scoreAnimationEnd()
{
	this->getParent()->removeChildByTag(TAG_BUG_SCORE, true);
}

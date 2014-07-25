//
//  LoadingLayer.cpp
//  bug
//
//  Created by pat on 13-3-1.
//
//

#include "LoadingLayer.h"
#include "MenuLayer.h"
#include "MenuScene.h"
#include "ConfigMenu.h"
#include "SimpleAudioEngine.h"
#include "GameMarcos.h"

USING_NS_CC;
USING_NS_CC_EXT;

LoadingLayer::LoadingLayer():
background(NULL),
scrollBar(NULL),
scrollBarBG(NULL),
scrollTxt(NULL),
loadNode(NULL),
hasTouchMove(false),
loadProgress(NULL),
pointBegan(ccp(0, 0)),
criticalValue(500){
	CCLOG("loadinglayer();");
	this->setTouchEnabled(true);
}

LoadingLayer::~LoadingLayer(){
	
}

bool LoadingLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
	CCLOG("cc touch began");
	pointBegan = CCDirector::sharedDirector()->convertToUI(pTouch->getLocation());

	/*static char str;
	sprintf(&str, "touch began point: %f, %f", pTouch->getLocation().x, pTouch->getLocation().y);
	CCLOG("%s", &str);
	CCPoint touchP = CCDirector::sharedDirector()->convertToUI(pTouch->getLocation());
	sprintf(&str, "touch began to UI point: %f, %f", touchP.x, touchP.y);
	CCLOG("%s", &str);*/
	
	return true;
}

void LoadingLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	float bWidth = background->getContentSize().width;
	CCSize frameSize = CCDirector::sharedDirector()->getOpenGLView()->getFrameSize();
	float space = (bWidth/2 - frameSize.width);
	
	hasTouchMove = true;
	CCPoint backgroundP = background->getPosition();
	
	
	CCPoint touchP = CCDirector::sharedDirector()->convertToUI(pTouch->getLocation());
	CCPoint p = ccp(backgroundP.x + (pointBegan.x - touchP.x)*-1, backgroundP.y);
	pointBegan = touchP;
	//CCString* s = CCString::createWithFormat("touch move point: %f %f", p.x, (background->getContentSize().width-visibleSize.width)-1);
	//CCLOG(s->getCString());
	if(p.x>=0 || p.x<(background->getContentSize().width-visibleSize.width)*-1) return;
	background->setPosition(p);
}

void LoadingLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
	if(!hasTouchMove){
		CCLOG("cc touch ended");
	}else{
		hasTouchMove = false;
	}
}


void LoadingLayer::ccTouchesBegan(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent){
	//CCLOG("cc touches began");
}
void LoadingLayer::ccTouchesEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent){
	//CCLOG("cc touches ended");
}
void LoadingLayer::ccTouchesMoved(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent){
	//CCLOG("cc touiches moved");
}

void LoadingLayer::openTest(const char * pCCBFileName, const char * pCCNodeName, CCNodeLoader * pCCNodeLoader) {
	CCLOG("open test");
}

void LoadingLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader) {
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCLOG("on node loaded");
	this->setTouchEnabled(true);
	this->setTouchMode(kCCTouchesOneByOne);
	this->schedule(schedule_selector(LoadingLayer::makeMenu), 0.01);
	
	loadNode->removeChild(scrollBar, false);
	loadProgress = CCProgressTimer::create(scrollBar);
	this->loadNode->addChild(loadProgress);
	loadProgress->setType(kCCProgressTimerTypeBar);

	loadProgress->setMidpoint(ccp(0, 0));
	loadProgress->setBarChangeRate(ccp(1, 0));
	//loadProgress->setPosition(scrollBarBG->getParent()->getPosition());
}


SEL_MenuHandler LoadingLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, CCString * pSelectorName) {
	CCLOG("on resolve ccb ccMenuItemSelector");
	
	return NULL;
}

SEL_CCControlHandler LoadingLayer::onResolveCCBCCControlSelector(CCObject * pTarget, CCString * pSelectorName) {
	CCLOG("on resolve ccb ccontrol selector");
	
	return NULL;
}

bool LoadingLayer::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, cocos2d::CCString * pMemberVariableName, cocos2d::CCNode * pNode){
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "background", CCSprite *, this->background);
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scrollBar", CCSprite *, this->scrollBar);
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scrollTxt", CCLabelTTF *, this->scrollTxt);
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scrollBarBG", CCSprite *, this->scrollBarBG);
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "loadNode", CCNode *, this->loadNode);
	return true;
}

void LoadingLayer::moveBG(){

	CCPoint p = background->getPosition();
	background->runAction(CCMoveTo::create(2, ccp(28,p.y)));
}

long LoadingLayer::getCurrentTime(){
	struct cc_timeval val;
	CCTime::gettimeofdayCocos2d(&val, NULL);
	return val.tv_sec*1000 + val.tv_usec*1000;
}
void LoadingLayer::makeMenu(float t){
	float percent = loadProgress->getPercentage()+2;
	//static char str;
	//sprintf(&str, "Loading... %f\%", percent);
	//scrollTxt->setString(&str);
	loadProgress->setPercentage(percent);

	if(percent>80){
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("tinyapple.mp3");
		loadProgress->setPercentage(90);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("press.mp3");
		loadProgress->setPercentage(98);
	}
	percent +=2;
	if(percent>=100){
		this->unschedule(schedule_selector(LoadingLayer::makeMenu));
		this->removeChild(loadNode, true);
		//this->removeChild(scrollBarBG->getParent(), true);
		this->removeChild(scrollTxt, true);
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		CCLabelTTF* label = CCLabelTTF::create("Skip", "arial", 50);
		CCMenuItemLabel* menuItem = CCMenuItemLabel::create(label, this, menu_selector(LoadingLayer::skipHandler));
		CCMenu* menu = CCMenu::create();
		menu->addChild(menuItem);
		this->addChild(menu);
		menu->setPosition(ccp(visibleSize.width, 50));
		
		CCString* str = CCString::createWithFormat("current percent: %d", percent);
		//static char printfSTR;
		//sprintf(&printfSTR, "printf %f === %f -- %f", space, frameSize.width, bWidth);
		//background->setPosition(p);
		//CCLOG("cc touch moved -- %s", &printfSTR);
		
		//ConfigMenu *configMenu = ConfigMenu::create();
		//this->addChild(configMenu);

		GameManager::getInstance()->isHavaSaveFile();
		if(CCUserDefault::sharedUserDefault()->getBoolForKey(CONFIG_KEY_HAS_MUSIC)){
			GameManager::getInstance()->playerBackgroundMusic();
		}
	}
	
}
void LoadingLayer::skipHandler(CCObject* object){
	CCScene * menuScene = new MenuScene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
	
	//GameManager::getInstance()->displayMeue();

}
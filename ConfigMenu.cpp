#include "ConfigMenu.h"
#include "MaskLayer.h"
#include "GameManager.h"
#include "GameMarcos.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include <string>
#include "../proj.android/jni/hellocpp/JniAPI.h"
#endif

bool ConfigMenu::init(){
	if(!CCLayer::init()){
		return false;
	}
	CCDirector* director = CCDirector::sharedDirector();
	this->setContentSize(director->getWinSize());

	MaskLayer* _mask = MaskLayer::create();
	this->addChild(_mask);
	_mask->setOpacity(200);

	makeMenu();
	return true;
}

void ConfigMenu::makeMenu(){
	CCMenuItemFont::setFontSize(50);
	CCMenuItemFont::setFontName("Arial");


	//CCMenuItemToggle* music = CCMenuItemToggle::createWithTarget(this, menu_selector(ConfigMenu::musicMenuCallback), 
		//CCMenuItemFont::create("Music OFF"),
		//CCMenuItemFont::create("Music ON"), NULL);
	CCMenuItemToggle* music = CCMenuItemToggle::createWithTarget(this, menu_selector(ConfigMenu::musicMenuCallback),
		CCMenuItemLabel::create(CCLabelBMFont::create("Music OFF", "arial-unicode-26.fnt", 300)), 
		CCMenuItemLabel::create(CCLabelBMFont::create("Music ON", "arial-unicode-26.fnt", 300)), NULL);
	
	CCLabelBMFont* txtShare = CCLabelBMFont::create("Share", "arial-unicode-26.fnt", 300);
	//CCMenuItemFont* share = CCMenuItemFont::create("Share", this, menu_selector(ConfigMenu::shareMenuCallback));
	//CCLabelTTF* d = CCLabelTTF::create("Share", "Arial", 30);
	CCMenuItemLabel* share = CCMenuItemLabel::create(txtShare, this, menu_selector(ConfigMenu::shareMenuCallback));
	music->setPosition(ccp(0,-60));
	share->setPosition(ccp(0, music->getContentSize().height+music->getPositionY()+20));
	share->setScale(2);
	music->setScale(2);
	CCMenu *menu = CCMenu::create(music, share, NULL);
	//menu->setPosition(ccp(400,0));
	menu->setOpacity(kCCMenuHandlerPriority);
	this->addChild(menu);
	if(!CCUserDefault::sharedUserDefault()->getBoolForKey(CONFIG_KEY_HAS_MUSIC)){
		music->setSelectedIndex(1);
	}else{
		music->setSelectedIndex(0);
	}

}

void ConfigMenu::musicMenuCallback( CCObject* sender )
{
	CCMenuItemToggle* target = (CCMenuItemToggle*) sender;
	int item = target->getSelectedIndex();//item为0时，当前背景音乐是关闭的;
	if(item==0){
		GameManager::getInstance()->playerBackgroundMusic();
	}else{
		GameManager::getInstance()->stopBackgroundMusic();
	}
}

void ConfigMenu::shareMenuCallback( CCObject* sender )
{
	CCLOG("share click");
	screenshot();
}

std::string ConfigMenu::getSDCard()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	std::string card = getSDCardJni();
	return card;
#endif

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	std::string card = CCFileUtils::sharedFileUtils()->getWriteablePath();
	return card;
#endif
}

void ConfigMenu::share()
{
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
	useIntentShare();
#endif
}


void ConfigMenu::screenshot()
{
	std::string sdcard = getSDCard();
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	const char* imgName = "/bug_screenshot.jpg";
	sdcard = sdcard.append(imgName);
	CCRenderTexture* pScreen = CCRenderTexture::create(size.width, size.height);
	CCScene* pTempScene = CCDirector::sharedDirector()->getRunningScene();
	pScreen->begin();
	//pTempScene->visit();
	pTempScene->getChildByTag(TAG_RUNNING_LAYER)->visit();
	pScreen->end();
	pScreen->saveToFile(sdcard.c_str());
	CC_SAFE_DELETE(pScreen);
	share();
	CCLOG("sdcard %s", sdcard.c_str());
}




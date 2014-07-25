#ifndef __BUG_CONFIG_MENU__
#define __BUG_CONFIG_MENU__

#include "cocos2d.h"

USING_NS_CC;

class ConfigMenu : public CCLayer{
	
public:
	virtual bool init();
	//virtual void onEnter();
	//virtual void registerWithTouchDispatcher();
	//virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
	//virtual void ccTouchMoved(CCTouch* pTouch, CCEvent* pEevnt);
	//virtual void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);

	void makeMenu();
	void musicMenuCallback(CCObject* sender);
	void shareMenuCallback(CCObject* sender);
	CREATE_FUNC(ConfigMenu);
	std::string getSDCard();
	void screenshot();
	void share();

};

#endif
#include "MaskLayer.h"


MaskLayer::MaskLayer():_bg(NULL)
{

}


bool MaskLayer::init()
{
	if(!CCLayer::init()){
		return false;
	}
	crawBG();
	return true;
}

void MaskLayer::registerWithTouchDispatcher()
{
	CCTouchDispatcher* dispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
	dispatcher->addTargetedDelegate(this, kCCMenuHandlerPriority, true);
}

void MaskLayer::onEnter()
{
	CCLayer::onEnter();
	this->setTouchEnabled(true);
}

bool MaskLayer::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	CCLOG("The Mask layer was be click");
	return true;
}

void MaskLayer::crawBG()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	_bg = CCLayerColor::create(ccc4(0, 0, 0, 127));
	_bg->setContentSize(visibleSize);
	this->addChild(_bg);
}

void MaskLayer::setBackGroundColor( const ccColor3B& var )
{
	_bg->setColor(var);
}

void MaskLayer::setOpacity( GLubyte opacity )
{
	_bg->setOpacity(opacity);
}




#ifndef __MASK_LAYER__
#define __MASK_LAYER__

#include "cocos2d.h"

USING_NS_CC;

class MaskLayer : public CCLayer
{
public:

	MaskLayer();

	virtual bool init();
	virtual void registerWithTouchDispatcher();
	virtual void onEnter();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);

	void crawBG();
	void setBackGroundColor(const ccColor3B& var);
	virtual void setOpacity(GLubyte opacity);
	CREATE_FUNC(MaskLayer);
private:
	CCLayerColor* _bg;
};

#endif
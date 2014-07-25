//
//  BaseBug.h
//  bug
//
//  Created by pat on 13-9-9.
//
//

#ifndef __bug__BaseBug__
#define __bug__BaseBug__

#include <iostream>


#include "cocos2d.h"
#include "cocos-ext.h"
#include "LogicObserver.h"
#include "GameEnum.h"
//#include "GameManager.h"
#include "BaseBugCCBI.h"
#include "BaseBugCCBILoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

//class BaseBugCCBILoader;
class BaseBugCCBI;

class BaseBug : public CCSprite
, public CCTargetedTouchDelegate
{
    CCString m_fileName;
    float m_HP;
    float m_speed;
    BaseBugCCBI* m_bug;
    int m_actionTag;
    
    void showFlower();
public:
    static BaseBug* create(float hp, float speed, CCString fileName);
    BaseBug();
    virtual ~BaseBug();
    bool init(float hp, float speed, CCString fileName);
    virtual void loaderBug(CCPoint point);
    void moveToPoint(CCPoint point);
    void stopMove();
    void onMoveEnd();
    void byPress();
    void rotationToPoint(CCPoint point);
    bool hasDie();
    bool containsTouchLocation(cocos2d::CCTouch * pTouch);

    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch * pTouch, CCEvent * event);
    virtual void ccTouchMove(CCTouch* pTouch, CCEvent * event);
    virtual void ccTouchEnded(CCTouch * pTouch, CCEvent * event);

	void addScoreAnimation();
	void scoreAnimationEnd();
    
};

#endif /* defined(__bug__BaseBug__) */

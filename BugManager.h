//
//  BugManager.h
//  bug
//
//  Created by pat on 13-9-12.
//
//

#ifndef __bug__BugManager__
#define __bug__BugManager__

#include <iostream>
#include "cocos2d.h"
#include "BaseBug.h"
#include "LogicObserver.h"
#include "BugFactory.h"

USING_NS_CC;

class BugManager : public CCNode
, LogicObserver{
    float m_interval;
    CCArray* m_bugList;
    BugFactory* m_bugFactory;
public:
    BugManager();
    ~BugManager();
    bool init();
    CCPoint makeRandomPoint();
    void makeRandomBug(float t);
    void createBugToPoint(CCPoint point);
    void removeBug(BaseBug* bug);
    CREATE_FUNC(BugManager);
    
    virtual void logicHandler(LogicEventStruct event);
    CCArray* getBugList();
};

#endif /* defined(__bug__BugManager__) */

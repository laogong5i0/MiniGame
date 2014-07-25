//
//  LogicObserver.h
//  bug
//
//  Created by pat on 13-9-5.
//
//

#ifndef __bug__LogicObserver__
#define __bug__LogicObserver__

#include <iostream>
#include "cocos2d.h"
#include "GameEnum.h"

class LogicObserver;

USING_NS_CC;
struct LogicObserverStruct{
    LogicObserver* logicObs;
};

struct LogicEventStruct{
    LogicEventEnum name;
    CCObject* data;
};

class LogicObserver{
public:
    virtual void logicHandler(LogicEventStruct event)=0;
};
#endif /* defined(__bug__LogicObserver__) */

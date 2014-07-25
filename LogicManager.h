//
//  LogicManager.h
//  bug
//
//  Created by pat on 13-9-5.
//
//

#ifndef __bug__LogicManager__
#define __bug__LogicManager__

#include <iostream>
#include "cocos2d.h"
#include "LogicObserver.h"
#include <vector>

USING_NS_CC;



class LogicObserver;

class LogicManager : public CCObject {
    LogicManager();
    //CCArray* arrObserver;
    std::vector<LogicObserverStruct> vectorObserver;
public:
    static LogicManager* create();
    virtual void addObserver(LogicObserver* observer);
    virtual void removeObserver(LogicObserver* observer);
    virtual void notify(LogicEventStruct evetn);
};

#endif /* defined(__bug__LogicManager__) */

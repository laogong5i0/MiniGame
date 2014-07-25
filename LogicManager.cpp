//
//  LogicManager.cpp
//  bug
//
//  Created by pat on 13-9-5.
//
//

#include "LogicManager.h"

LogicManager::LogicManager(){
    
}


LogicManager* LogicManager::create(){
    LogicManager* instance = new LogicManager();
    instance->retain();
    return instance;
}

void LogicManager::addObserver(LogicObserver *observer){
    //arrObserver->addObject(observer);
    LogicObserverStruct structLogicObserver;
    structLogicObserver.logicObs = observer;
    vectorObserver.push_back(structLogicObserver);
}

void LogicManager::removeObserver(LogicObserver *observer){
    for (std::vector<LogicObserverStruct>::iterator i = vectorObserver.begin(); i!=vectorObserver.end(); i++) {
        LogicObserver* lb = i->logicObs;
        if(lb == observer){
            vectorObserver.erase(i);
            return;
        }
    }
}

void LogicManager::notify(LogicEventStruct event){
    for(std::vector<LogicObserverStruct>::iterator i= vectorObserver.begin(); i!=vectorObserver.end(); i++){
        LogicObserver* lb = i->logicObs;
        lb->logicHandler(event);
    }
}
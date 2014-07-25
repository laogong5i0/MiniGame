//
//  LoadingLayerLoader.h
//  bug
//
//  Created by pat on 13-3-1.
//
//

#ifndef __bug__LoadingLayerLoader__
#define __bug__LoadingLayerLoader__

#include <iostream>
#include "LoadingLayer.h"

class CCBReader;

class LoadingLayerLoader : public cocos2d::extension::CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LoadingLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(LoadingLayer);
    
};

#endif /* defined(__bug__LoadingLayerLoader__) */

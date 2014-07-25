//
//  MenuLayerLoader.h
//  bug
//
//  Created by pat on 13-3-4.
//
//

#ifndef __bug__MenuLayerLoader__
#define __bug__MenuLayerLoader__

#include <iostream>
#include "MenuLayer.h"

class CCBReader;

class MenuLayerLoader : public cocos2d::extension::CCLayerLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuLayer);
    
};


#endif /* defined(__bug__MenuLayerLoader__) */

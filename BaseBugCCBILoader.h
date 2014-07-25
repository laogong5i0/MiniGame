//
//  BaseBugCCBILoader.h
//  bug
//
//  Created by pat on 13-9-13.
//
//

#ifndef __bug__BaseBugCCBILoader__
#define __bug__BaseBugCCBILoader__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "BaseBugCCBI.h"

class CCBReader;

class BaseBugCCBILoader : public cocos2d::extension::CCSpriteLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BaseBugCCBILoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(BaseBugCCBI);
    
};

#endif /* defined(__bug__BaseBugCCBILoader__) */

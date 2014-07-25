//
//  LoadingScene.h
//  bug
//
//  Created by pat on 13-3-1.
//
//

#ifndef __bug__LoadingScene__
#define __bug__LoadingScene__

#include <iostream>
#include "LoadingLayerLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

class LoadingScene : public CCScene{
public:
    LoadingScene();
    bool init();
	void menucall(CCObject* sender);
};

#endif /* defined(__bug__LoadingScene__) */

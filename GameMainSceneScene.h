//
//  GameMainSceneScene.h
//  bug
//
//  Created by pat on 13-3-6.
//
//

#ifndef __bug__GameMainSceneScene__
#define __bug__GameMainSceneScene__

#include <iostream>
#include "GameMainSceneLayer.h"

class GameMainSceneScene : public CCScene
{
public:
    CREATE_FUNC(GameMainSceneScene);
    virtual bool init();
};

#endif /* defined(__bug__GameMainSceneScene__) */

//
//  BugFactory.h
//  bug
//
//  Created by pat on 13-9-30.
//
//

#ifndef __bug__BugFactory__
#define __bug__BugFactory__

#include <iostream>

class BaseBug;

enum BUG_TYPE{
    BUG_1,
    BUG_2
};

class BugFactory {
    float m_HP;
public:
	BaseBug* randomMakeABug();
    BaseBug* createBug(BUG_TYPE type);
};

#endif /* defined(__bug__BugFactory__) */
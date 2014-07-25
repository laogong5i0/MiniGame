//
//  BugFactory.cpp
//  bug
//
//  Created by pat on 13-9-30.
//
//

#include "BugFactory.h"
#include "BaseBug.h"

BaseBug* BugFactory::createBug(BUG_TYPE type){
    switch (type) {
        case BUG_1:
            return BaseBug::create(4, 80, "bug-0.ccbi");
            break;
        case BUG_2:
            return BaseBug::create(5, 158, "bug-1.ccbi");
        default:
            break;
    }
	return NULL;
}

BaseBug* BugFactory::randomMakeABug()
{
	int length = BUG_2;
	float type = CCRANDOM_0_1()*(length+1);
	BaseBug* bug;
	if((int)type==1)
		bug = createBug(BUG_1);
	else 
		bug = createBug(BUG_2);
	
	return bug;
}

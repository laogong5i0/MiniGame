//
//  ScoreManager.h
//  bug
//
//  Created by pat on 13-10-15.
//
//

#ifndef __bug__ScoreManager__
#define __bug__ScoreManager__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class ScoreManager : public CCObject {
	int m_score;
	CCLabelBMFont* m_scoreSprite;
	
	void updateScore();
public:
	ScoreManager();
	~ScoreManager();
	void init();
	int getScore();
	void setScore(int score);
	void addScore(int score);
	
	void addScoreTo(CCLayer* layer, CCPoint& _p);

	int getHeightScore();
	void setHeightScore(int score);
};

#endif /* defined(__bug__ScoreManager__) */

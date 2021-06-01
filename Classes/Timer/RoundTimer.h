#ifndef _GAME_TIMER_H_
#define _GAME_TIMER_H_

#include "cocos2d.h"


USING_NS_CC;

class RoundTimer :public cocos2d::Node
{
public:
	RoundTimer();

	virtual ~RoundTimer();

	static RoundTimer* create(float time);

	void update(float delta);

	bool init(float time);

private:
<<<<<<< HEAD
	float pTime = 100;
	cocos2d::Label* label;
	friend class scene1;
	friend class Chess;
=======
	float pTime;
	cocos2d::Label* label;
>>>>>>> lx
};

#endif
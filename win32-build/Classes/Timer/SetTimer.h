#pragma once
#include "cocos2d.h"
USING_NS_CC;
class SetTimer :public Layer
{
public:
	int oldTime;
	int min;
	int sec;
	virtual void update(float dt);
	static Layer* createSetTimer();
	virtual bool init();
	CREATE_FUNC(SetTimer);
};


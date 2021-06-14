#pragma once
#include "cocos2d.h"
#include "Equipment.h"
USING_NS_CC;
class Knife :public Equipment
{
public:
	CREATE_FUNC(Knife);
	static Knife* createKnife();
};


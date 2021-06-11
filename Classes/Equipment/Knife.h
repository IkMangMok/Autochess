#pragma once
#include "cocos2d.h"
#include "Equipment.h"
USING_NS_CC;
class Knife:public Equipment
{
protected:


public:

	/*创建相关函数*/
	CREATE_FUNC(Knife);
	static Knife* createKnife();

	/*对棋子进行装备加成*/
	//virtual void EquipToChess(Chess* Owner);
};


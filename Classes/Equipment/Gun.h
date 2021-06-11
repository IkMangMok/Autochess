#pragma once
#include "cocos2d.h"
#include "Equipment.h"

USING_NS_CC;
class Gun:public Equipment
{
protected:


public:

	/*创建相关函数*/
	CREATE_FUNC(Gun);
	static Gun* createGun();

	/*对棋子进行装备加成*/
	//virtual void EquipToChess(Chess* Owner);
};


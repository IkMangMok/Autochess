#pragma once
#include "cocos2d.h"
#include "Chess/Chess1.h"

USING_NS_CC;

enum class EquipmentType
{
	None,
	Gun,          /* 枪 */
	Knife         /* 刀 */
	           
	//...
};
class Equipment :public Sprite
{
protected:


	float x_in_package = 0;       //进入战斗时的位置
	float y_in_package = 0;

	bool equiped_or_not = 0;      //是否装备

	int type ;

public:
	virtual void EquipToChess(Chess* Owner) = 0;    //对棋子进行加成(a pure virtual func)

private:
	Chess* OwnerChess = NULL;
	float SearchDistance = 30;

	friend class scene1;
	friend class Package;
};


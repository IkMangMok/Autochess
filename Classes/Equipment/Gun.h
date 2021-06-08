#pragma once
#include "cocos2d.h"
#include "Equipment.h"

USING_NS_CC;

class Gun :public Equipment
{
protected:
	int addAttackDistance = 20;  //攻击距离
	int addHealthLimit = 0;     //生命上限
	int addHealth = 0;          //生命值
	int addArmor = 0;        //护甲
	float addAttackSpeed = 0.1f;  //攻击速度
	int addDamage = 5;     //攻击力
public:
	CREATE_FUNC(Gun);
	static Gun* createGun();

	virtual void EquipToChess(Chess* owner);    //加成（装备）


private:

};
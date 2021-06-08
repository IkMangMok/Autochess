#pragma once
#include "cocos2d.h"
#include "Equipment.h"

USING_NS_CC;

class Knife :public Equipment
{
protected:
	int addAttackDistance = 5;  //攻击距离
	int addHealthLimit = 0;     //生命上限
	int addHealth = 0;          //生命值
	int addArmor = 0;        //护甲
	float addAttackSpeed = 0.1f;  //攻击速度
	int addDamage = 10;     //攻击力
public:
	CREATE_FUNC(Knife);
	static Knife* createKnife();

	virtual void EquipToChess(Chess* owner);    //加成（装备）
	//virtual void RemoveFrom(Chess* owner);  //取消加成（卸装时用）

private:

};
#pragma once

#define GUN 1
#define KNIFE 2

#include "cocos2d.h"
<<<<<<< HEAD
#include "Chess/Chess.h"
=======
>>>>>>> lx

USING_NS_CC;

enum class EquipmentType
{
	None,
	Gun,
	Knife
};

class Equipment :public Sprite
{
protected:



	/*属性加成设定值*/
	int addAttackDistance; //攻击距离
	int addHealthLimit;    //生命上限
	int addHealth;         //当前生命值
	int addArmor;            //护甲
	float addAttackSpeed; //攻速
	int addDamage;          //攻击力

public:
	/*对棋子进行装备加成*/
<<<<<<< HEAD
	virtual void EquipToChess(Chess* Owner);
=======
	int getaddAttackDistance(){ return addAttackDistance; } //攻击距离
	int getaddHealthLimit() { return addHealthLimit; };    //生命上限
	int getaddHealth() { return addHealth; };         //当前生命值
	int getaddArmor() { return addArmor; };            //护甲
	float getaddAttackSpeed() { return addAttackSpeed; }; //攻速
	int getaddDamage() { return addDamage; };          //攻击力
>>>>>>> lx
	int type;//装备类型
private:
	//Chess* OwnerChess = NULL;
	float SearchDistance = 30;         //在地图中对装备目标搜索的距离（could be better）

	friend class GameScene;
	friend class Package;
};


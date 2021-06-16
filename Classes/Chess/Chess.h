#pragma once
#include "cocos2d.h"
#include "string"

#include"Timer/RoundTimer.h"

using namespace cocos2d;
using namespace std;

enum ChessType
{
	None = -1,
	sunflower,
	cactus,
	walnut,
	pealauncher,
	mushroom,
	cherrybomb,
	cornshooter,
	cabbagepult,
	//升级后的植物
	upgrade_sunflower,
	upgrade_cactus,
	upgrade_walnut,
	upgrade_pealauncher,
	upgrade_mushroom, 
	upgrade_cherrybomb,
	upgrade_cornshooter, 
	upgrade_cabbagepult
};

class Chess :public Sprite
{
protected:
	/*重要物理属性*/
	float AttackDistance = 100;  //攻击距离
	float HealthLimit = 500;     //生命上限
	float Health = 500;          //生命值
	float Mana = 0;          //法力值
	float ManaOrigin = 0;      //初始法力值
	float ManaLimit = 100;   //法力上限
	float Armor = 0;        //护甲
	float MagicResistance = 0;   //魔法抗性
	float Magic = 1.0f;          //法术强度
	float AttackSpeed = 0.8f;  //攻击速度
	int Damage = 50;     //攻击力
	float HurtRate = 1;   //伤害比率

	int type = None;        //种类
	int star = 1;        //星级
	int CoinsNeeded = 0;    //所需金币
	int SoldCoins = CoinsNeeded; //卖掉所获金币
	int OfPlayer = 0;     //所属玩家

	ccArray* equipment = ccArrayNew(100);   //装备

	/*位置属性*/
	float xtemp = x;      //进入战斗时的位置(地图位置)
	float ytemp = y;

	float x = 0.f;                //真实位置
	float y = 0.f;

	float height = 0; //所带图片的长度和宽度
	float width = 0;

public:
	//virtual bool init();

	/*构造以及位置设定*/
	static Chess* createChess(string picture_name);
	void set(float x1, float y1);
	void set(Point point) {
		x = point.x;
		y = point.y;
	};
	void setTempPosition() { xtemp = x; ytemp = y; }
	const cocos2d::Size getContentSize() { return Size(width, height); }   //获得图片长宽

	/*更新函数*/
	void update(float dt);

	/*相关属性*/
	Chess* AttackTarget = NULL;   //攻击目标
	Sprite* bloodFrame = Sprite::create("BloodFrame.jpg");
	ProgressTimer* Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));

	/*返回与设置属性相关函数*/
	Point getPosition() { return Point(x, y); }
	Point getTempPosition() { return Point(xtemp, ytemp); }   //获得进入战斗时的位置
	int GetAttackDistance() { return AttackDistance; }        //获得攻击距离
	int getType() { return type; }                       //获得类型
	int getCoinsNeeded() { return CoinsNeeded; }        //获取购买价格
	int getSoldCoins() { return SoldCoins; }             //获取卖出价格
	int getPlayer() { return OfPlayer; }           //返回所属玩家
	int getStar() { return star; }                //获取星数
	void setPlayer(int player) { OfPlayer = player; }
	virtual void Attack(float dt);    //攻击
	virtual void Hurted(int Damage);  //受伤

	/*棋子自身功能/性质*/
	virtual void Skill() {};          //技能
	virtual void recover();           //状态复原
	bool Die();                     //判断是否死亡及死亡操作

	/*用于装备修改属性*/
	void ChangeAttackDistance(int value) { AttackDistance += value; }
	void ChangeHealthLimit(int value) { HealthLimit += value; }
	void ChangeHealth(int value) { Health += value; }
	void ChangeArmor(int value) { Armor += value; }
	void ChangeAttackSpeed(float value) { AttackSpeed += value; }
	void ChangeDamage(int value) { Damage += value; }

private:
	RoundTimer* test_timer = RoundTimer::create(5);
	friend class scene1;
};

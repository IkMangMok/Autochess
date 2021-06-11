#pragma once
#include "cocos2d.h"
#include "string"

#include"Timer/RoundTimer.h"

using namespace cocos2d;
using namespace std;

enum ChessType
{
	None = -1,
	walnut,         
	pealauncher,           
	mushroom,       
	sunflower,            
	cactus,
	cherrybomb,
	cornshooter,
	cabbagepult
	//...
};

class Chess :public Sprite {
protected:

	int AttackDistance = 100;  //攻击距离
	int HealthLimit = 500;     //生命上限
	int Health = 500;          //生命值
	int Mana = 0;          //法力值
	int ManaLimit = 100;   //法力上限
	int Armor = 0;        //护甲
	int MagicResistance = 0;   //魔法抗性
	float AttackSpeed = 0.8f;  //攻击速度
	int Damage = 50;     //攻击力


	float xtemp = x;      //进入战斗时的位置(地图位置)
	float ytemp = y;

	float x = 0.f;                //真实位置
	float y = 0.f;

	float height = 0; //所带图片的长度和宽度
	float width = 0;

	int OfPlayer = 0;     //所属玩家
	int CoinsNeeded = 0;    //所需金币
	int star = 0;        //星级
	ccArray* equipment = ccArrayNew(100);   //装备
	
public:
	//virtual bool init();
	Chess* AttackTarget = NULL;   //攻击目标
	static Chess* createChess(string picture_name);
	void set(float x1, float y1);
	void set(Point point) {
		x = point.x;
		y = point.y;
	};
	void setTempPosition() { xtemp = x; ytemp = y; }

	Point getPosition();
	Point getTempPosition(){return Point(xtemp, ytemp);}   //获得进入战斗时的位置

	int getCoinsNeeded() { return CoinsNeeded; }

	virtual void Attack(float dt);    //攻击
	virtual void Hurted(int Damage);  //受伤

	bool Die();                     //判断是否死亡及死亡操作

	int GetAttackDistance();        //获得攻击距离

	const cocos2d::Size getContentSize() { return Size(width, height); }   //获得图片长宽
	virtual void Skill() {};          //技能

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

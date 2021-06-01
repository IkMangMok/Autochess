<<<<<<< HEAD
#pragma once
#include "cocos2d.h"
#include "string"
#include"Timer/RoundTimer.h"
#include"Data/GameData.h"
using namespace cocos2d;
using namespace std;

enum class ChessType
{
	None = -1,
	PeaShooter,         /* 豌豆射手 */
	WallNut,            /* 坚果墙 */
	CabbagePult,        /* 卷心菜投手 */
	Garlic,             /* 大蒜 */
	FirePeaShooter,     /* 火焰豌豆射手 */
	AcidLemonShooter,   /* 强酸柠檬射手 */
	Citron              /* 离子缘 */
	//...
};
class Chess :public Sprite {
protected:

	int AttackDistance = 100;  //攻击距离
	int HealthLimit = 500;     //生命上限
	int Health = 500;          //生命值
	int Armor = 0;        //护甲
	float AttackSpeed = 0.8f;  //攻击速度
	int Damage = 50;     //攻击力

	float x = 0.;           //位置
	float y = 0.;

	float xtemp = x;       //进入战斗时的位置
	float ytemp = y;

	Player* OfPlayer = 0;     //所属玩家
	int CoinsNeeded = 0;    //所需金币
	int star = 0;        //星级
	ccArray* equipment = ccArrayNew(100);   //装备
=======

#include "cocos2d.h"
#include "string"

using namespace cocos2d;
using namespace std;

class Chess :public Sprite {
private:
	int AttackDistance;  //攻击距离
	int Health;          //生命值
	int Armor;           //护甲
	float AttackSpeed;   //攻击速度
	float x = 0.;           //位置
	float y = 0.;
	
>>>>>>> lx
	
public:
	//virtual bool init();
	Chess* AttackTarget = NULL;   //攻击目标
<<<<<<< HEAD
	static Chess* createChess(string picture_name, Point point);
	void set(float x, float y);
	void set(Point point);
	void setTempPosition() { xtemp = x; ytemp = y; }
	Point getPosition();
	Point getTempPosition();   //获得进入战斗时的位置
	virtual void Attack(float dt);    //攻击
	virtual void Hurted(int Damage);  //受伤
	bool Die();                     //判断是否死亡及死亡操作
	int GetAttackDistance();        //获得攻击距离
	void Move(float dt);
	
private:
	RoundTimer* test_timer = RoundTimer::create(5);
	friend class scene1;
=======
	static Chess* createChess(string picture_name, float x, float y);
	void set(float x, float y);
	void set(Point point);
	Point getPosition();
>>>>>>> lx
};

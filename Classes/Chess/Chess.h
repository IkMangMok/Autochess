#pragma once
#include "cocos2d.h"
#include "string"
#include "Data/PlayerData.h"
#include "Timer/RoundTimer.h"
#include "Equipment/EquipmentFile.h"
using namespace cocos2d;
using namespace std;



class Chess :public Sprite {
protected:

	float AttackDistance = 100;  //攻击距离
	float HealthLimit = 500;     //生命上限
	float Health = 500;          //生命值
	float Mana = 0;          //法力值
	float ManaOrigin = 0;      //初始法力值
	float ManaLimit = 100;   //法力上限
	float Armor = 0;        //护甲
	float MagicResistance = 10;   //魔法抗性
	float Magic = 1.0f;          //法术强度
	float AttackSpeed = 0.8f;  //攻击速度
	float TempAttackSpeed = AttackSpeed;
	int Damage = 50;     //攻击力

	float HurtRate = 1;   //伤害比率

	int type = None;        //种类

	float Speed = 6;         //移动速度
	float TempSpeed = Speed; //记录中间速度

	float xtemp = x;      //进入战斗时的位置(地图位置)
	float ytemp = y;

	float x = 0.f;                //真实位置
	float y = 0.f;

	float height = 0; //所带图片的长度和宽度
	float width = 0;
	
	int OfPlayer = 0;     //所属玩家
	int CoinsNeeded = 0;    //所需金币
	int SoldCoins = CoinsNeeded; //卖掉所获金币
	int star = 1;        //星级

	
	
	
public:
	//virtual bool init();
	Chess* AttackTarget = nullptr;   //攻击目标
	Chess();
	bool isMove = 0;
	ccArray* equipment = ccArrayNew(100);   //装备
	string picturename;   //图片名字
	int picturenum;       //图片张数

	static Chess* createChess(string picture_name);
	void set(float x1, float y1);
	void set(Point point) {
		x = point.x;
		y = point.y;
	};
	void setTempPosition() { xtemp = x; ytemp = y; }

	Point getTempPosition(){return Point(xtemp, ytemp);}   //获得进入战斗时的位置
	int getType() { return type; }                       //获得类型
	int getCoinsNeeded() { return CoinsNeeded; }
	int getSoldCoins() { return SoldCoins; }
	int getPlayer() { return OfPlayer; }           //返回所属玩家
	int getStar() { return star; }
	float getHealth() { return Health; }
	void Chess::shootbullet(string picturename, Point deltaPos, Chess* mychess);

	Point getPosition(){ return Point(x,y); }
	float getSpeed() { return Speed; }
	float getTempSpeed() { return TempSpeed; }
	void setSpeed(float a) { Speed = a; }
	void setPlayer(int player); 
	float getAttackSpeed() { return AttackSpeed; }
	void setAttackSpeed(float a) { AttackSpeed = a; }
	void setHealth(float a) { Health = a; }
	float getTempAttackSpeed() { return TempAttackSpeed; }
	virtual void Attack(float dt);    //攻击
	virtual void Hurted(float Damage);  //受伤
	virtual void MagicHurt(float Damage);
	float TimeSet = 0;

	bool SkillFlag = 0;

	bool Die();                     //判断是否死亡及死亡操作
	void chessAnimation(string picturename, const int picturenum, Sprite* sprite, Point location, const float speed, const int loop);
	int GetAttackDistance();        //获得攻击距离

	const cocos2d::Size getContentSize() { return Size(width, height); }   //获得图片长宽
	virtual void Skill() {};          //技能
	virtual void recover();

	Sprite* bloodFrame = Sprite::create("BloodFrame.jpg");
	ProgressTimer* Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	ProgressTimer* _Mana = ProgressTimer::create(Sprite::create("Mana.png"));
	Sprite* ManaFrame = Sprite::create("BloodFrame.jpg");

	Label* Star = Label::createWithTTF(to_string(star), "fonts/arial.ttf", 24);
	void update(float dt) ;
	void Bloodupdate(float dt);
	
	/*用于装备修改属性*/
	void ChangeAttackDistance(int value) { AttackDistance += value; }
	void ChangeHealthLimit(int value) { HealthLimit += value; }
	void ChangeHealth(int value) { Health += value; }
	void ChangeArmor(int value) { Armor += value; }
	void ChangeAttackSpeed(float value) { AttackSpeed += value; }
	void ChangeDamage(int value) { Damage += value; }
	void ChangeMana(float value) { Mana += value; }
	void EquimentChange();
	void Chess::EquipToChess(Equipment* equ);
	
private:
	RoundTimer* test_timer = RoundTimer::create(5);
	friend class scene1;
};

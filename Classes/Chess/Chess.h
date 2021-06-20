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

	float AttackDistance = 100;  //��������
	float HealthLimit = 500;     //��������
	float Health = 500;          //����ֵ
	float Mana = 0;          //����ֵ
	float ManaOrigin = 0;      //��ʼ����ֵ
	float ManaLimit = 100;   //��������
	float Armor = 0;        //����
	float MagicResistance = 10;   //ħ������
	float Magic = 1.0f;          //����ǿ��
	float AttackSpeed = 0.8f;  //�����ٶ�
	float TempAttackSpeed = AttackSpeed;
	int Damage = 50;     //������

	float HurtRate = 1;   //�˺�����

	int type = None;        //����

	float Speed = 6;         //�ƶ��ٶ�
	float TempSpeed = Speed; //��¼�м��ٶ�

	float xtemp = x;      //����ս��ʱ��λ��(��ͼλ��)
	float ytemp = y;

	float x = 0.f;                //��ʵλ��
	float y = 0.f;

	float height = 0; //����ͼƬ�ĳ��ȺͿ��
	float width = 0;
	
	int OfPlayer = 0;     //�������
	int CoinsNeeded = 0;    //������
	int SoldCoins = CoinsNeeded; //����������
	int star = 1;        //�Ǽ�

	
	
	
public:
	//virtual bool init();
	Chess* AttackTarget = nullptr;   //����Ŀ��
	Chess();
	bool isMove = 0;
	ccArray* equipment = ccArrayNew(100);   //װ��
	string picturename;   //ͼƬ����
	int picturenum;       //ͼƬ����

	static Chess* createChess(string picture_name);
	void set(float x1, float y1);
	void set(Point point) {
		x = point.x;
		y = point.y;
	};
	void setTempPosition() { xtemp = x; ytemp = y; }

	Point getTempPosition(){return Point(xtemp, ytemp);}   //��ý���ս��ʱ��λ��
	int getType() { return type; }                       //�������
	int getCoinsNeeded() { return CoinsNeeded; }
	int getSoldCoins() { return SoldCoins; }
	int getPlayer() { return OfPlayer; }           //�����������
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
	virtual void Attack(float dt);    //����
	virtual void Hurted(float Damage);  //����
	virtual void MagicHurt(float Damage);
	float TimeSet = 0;

	bool SkillFlag = 0;

	bool Die();                     //�ж��Ƿ���������������
	void chessAnimation(string picturename, const int picturenum, Sprite* sprite, Point location, const float speed, const int loop);
	int GetAttackDistance();        //��ù�������

	const cocos2d::Size getContentSize() { return Size(width, height); }   //���ͼƬ����
	virtual void Skill() {};          //����
	virtual void recover();

	Sprite* bloodFrame = Sprite::create("BloodFrame.jpg");
	ProgressTimer* Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	ProgressTimer* _Mana = ProgressTimer::create(Sprite::create("Mana.png"));
	Sprite* ManaFrame = Sprite::create("BloodFrame.jpg");

	Label* Star = Label::createWithTTF(to_string(star), "fonts/arial.ttf", 24);
	void update(float dt) ;
	void Bloodupdate(float dt);
	
	/*����װ���޸�����*/
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

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
	//�������ֲ��
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
	/*��Ҫ��������*/
	float AttackDistance = 100;  //��������
	float HealthLimit = 500;     //��������
	float Health = 500;          //����ֵ
	float Mana = 0;          //����ֵ
	float ManaOrigin = 0;      //��ʼ����ֵ
	float ManaLimit = 100;   //��������
	float Armor = 0;        //����
	float MagicResistance = 0;   //ħ������
	float Magic = 1.0f;          //����ǿ��
	float AttackSpeed = 0.8f;  //�����ٶ�
	int Damage = 50;     //������
	float HurtRate = 1;   //�˺�����

	int type = None;        //����
	int star = 1;        //�Ǽ�
	int CoinsNeeded = 0;    //������
	int SoldCoins = CoinsNeeded; //����������
	int OfPlayer = 0;     //�������

	ccArray* equipment = ccArrayNew(100);   //װ��

	/*λ������*/
	float xtemp = x;      //����ս��ʱ��λ��(��ͼλ��)
	float ytemp = y;

	float x = 0.f;                //��ʵλ��
	float y = 0.f;

	float height = 0; //����ͼƬ�ĳ��ȺͿ��
	float width = 0;

public:
	//virtual bool init();

	/*�����Լ�λ���趨*/
	static Chess* createChess(string picture_name);
	void set(float x1, float y1);
	void set(Point point) {
		x = point.x;
		y = point.y;
	};
	void setTempPosition() { xtemp = x; ytemp = y; }
	const cocos2d::Size getContentSize() { return Size(width, height); }   //���ͼƬ����

	/*���º���*/
	void update(float dt);

	/*�������*/
	Chess* AttackTarget = NULL;   //����Ŀ��
	Sprite* bloodFrame = Sprite::create("BloodFrame.jpg");
	ProgressTimer* Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));

	/*����������������غ���*/
	Point getPosition() { return Point(x, y); }
	Point getTempPosition() { return Point(xtemp, ytemp); }   //��ý���ս��ʱ��λ��
	int GetAttackDistance() { return AttackDistance; }        //��ù�������
	int getType() { return type; }                       //�������
	int getCoinsNeeded() { return CoinsNeeded; }        //��ȡ����۸�
	int getSoldCoins() { return SoldCoins; }             //��ȡ�����۸�
	int getPlayer() { return OfPlayer; }           //�����������
	int getStar() { return star; }                //��ȡ����
	void setPlayer(int player) { OfPlayer = player; }
	virtual void Attack(float dt);    //����
	virtual void Hurted(int Damage);  //����

	/*����������/����*/
	virtual void Skill() {};          //����
	virtual void recover();           //״̬��ԭ
	bool Die();                     //�ж��Ƿ���������������

	/*����װ���޸�����*/
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

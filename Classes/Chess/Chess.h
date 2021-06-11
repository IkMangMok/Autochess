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

	int AttackDistance = 100;  //��������
	int HealthLimit = 500;     //��������
	int Health = 500;          //����ֵ
	int Mana = 0;          //����ֵ
	int ManaLimit = 100;   //��������
	int Armor = 0;        //����
	int MagicResistance = 0;   //ħ������
	float AttackSpeed = 0.8f;  //�����ٶ�
	int Damage = 50;     //������


	float xtemp = x;      //����ս��ʱ��λ��(��ͼλ��)
	float ytemp = y;

	float x = 0.f;                //��ʵλ��
	float y = 0.f;

	float height = 0; //����ͼƬ�ĳ��ȺͿ��
	float width = 0;

	int OfPlayer = 0;     //�������
	int CoinsNeeded = 0;    //������
	int star = 0;        //�Ǽ�
	ccArray* equipment = ccArrayNew(100);   //װ��
	
public:
	//virtual bool init();
	Chess* AttackTarget = NULL;   //����Ŀ��
	static Chess* createChess(string picture_name);
	void set(float x1, float y1);
	void set(Point point) {
		x = point.x;
		y = point.y;
	};
	void setTempPosition() { xtemp = x; ytemp = y; }

	Point getPosition();
	Point getTempPosition(){return Point(xtemp, ytemp);}   //��ý���ս��ʱ��λ��

	int getCoinsNeeded() { return CoinsNeeded; }

	virtual void Attack(float dt);    //����
	virtual void Hurted(int Damage);  //����

	bool Die();                     //�ж��Ƿ���������������

	int GetAttackDistance();        //��ù�������

	const cocos2d::Size getContentSize() { return Size(width, height); }   //���ͼƬ����
	virtual void Skill() {};          //����

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

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

class Chess :public Sprite {
protected:

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
	int getType() { return type; }                       //�������
	int getCoinsNeeded() { return CoinsNeeded; }
	int getSoldCoins() { return SoldCoins; }
	int getPlayer() { return OfPlayer; }           //�����������
	void setPlayer(int player) { OfPlayer = player; }
	virtual void Attack(float dt);    //����
	virtual void Hurted(int Damage);  //����

	bool Die();                     //�ж��Ƿ���������������

	int GetAttackDistance();        //��ù�������

	const cocos2d::Size getContentSize() { return Size(width, height); }   //���ͼƬ����
	virtual void Skill() {};          //����
	virtual void recover();
	Sprite* bloodFrame = Sprite::create("BloodFrame.jpg");
	
	
	ProgressTimer* Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	void update(float dt) ;
	
	

	
private:
	RoundTimer* test_timer = RoundTimer::create(5);
	friend class scene1;
};

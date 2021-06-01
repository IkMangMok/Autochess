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
	PeaShooter,         /* �㶹���� */
	WallNut,            /* ���ǽ */
	CabbagePult,        /* ���Ĳ�Ͷ�� */
	Garlic,             /* ���� */
	FirePeaShooter,     /* �����㶹���� */
	AcidLemonShooter,   /* ǿ���������� */
	Citron              /* ����Ե */
	//...
};
class Chess :public Sprite {
protected:

	int AttackDistance = 100;  //��������
	int HealthLimit = 500;     //��������
	int Health = 500;          //����ֵ
	int Armor = 0;        //����
	float AttackSpeed = 0.8f;  //�����ٶ�
	int Damage = 50;     //������

	float x = 0.;           //λ��
	float y = 0.;

	float xtemp = x;       //����ս��ʱ��λ��
	float ytemp = y;

	Player* OfPlayer = 0;     //�������
	int CoinsNeeded = 0;    //������
	int star = 0;        //�Ǽ�
	ccArray* equipment = ccArrayNew(100);   //װ��
=======

#include "cocos2d.h"
#include "string"

using namespace cocos2d;
using namespace std;

class Chess :public Sprite {
private:
	int AttackDistance;  //��������
	int Health;          //����ֵ
	int Armor;           //����
	float AttackSpeed;   //�����ٶ�
	float x = 0.;           //λ��
	float y = 0.;
	
>>>>>>> lx
	
public:
	//virtual bool init();
	Chess* AttackTarget = NULL;   //����Ŀ��
<<<<<<< HEAD
	static Chess* createChess(string picture_name, Point point);
	void set(float x, float y);
	void set(Point point);
	void setTempPosition() { xtemp = x; ytemp = y; }
	Point getPosition();
	Point getTempPosition();   //��ý���ս��ʱ��λ��
	virtual void Attack(float dt);    //����
	virtual void Hurted(int Damage);  //����
	bool Die();                     //�ж��Ƿ���������������
	int GetAttackDistance();        //��ù�������
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

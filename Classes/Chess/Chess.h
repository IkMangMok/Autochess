#pragma once
#include "cocos2d.h"
#include "string"

#include"Timer/RoundTimer.h"

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


	int xtemp = x;      //����ս��ʱ��λ��(��ͼλ��)
	int ytemp = y;

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

	virtual void Attack(float dt);    //����
	virtual void Hurted(int Damage);  //����

	bool Die();                     //�ж��Ƿ���������������

	int GetAttackDistance();        //��ù�������

	const cocos2d::Size getContentSize() { return Size(width, height); }   //���ͼƬ����
	
private:
	RoundTimer* test_timer = RoundTimer::create(5);
	friend class scene1;
};

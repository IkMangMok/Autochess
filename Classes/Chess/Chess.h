#pragma once
#include "cocos2d.h"
#include "string"
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
	int OfPlayer = 0;     //�������
	int CoinsNeeded = 0;    //������
	int star = 0;        //�Ǽ�
	ccArray* equipment = ccArrayNew(100);   //װ��
public:
	//virtual bool init();
	Chess* AttackTarget = NULL;   //����Ŀ��
	static Chess* createChess(string picture_name, float x, float y);  //ͼƬ��λ��
	void set(float x, float y);    //����x,y��ֵ��ÿ��setPosition��ؼ���set��
	void set(Point point);
	Point getPosition();           //���λ��
	virtual void Attack();    //����
	virtual void Hurted(int Damage);  //����
	bool Die();                     //�ж��Ƿ���������������
	int GetAttackDistance();        //��ù�������
	void Move();                   //�ƶ�
	void update(float dt);
	
};

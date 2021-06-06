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

struct chessInfo
{
	string address;
	int money;
	bool buy=false;
};

const chessInfo chess_store[8] =
{ {"walnut.png",1},{"pealauncher.png",2},{"mushroom.png",2},{"sunflower.png",1},{"cactus.png",3 },{"cherrybomb.png",3},
	{"cornshooter.png",2},{"cabbagepult.png",2} };

const string chessValue[3] =
{ "1 coin","2 coins","3 coins" };

/*const string upgradeChess[8]=
{"upgrade_walnut.jpg","upgrade_pealauncher.png","upgrade_mushroom.png","upgrade_sunflower.png","cactus.png","cherrybomb.png",

}*/

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
	
public:
	//virtual bool init();
	Chess* AttackTarget = NULL;   //����Ŀ��
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
};

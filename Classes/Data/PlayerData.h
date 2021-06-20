#pragma once
#include"cocos2d.h"
#include"GameData.h"
USING_NS_CC;

struct PackageSlot
{
	PackageSlot(bool a, int b) { is_occupied = a; is_equiped = b; }
	PackageSlot() { is_occupied = 0; is_equiped = 0; }
	bool is_occupied = 0;
	int is_equiped = 0;
};

class PlayerData {
private:
	/**********�����Ϣ*************/
	int LifeLimit = 100;   //����ֵ����
	int HealthValue = LifeLimit; //����ֵ
	int Grade = 1; //��ҵȼ�
	int ExperienceValue = 0;   //����ֵ
	int Gold = 10;  //���
	int NextNeedExp = 2;
	void CountExperience();
	
	//�ж��Ƿ���������
	bool HaveNewChess = 0;

public:

	void Hurted(int blood){ HealthValue -= blood;}   //����������
	void recover();

	ccArray* PlayerArray = ccArrayNew(100);   //��ұ�ս������������
	ccArray* FightArray = ccArrayNew(100);    //���ս��������������
	int chessnumber[ChessNumber] = {};
	chessInfo Used[4];

	/*װ���������*/
	ccArray* equipment = ccArrayNew(100);   //װ��
	ccArray* UnequipedEquipment = ccArrayNew(100);
	int occupied_slot = 0;
	bool is_package_opened = 0;
	PackageSlot packageSlot[3][4] = {};
	Point slotPoint[12] = {};
	void remain();
	//CREATE_FUNC(PlayerData);



	friend class GameSprite;
	friend class ChessPile;
	friend class GameScene;
	friend class HelpAndSetLayer;
	friend class Player;
	friend class PC_Player;
};

extern PlayerData player1data;
extern PlayerData player2data;
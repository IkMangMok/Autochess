#pragma once
#include"cocos2d.h"
#include"GameData.h"
USING_NS_CC;

/*to describe PackageSlot*/
struct PackageSlot
{
	bool is_occupied = 0;
	int is_equiped = 0;
};

class PlayerData {
public:
	void Hurted(int blood){ HealthValue -= blood;}

	void recover();
	ccArray* PlayerArray = ccArrayNew(100);   //��ұ�ս������������
	ccArray* FightArray = ccArrayNew(100);    //���ս��������������
	int chessnumber[ChessNumber] = {};
	//CREATE_FUNC(PlayerData);

private:
	int LifeLimit = 100;   //����ֵ����
	int HealthValue = LifeLimit; //����ֵ
	int Grade = 1; //��ҵȼ�
	int ExperienceValue = 0;   //����ֵ
	int Gold = 500;  //���
	bool HaveNewChess = 0;

	/*װ���������*/
	ccArray* equipment = ccArrayNew(100);   //װ��
	ccArray* UnequipedEquipment = ccArrayNew(100);
	int occupied_slot = 0;
	bool is_package_opened = 0;
	PackageSlot packageSlot[3][4] = {};
	Point slotPoint[12] = {};
	friend class GameSprite;
	friend class ChessPile;
	friend class GameScene;
	friend class Package;
};

extern PlayerData player1data;
extern PlayerData player2data;
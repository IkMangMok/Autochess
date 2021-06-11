#pragma once
#include"cocos2d.h"
USING_NS_CC;

struct PackageSlot
{
	//int x;
	//int y;
	bool is_occupied;//ռ��״̬
	int is_equiped;//װ��״̬
};
class PlayerData {
private:
	int LifeLimit = 100;   //����ֵ����
	int HealthValue = LifeLimit; //����ֵ
	int Grade = 1; //��ҵȼ�
	int ExperienceValue = 0;   //����ֵ
	int Gold = 5;  //���
	ccArray* equipment = ccArrayNew(100);   //װ��
	ccArray* PlayerArray = ccArrayNew(100);   //��ұ�ս������������
	bool HaveNewChess = 0;


	/*װ��ϵͳ�������*/
	ccArray* UnequipedEquipment = ccArrayNew(1200);
	int occupied_slot = 0;
	bool is_package_opened = 0;
	PackageSlot packageSlot[3][4] = {};
	Point slotPoint[12] = {};



public:
	void Hurted(int blood){ HealthValue -= blood;}
	void BuyChess();
	
	//CREATE_FUNC(PlayerData);
	friend class GameSprite;
	friend class ChessPile;
	friend class GameScene;
	friend class Package;
};

extern PlayerData player1data;
extern PlayerData player2data;
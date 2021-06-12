#pragma once
#include"cocos2d.h"
#include "GameData.h"
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
	/*Life System*/
	int LifeLimit = 100;   //����ֵ����
	int HealthValue = LifeLimit; //����ֵ
	
	/*Exp System*/
	int Level = 1; //��ҵȼ�
	int ExpValueTotal = 0;   //����ֵ
	int ExpInLevelMax = 0;  //��������
	int ExpInLevel = 0;     //�ȼ�������

	/*Gold System*/
	int Gold = 1;  //���

	/*Equipment System*/
	//ccArray* equipment = ccArrayNew(100);   //װ��
	/*װ��ϵͳ�������*/
	ccArray* UnequipedEquipment = ccArrayNew(1200);
	int occupied_slot = 0;
	bool is_package_opened = 0;
	PackageSlot packageSlot[3][4] = {};
	Point slotPoint[12] = {};
	
	/*Chess System*/
	ccArray* PlayerArray = ccArrayNew(100);   //��ұ�ս������������
	bool HaveNewChess = 0;

public:
	/*life system*/
	void LoseTurn();

	/*Gold system*/
	void BuyChess();
	void GoldInterest();

	/*Exp system*/
	void LevelUp();
	void BuyExp();


	
	//CREATE_FUNC(PlayerData);
	friend class Player;
	friend class GameSprite;
	friend class ChessPile;
	friend class GameScene;
	friend class Package;
	friend class AI_Player;
};

extern PlayerData player1data;
extern PlayerData player2data;
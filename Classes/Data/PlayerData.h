#pragma once
#include"cocos2d.h"
#include "GameData.h"
USING_NS_CC;

struct PackageSlot
{
	//int x;
	//int y;
	bool is_occupied;//占用状态
	int is_equiped;//装备状态
};
class PlayerData {
private:
	/*Life System*/
	int LifeLimit = 100;   //生命值上限
	int HealthValue = LifeLimit; //生命值
	
	/*Exp System*/
	int Level = 1; //玩家等级
	int ExpValueTotal = 0;   //经验值
	int ExpInLevelMax = 0;  //升级所需
	int ExpInLevel = 0;     //等级内现有

	/*Gold System*/
	int Gold = 1;  //金币

	/*Equipment System*/
	//ccArray* equipment = ccArrayNew(100);   //装备
	/*装备系统相关数据*/
	ccArray* UnequipedEquipment = ccArrayNew(1200);
	int occupied_slot = 0;
	bool is_package_opened = 0;
	PackageSlot packageSlot[3][4] = {};
	Point slotPoint[12] = {};
	
	/*Chess System*/
	ccArray* PlayerArray = ccArrayNew(100);   //玩家备战区的棋子数组
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
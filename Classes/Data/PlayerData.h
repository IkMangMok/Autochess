#pragma once
#include"cocos2d.h"
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
	int LifeLimit = 100;   //生命值上限
	int HealthValue = LifeLimit; //生命值
	int Grade = 1; //玩家等级
	int ExperienceValue = 0;   //经验值
	int Gold = 5;  //金币
	ccArray* equipment = ccArrayNew(100);   //装备
	ccArray* PlayerArray = ccArrayNew(100);   //玩家备战区的棋子数组
	bool HaveNewChess = 0;


	/*装备系统相关数据*/
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
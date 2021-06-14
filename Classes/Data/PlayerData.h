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
	ccArray* PlayerArray = ccArrayNew(100);   //玩家备战区的棋子数组
	ccArray* FightArray = ccArrayNew(100);    //玩家战斗区的棋子数组
	int chessnumber[ChessNumber] = {};
	//CREATE_FUNC(PlayerData);

private:
	int LifeLimit = 100;   //生命值上限
	int HealthValue = LifeLimit; //生命值
	int Grade = 1; //玩家等级
	int ExperienceValue = 0;   //经验值
	int Gold = 500;  //金币
	bool HaveNewChess = 0;

	/*装备相关数据*/
	ccArray* equipment = ccArrayNew(100);   //装备
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
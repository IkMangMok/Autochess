#pragma once
#include"cocos2d.h"
#include"GameData.h"
USING_NS_CC;

struct PackageSlot
{
	bool is_occupied = 0;
	int is_equiped = 0;
};

class PlayerData {
private:
	int LifeLimit = 0;   //生命值上限
	int HealthValue = LifeLimit; //生命值
	int Grade = 1; //玩家等级
	int ExperienceValue = 0;   //经验值
	int Gold = 3000;  //金币
	int ToNextGrade = 3;
	void CountExperience();
	
	
	bool HaveNewChess = 0;
public:
	void Hurted(int blood){ HealthValue -= blood;}

	void recover();
	ccArray* PlayerArray = ccArrayNew(100);   //玩家备战区的棋子数组
	ccArray* FightArray = ccArrayNew(100);    //玩家战斗区的棋子数组
	int chessnumber[ChessNumber] = {};
	chessInfo Used[4];

	/*装备相关数据*/
	ccArray* equipment = ccArrayNew(100);   //装备
	ccArray* UnequipedEquipment = ccArrayNew(100);
	int occupied_slot = 0;
	bool is_package_opened = 0;
	PackageSlot packageSlot[3][4] = {};
	Point slotPoint[12] = {};

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
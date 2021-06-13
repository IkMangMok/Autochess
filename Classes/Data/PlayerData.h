#pragma once
#include"cocos2d.h"
#include"GameData.h"
USING_NS_CC;


class PlayerData {
private:
	int LifeLimit = 100;   //生命值上限
	int HealthValue = LifeLimit; //生命值
	int Grade = 1; //玩家等级
	int ExperienceValue = 0;   //经验值
<<<<<<< Updated upstream
	int Gold = 5;  //金币
=======
	int Gold = 500;  //金币
>>>>>>> Stashed changes
	ccArray* equipment = ccArrayNew(100);   //装备
	ccArray* PlayerArray = ccArrayNew(100);   //玩家备战区的棋子数组
	bool HaveNewChess = 0;
public:
	void Hurted(int blood){ HealthValue -= blood;}
	void BuyChess();
	void recover();
<<<<<<< Updated upstream
	int chessnumber[ChessNumber];
=======
	int chessnumber[ChessNumber] = {};
>>>>>>> Stashed changes
	//CREATE_FUNC(PlayerData);
	friend class GameSprite;
	friend class ChessPile;
	friend class GameScene;
};

extern PlayerData player1data;
extern PlayerData player2data;
#ifndef NETWORKSMALLGAME_PLAYER_H
#define NETWORKSMALLGAME_PLAYER_H

#include "cocos2d.h"
#include "string"
<<<<<<< Updated upstream

class Player : public cocos2d::Sprite {
=======
#include "Scene/AutoChessScene.h"

using namespace cocos2d;
using namespace std;

class Player : public cocos2d::Sprite 
{
private:

	/*-----------玩家属性-------------*/
	//生命系统
	int Health = 100; //生命值
	//经验系统
	int Level = 1; //玩家等级
	int ExpValue = 0;   //经验值
	int BattleChessMaxNum = 1;  //上阵棋数上限
	//金币系统
	int Money = 0;   //金币
	ccArray* Equipment = ccArrayNew(100);   //装备数
	ccArray* PlayerChess = ccArrayNew(100);  //棋子


	/*------------属性相关函数-------------*/
	void ChangeHealth(int blood);
	void ChangeMoney(int benefit);
	void ChangeExp(int benefit);
	void BuyChess();//?暂不处理

public:
	CREATE_FUNC(Player);
	static Sprite* createPlayer();
	virtual bool init();

>>>>>>> Stashed changes

};
;
#endif
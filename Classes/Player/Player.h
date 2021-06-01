#pragma once
#include "cocos2d.h"
#include "string"

using namespace cocos2d;
using namespace std;

class Player : public cocos2d::Sprite {
private:
	int LifeLimit = 100;   //生命值上限
	int HealthValue = LifeLimit; //生命值
	int Grade; //玩家等级
	int ExperienceValue;   //经验值
	int Gold = 5;  //金币
	ccArray* equipment = ccArrayNew(100);   //装备数
	ccArray* PlayerChess = ccArrayNew(100);  //棋子

public:
	void Hurted(int blood); //受到伤害
	void BuyChess();

};


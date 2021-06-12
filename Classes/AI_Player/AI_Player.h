#pragma once
#include "cocos2d.h"
#include "Data/PlayerData.h"
USING_NS_CC;

class AI_Player
{
public:
private:

	void aiAction();    //回合所有行为的封装

	/* 可能有些什么行为呢？ */
	/* in order */

	int aiJudgeToUseMoney();
	void aiBuyChess();
	void aiJudgeLevelUp();

	void aiCreateBattleArray();
	void aiEquip();

};


#pragma once
#include "cocos2d.h"
#include "Data/PlayerData.h"
USING_NS_CC;

class AI_Player
{
public:
private:

	void aiAction();    //�غ�������Ϊ�ķ�װ

	/* ������Щʲô��Ϊ�أ� */
	/* in order */

	int aiJudgeToUseMoney();
	void aiBuyChess();
	void aiJudgeLevelUp();

	void aiCreateBattleArray();
	void aiEquip();

};


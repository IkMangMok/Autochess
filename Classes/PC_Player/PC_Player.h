#pragma once
#include "cocos2d.h"
#include "Data/PlayerData.h"
#include "Chess/Chess.h"
#include "Equipment/Equipment.h"
#include "Equipment/Gun.h"
#include "Equipment/Knife.h"

USING_NS_CC;

class PC_Player
{
public:
private:
	void pcAction();

	int pcJudgeMoneyUsage();
	void CheckChessStar();
	void CheckFightArrLimit();
	void CheckBuyExp();
	void CheckGoldInterest();
	void CheckHighFeeChess();


	void pcBuyChess();
	void pcCreateBattleArray();  //ѡ��ս������
	void pcEquip();

	void ShowFightArray();        //չʾս��������

};


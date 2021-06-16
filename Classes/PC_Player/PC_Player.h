#pragma once
#include "cocos2d.h"
//#include "Map/MapLayer.h"
#include "Data/PlayerData.h"
#include "Chess/Chess.h"
#include "Equipment/Equipment.h"
#include "Equipment/EquipmentFile.h"


USING_NS_CC;

class PC_Player
{
public:
private:
	void pcAction();

	int pcJudgeMoneyUsage();
	void CheckChessUpgrade();
	void CheckFightArrLimit();
	void CheckBuyExp();
	int CheckGoldInterest();
	void CheckHighFeeChess();


	void pcBuyChess();
	void pcCreateBattleArray();  //ѡ��ս������
	void pcEquip();

	/*Ŀǰ�Ž���GameSprite
	void ShowFightArray();        //չʾս��������
	void ShowPlayerArray();*/

};

extern PC_Player pc;
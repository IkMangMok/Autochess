#pragma once
#include "cocos2d.h"
#include "Equipment/Equipment.h"
#include "Equipment/Gun.h"
#include "Equipment/Knife.h"
#include "ChessPile/ChessPile.h"

USING_NS_CC;

class PC_Player
{
public:
<<<<<<< HEAD
=======
	Chess* pcSoldChess();
>>>>>>> lx
private:

	int pcJudgeMoneyUsage();
	bool CheckChessUpgrade();
	bool CheckFightArrLimit();
	void CheckBuyExp();
	int CheckGoldInterest();
	bool CheckHighFeeChess();
<<<<<<< HEAD


	bool pcBuyChess(int j);
=======
	

	bool pcBuyChess(int j);
	
>>>>>>> lx
	void pcCreateBattleArray();  //ѡ��ս������
	void pcEquip();

	void refresh(PlayerData& playerdata);  //�ֶ�ˢ��

	friend class GameScene;
};

extern PC_Player pc_player;
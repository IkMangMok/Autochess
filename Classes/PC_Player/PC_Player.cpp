#include "PC_Player.h"



/***************辅助函数************/
Chess* ChessCreate(int i)   //生成不同的棋子
{
	switch (i)
	{
		case walnut:
			return WalNut::createChess();
			break;
		case pealauncher:
			return PeaShooter::createChess();
			break;
		case mushroom:
			return MushRoom::createChess();
			break;
		case sunflower:
			return SunFlower::createChess();
			break;
		case chomper:
			return Chomper::createChess();
			break;
		case cherrybomb:
			return CherryBomb::createChess();
			break;
		case ga_peashooter:
			return Ga_PeaShooter::createChess();
			break;
		case tomatoboom:
			return TomatoBoom::createChess();
			break;
	}
}












/*-------------------------------pcJudgeMoneyUsage------------------------------------------*/
int PC_Player::pcJudgeMoneyUsage()
{
	bool save_money = 0;
	bool flag = 0;
	if (CheckGoldInterest())
	{
		save_money = 1;
	}
	
		/*step 1 检查能否升星*/
	flag = CheckChessUpgrade();
		/*step 2 检查棋子总数能不能塞满*/
	if (flag == 1)
		flag = CheckFightArrLimit();
		/*step 3 检查与敌方exp差距是否过大*/
	CheckBuyExp();
		/*step 4 检查是否靠近利息点*/
		/*step 5 买高费棋子*/
	
	if ((!save_money))
	{
		if (flag == 1)
			flag = CheckHighFeeChess();
		if (flag == 1 && player2data.Gold >= 2)
		{
			player2data.Gold -= 2;
			refresh(player2data);  //刷新
		}
	}
	

	return 0;

}   

/*--------------下面为pcJudgeMoneyUsage调用的函数---------------------*/

/*检查是否能够升星*/
/*若能够升星，判断钱够不够，不够就算了*/
bool PC_Player::CheckChessUpgrade()
{
	for (int i = 0; i < ChessNumber; i++)
	{
		if (player2data.chessnumber[i] > 0)       //判断哪种棋子存在
		{
			for (int j = 0; j < 4; j++)
			{
				if (player2data.Used[j].address == i ||
					(player2data.Used[j].address > OriginalChess && 
						i == player2data.Used[j].address - OriginalChess))  //判断是否存在可升星棋子或其子棋子（后半句为判断三星）
				{
				if(pcBuyChess(j))
					return 0;      //买棋子，GameScene的监视器自动监视是否可升级
				}
			}
		}
	}
	return 1;
}

/*检查pc的棋子总数是否能够塞满战斗区*/
/*若是，有钱就买一些棋子*/
bool PC_Player::CheckFightArrLimit()
{
	int ChessTotal = (player2data.FightArray->num) + (player2data.PlayerArray->num);  //战斗区+准备区=总数
	if (ChessTotal <= player2data.Grade && player2data.Gold > 5)  //若不足且金钱足够
	{
		int tempgold = 0, tempaddress = -1;
		//按一定逻辑购买!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j = 0; j < 4; j++)
		{
			if (player2data.Used[j].money >= tempgold && player2data.Used[j].buy == false)
			{
				tempgold = player2data.Used[j].money;  //寻找最高费棋子
				tempaddress = j;				
			}
		}
		if (tempaddress != -1)
		{
		
			if (pcBuyChess(tempaddress))
			{			
				return 0;
			}
		}
		else
			return 1;        //没有可以买的棋子了
	}
	return 1;
}

/*检查与敌方Exp差距是否过大*/
/*若是，钱够就购买一些Exp*/
void PC_Player::CheckBuyExp()
{
	int ExpError = player1data.ExperienceValue - player2data.ExperienceValue;
	while (ExpError > 5 && player2data.Gold >= 4)
	{
		//购买Exp!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		player2data.Gold -= 4;
		player2data.ExperienceValue += 4;
		player2data.CountExperience();
		ExpError = player1data.ExperienceValue - player2data.ExperienceValue;
	}
}

/*检查是否靠近利息点（需要存钱的点）*/
int PC_Player::CheckGoldInterest()
{
	if (player2data.Gold < 10)  //积蓄10元以下
		return 1;            //要存钱
	else if (player2data.Gold > 25 && player2data.Gold < 30)//积蓄25-30元
		return 1;            //要存钱
	else if (player2data.Gold > 45 && player2data.Gold < 50)//积蓄45-50元
		return 1;
	else
		return 0;           //不存了
}

/*买高费棋子*/
/*若有足够高档的棋子，且有足够的钱，就买*/
bool PC_Player::CheckHighFeeChess()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int tempgold = 0, tempaddress = -1;
	//按一定逻辑购买!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int j = 0; j < 4; j++)
	{
		if (player2data.Used[j].money >= tempgold && player2data.Used[j].buy == false)
		{
			tempgold = player2data.Used[j].money;  //寻找最高费棋子
			tempaddress = j;

		}
	}
	if (tempaddress >= 3)    //三费卡！
	{
		if(pcBuyChess(tempaddress))
			return 0;
		
	}

}
/*---------------------------------------------------------------------------------------------*/
/*pc 快速随机装备*/
void PC_Player::pcEquip()
{
	for (int i = 0; i < player2data.UnequipedEquipment->num; i++)
	{
		int equipTargetIndex = rand() % (player2data.FightArray->num);
		auto temp = (Chess*)player2data.FightArray->arr[equipTargetIndex];
		ccArrayAppendObject(temp->equipment, ((Equipment*)player2data.UnequipedEquipment->arr[i]));
		//((Equipment*)player1data.UnequipedEquipment->arr[i])->retain();
		ccArrayRemoveObjectAtIndex(player2data.UnequipedEquipment, i);
		((Equipment*)player2data.UnequipedEquipment->arr[i])->removeFromParent();

		temp->EquimentChange();
		
	}
}

/*pc 选拔战斗阵列——星数优先原则*/
void PC_Player::pcCreateBattleArray()
{
	/*如不足，先从准备区补充*/
	for (int j = 3; j >= 1; j--)  //3星--1星
	{
		for (int i = 0; i < player2data.PlayerArray->num; i++)
		{

			if (player2data.FightArray->num < player2data.Grade)
			{
				if (((Chess*)(player2data.PlayerArray->arr[i]))->getStar() == j)
				{
					ccArrayAppendObject(player2data.FightArray, player2data.PlayerArray->arr[i]);
					ccArrayRemoveObjectAtIndex(player2data.PlayerArray, i);
				}
			}
			else
				break;
		}
		if (player2data.FightArray->num == player2data.Grade)
			break;
	}
	/*填满后，进行交换*/
	/*先把1星换成两星*/
	for (int i = 0; i < player2data.FightArray->num; i++)
	{
		if (((Chess*)(player2data.FightArray->arr[i]))->getStar() > 1)
			continue;
		else
		{
			for (int j = 0; j < player2data.PlayerArray->num; j++)
			{
				if (((Chess*)(player2data.PlayerArray->arr[j]))->getStar() > 1)
				{
					ccArrayAppendObject(player2data.FightArray, player2data.PlayerArray->arr[j]);  //swap
					ccArrayRemoveObjectAtIndex(player2data.PlayerArray, j);

					ccArrayAppendObject(player2data.PlayerArray, player2data.FightArray->arr[i]);
					ccArrayRemoveObjectAtIndex(player2data.FightArray, i);
				}
			}
		}
	}
	/*再把2星换成3星*/
	for (int i = 0; i < player2data.FightArray->num; i++)
	{
		if (((Chess*)(player2data.FightArray->arr[i]))->getStar() ==3 )
			continue;
		else
		{
			for (int j = 0; j < player2data.PlayerArray->num; j++)
			{
				if (((Chess*)(player2data.PlayerArray->arr[j]))->getStar() == 3)
				{
					ccArrayAppendObject(player2data.FightArray, player2data.PlayerArray->arr[j]);  //swap
					ccArrayRemoveObjectAtIndex(player2data.PlayerArray, j);

					ccArrayAppendObject(player2data.PlayerArray, player2data.FightArray->arr[i]);
					ccArrayRemoveObjectAtIndex(player2data.FightArray, i);
				}
			}
		}
	}
}



bool PC_Player::pcBuyChess(int j)
{
	if (player2data.FightArray->num + player2data.PlayerArray->num <= player2data.Grade + 7)  //确保不超过备战区
	{
		if (player2data.Gold >= player2data.Used[j].money && player2data.Used[j].buy == false)   //大于则买
		{
			auto temp = ChessCreate(player2data.Used[j].address);
			ccArrayAppendObject(player2data.PlayerArray, temp);
			player2data.HaveNewChess = 1;
			player2data.Used[j].buy = true;
			return 1;
		}
		else
			return 0;
	}
	return 1;
}

void PC_Player::refresh(PlayerData& playerdata)
{
	for (int i = 0; i < 4; i++)
	{
		int deter = 0;
		deter = rand() % 100 + 1;
		for (int j = 0; j < 5; j++)
		{
			if (deter > PB[min(9, playerdata.Grade) - 1][j])
				deter -= PB[min(9, playerdata.Grade) - 1][j];
			else
			{
				int temp = 0;
				while (1)
				{
					temp = rand() % OriginalChess;
					if (chess_store[temp].money == j + 1)
						break;
				}
				playerdata.Used[i].address = chess_store[temp].address;
				playerdata.Used[i].money = chess_store[temp].money;
				playerdata.Used[i].picture_name = chess_store[temp].picture_name;
				playerdata.Used[i].buy = false;
				break;
			}
		}
	}
}
Chess* PC_Player::pcSoldChess()
{
	
	for (int i = 0; i < player2data.PlayerArray->num; i++)
	{
		auto temp = (Chess*)player2data.PlayerArray->arr[i];
		if (temp->getStar() == 1 && temp->getCoinsNeeded() <= 2)   //卖掉星级最低的
		{
			return temp;
		}
	}
}
PC_Player pc_player;
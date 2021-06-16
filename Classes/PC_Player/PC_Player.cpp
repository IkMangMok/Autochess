#include "PC_Player.h"

PC_Player pc;

void PC_Player::pcAction()
{
	pcJudgeMoneyUsage();   //step 1 使钱
	pcCreateBattleArray(); //step 2 快速阵型
	pcEquip();             //step 3 快速装备
}

/*-------------------------------pcJudgeMoneyUsage------------------------------------------*/
int PC_Player::pcJudgeMoneyUsage()
{
	bool step_done = 0;

	/*step 1 检查能否升星*/
	if (!step_done)
	{
		//CheckChessUpgrade();                   //检查我的棋子是否能够升星!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		step_done = 1;
	}

	/*step 2 检查棋子总数能不能塞满*/
	if (!step_done)
	{
		//CheckFightArrLimit();!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		step_done = 1;
	}

	/*step 3 检查与敌方exp差距是否过大*/
	if (!step_done)
	{
		//CheckBuyExp();!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		step_done = 1;
	}

	/*step 4 检查是否靠近利息点*/
	bool save_money = 0;
	if (!step_done)
	{
		if (CheckGoldInterest())
		{
			step_done = 1;
			save_money = 1;
		}
		else
			step_done = 1;
	}

	/*step 5 买高费棋子*/
	if((!step_done) && (!save_money))
	{
		//CheckHighFeeChess();!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		step_done = 1;
	}

	//if ((step_done)&&(!save_money))
		//pcJudgeMoneyUsage();  //参与递归

	return 0;
}   

/*--------------下面为pcJudgeMoneyUsage调用的函数---------------------*/

/*检查是否能够升星*/
/*若能够升星，判断钱够不够，不够就算了*/
void PC_Player::CheckChessUpgrade()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

/*检查pc的棋子总数是否能够塞满战斗区*/
/*若是，有钱就买一些棋子*/
void PC_Player::CheckFightArrLimit()
{
	int ChessTotal = (player2data.FightArray->num) + (player2data.PlayerArray->num);  //战斗区+准备区=总数
	if (ChessTotal < player2data.Grade)  //若不足
	{
		//按一定逻辑购买!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}

/*检查与敌方Exp差距是否过大*/
/*若是，钱够就购买一些Exp*/
void PC_Player::CheckBuyExp()
{
	int ExpError = player1data.ExperienceValue - player2data.ExperienceValue;
	if (ExpError > 5)
	{
		//购买Exp!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
void PC_Player::CheckHighFeeChess()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
/*---------------------------------------------------------------------------------------------*/
/*pc 快速随机装备*/
void PC_Player::pcEquip()
{
	for (int i = 0; i < player2data.UnequipedEquipment->num; i++)
	{
		int equipTargetIndex = rand() % (player2data.FightArray->num);

		switch (((Equipment*)player2data.UnequipedEquipment->arr[i])->type)
		{
			case GUN:
				((Gun*)player2data.UnequipedEquipment->arr[i])->EquipToChess((Chess*)(player2data.FightArray->arr[equipTargetIndex]));
				break;
			case KNIFE:
				((Knife*)player2data.UnequipedEquipment->arr[i])->EquipToChess((Chess*)(player2data.FightArray->arr[equipTargetIndex]));
				break;
		}
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
		if (((Chess*)(player2data.PlayerArray->arr[i]))->getStar() > 1)
			continue;
		else
		{
			for (int j = 0; j < player2data.PlayerArray->num; j++)
			{
				if (((Chess*)(player2data.PlayerArray->arr[i]))->getStar() > 1)
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
		if (((Chess*)(player2data.PlayerArray->arr[i]))->getStar() ==3 )
			continue;
		else
		{
			for (int j = 0; j < player2data.PlayerArray->num; j++)
			{
				if (((Chess*)(player2data.PlayerArray->arr[i]))->getStar() == 3)
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


/*-------------------------------pc ShowFightArray------------------------------------------*/
/*pc 显示阵列*/
//void PC_Player::ShowFightArray()
//{
	/*准备区*/
	
	/*战斗区*/
//	for (int i = 0; i < player2data.FightArray->num; i++)
//	{
		//放到战场上并显示（先做低级版本，乱放）!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	}
	//调用战斗函数!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//}




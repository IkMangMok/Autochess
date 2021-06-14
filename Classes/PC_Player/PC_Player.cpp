#include "PC_Player.h"

void PC_Player::pcAction()
{
	pcJudgeMoneyUsage();   //使钱
	pcEquip();             //快速装备
	//pcCreateBattleArray(); //快速阵型
}

int PC_Player::pcJudgeMoneyUsage()
{
	int step_done = 0;

	/*step 1 检查能否升星*/
	if (!step_done)
	{
		//CheckChessStar();  //检查
		step_done = 1;
	}

	/*step 2 检查战斗区棋子是否达到上限*/
	if (!step_done)
	{
		//CheckFightArrLimit();
		step_done = 1;
	}

	/*step 3 检查与敌方exp差距是否过大*/
	if (!step_done)
	{
		//CheckBuyExp();
		step_done = 1;
	}

	/*step 4 检查是否靠近利息点*/
	if (!step_done)
	{
		//CheckGoldInterest();
		step_done = 1;
	}

	/*step 5 买高费棋子*/
	{
		//CheckHighFeeChess();
		step_done = 1;
	}

	//if (step_done)
		//pcJudgeMoneyUsage();  //参与递归

	return 0;
}

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

/*pc 显示阵列*/
void PC_Player::ShowFightArray()
{
	/*准备区*/
	for (int i = 0; i < player2data.PlayerArray->num; i++)
	{
		//一排备战棋子
	}
	/*战斗区*/
	

}
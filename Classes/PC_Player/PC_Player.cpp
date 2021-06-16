#include "PC_Player.h"

PC_Player pc;

void PC_Player::pcAction()
{
	pcJudgeMoneyUsage();   //step 1 ʹǮ
	pcCreateBattleArray(); //step 2 ��������
	pcEquip();             //step 3 ����װ��
}

/*-------------------------------pcJudgeMoneyUsage------------------------------------------*/
int PC_Player::pcJudgeMoneyUsage()
{
	bool step_done = 0;

	/*step 1 ����ܷ�����*/
	if (!step_done)
	{
		//CheckChessUpgrade();                   //����ҵ������Ƿ��ܹ�����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		step_done = 1;
	}

	/*step 2 ������������ܲ�������*/
	if (!step_done)
	{
		//CheckFightArrLimit();!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		step_done = 1;
	}

	/*step 3 �����з�exp����Ƿ����*/
	if (!step_done)
	{
		//CheckBuyExp();!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		step_done = 1;
	}

	/*step 4 ����Ƿ񿿽���Ϣ��*/
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

	/*step 5 ��߷�����*/
	if((!step_done) && (!save_money))
	{
		//CheckHighFeeChess();!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		step_done = 1;
	}

	//if ((step_done)&&(!save_money))
		//pcJudgeMoneyUsage();  //����ݹ�

	return 0;
}   

/*--------------����ΪpcJudgeMoneyUsage���õĺ���---------------------*/

/*����Ƿ��ܹ�����*/
/*���ܹ����ǣ��ж�Ǯ������������������*/
void PC_Player::CheckChessUpgrade()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

/*���pc�����������Ƿ��ܹ�����ս����*/
/*���ǣ���Ǯ����һЩ����*/
void PC_Player::CheckFightArrLimit()
{
	int ChessTotal = (player2data.FightArray->num) + (player2data.PlayerArray->num);  //ս����+׼����=����
	if (ChessTotal < player2data.Grade)  //������
	{
		//��һ���߼�����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}

/*�����з�Exp����Ƿ����*/
/*���ǣ�Ǯ���͹���һЩExp*/
void PC_Player::CheckBuyExp()
{
	int ExpError = player1data.ExperienceValue - player2data.ExperienceValue;
	if (ExpError > 5)
	{
		//����Exp!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}

/*����Ƿ񿿽���Ϣ�㣨��Ҫ��Ǯ�ĵ㣩*/
int PC_Player::CheckGoldInterest()
{
	if (player2data.Gold < 10)  //����10Ԫ����
		return 1;            //Ҫ��Ǯ
	else if (player2data.Gold > 25 && player2data.Gold < 30)//����25-30Ԫ
		return 1;            //Ҫ��Ǯ
	else if (player2data.Gold > 45 && player2data.Gold < 50)//����45-50Ԫ
		return 1;
	else
		return 0;           //������
}

/*��߷�����*/
/*�����㹻�ߵ������ӣ������㹻��Ǯ������*/
void PC_Player::CheckHighFeeChess()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
/*---------------------------------------------------------------------------------------------*/
/*pc �������װ��*/
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

/*pc ѡ��ս�����С�����������ԭ��*/
void PC_Player::pcCreateBattleArray()
{
	/*�粻�㣬�ȴ�׼��������*/
	for (int j = 3; j >= 1; j--)  //3��--1��
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
	/*�����󣬽��н���*/
	/*�Ȱ�1�ǻ�������*/
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
	/*�ٰ�2�ǻ���3��*/
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
/*pc ��ʾ����*/
//void PC_Player::ShowFightArray()
//{
	/*׼����*/
	
	/*ս����*/
//	for (int i = 0; i < player2data.FightArray->num; i++)
//	{
		//�ŵ�ս���ϲ���ʾ�������ͼ��汾���ҷţ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	}
	//����ս������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//}




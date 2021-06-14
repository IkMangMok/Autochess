#include "PC_Player.h"

void PC_Player::pcAction()
{
	pcJudgeMoneyUsage();   //ʹǮ
	pcEquip();             //����װ��
	//pcCreateBattleArray(); //��������
}

int PC_Player::pcJudgeMoneyUsage()
{
	int step_done = 0;

	/*step 1 ����ܷ�����*/
	if (!step_done)
	{
		//CheckChessStar();  //���
		step_done = 1;
	}

	/*step 2 ���ս���������Ƿ�ﵽ����*/
	if (!step_done)
	{
		//CheckFightArrLimit();
		step_done = 1;
	}

	/*step 3 �����з�exp����Ƿ����*/
	if (!step_done)
	{
		//CheckBuyExp();
		step_done = 1;
	}

	/*step 4 ����Ƿ񿿽���Ϣ��*/
	if (!step_done)
	{
		//CheckGoldInterest();
		step_done = 1;
	}

	/*step 5 ��߷�����*/
	{
		//CheckHighFeeChess();
		step_done = 1;
	}

	//if (step_done)
		//pcJudgeMoneyUsage();  //����ݹ�

	return 0;
}

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

/*pc ��ʾ����*/
void PC_Player::ShowFightArray()
{
	/*׼����*/
	for (int i = 0; i < player2data.PlayerArray->num; i++)
	{
		//һ�ű�ս����
	}
	/*ս����*/
	

}
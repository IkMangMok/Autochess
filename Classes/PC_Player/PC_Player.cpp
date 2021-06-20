#include "PC_Player.h"



/***************��������************/
Chess* ChessCreate(int i)   //���ɲ�ͬ������
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
	
		/*step 1 ����ܷ�����*/
	flag = CheckChessUpgrade();
		/*step 2 ������������ܲ�������*/
	if (flag == 1)
		flag = CheckFightArrLimit();
		/*step 3 �����з�exp����Ƿ����*/
	CheckBuyExp();
		/*step 4 ����Ƿ񿿽���Ϣ��*/
		/*step 5 ��߷�����*/
	
	if ((!save_money))
	{
		if (flag == 1)
			flag = CheckHighFeeChess();
		if (flag == 1 && player2data.Gold >= 2)
		{
			player2data.Gold -= 2;
			refresh(player2data);  //ˢ��
		}
	}
	

	return 0;

}   

/*--------------����ΪpcJudgeMoneyUsage���õĺ���---------------------*/

/*����Ƿ��ܹ�����*/
/*���ܹ����ǣ��ж�Ǯ������������������*/
bool PC_Player::CheckChessUpgrade()
{
	for (int i = 0; i < ChessNumber; i++)
	{
		if (player2data.chessnumber[i] > 0)       //�ж��������Ӵ���
		{
			for (int j = 0; j < 4; j++)
			{
				if (player2data.Used[j].address == i ||
					(player2data.Used[j].address > OriginalChess && 
						i == player2data.Used[j].address - OriginalChess))  //�ж��Ƿ���ڿ��������ӻ��������ӣ�����Ϊ�ж����ǣ�
				{
				if(pcBuyChess(j))
					return 0;      //�����ӣ�GameScene�ļ������Զ������Ƿ������
				}
			}
		}
	}
	return 1;
}

/*���pc�����������Ƿ��ܹ�����ս����*/
/*���ǣ���Ǯ����һЩ����*/
bool PC_Player::CheckFightArrLimit()
{
	int ChessTotal = (player2data.FightArray->num) + (player2data.PlayerArray->num);  //ս����+׼����=����
	if (ChessTotal <= player2data.Grade && player2data.Gold > 5)  //�������ҽ�Ǯ�㹻
	{
		int tempgold = 0, tempaddress = -1;
		//��һ���߼�����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j = 0; j < 4; j++)
		{
			if (player2data.Used[j].money >= tempgold && player2data.Used[j].buy == false)
			{
				tempgold = player2data.Used[j].money;  //Ѱ����߷�����
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
			return 1;        //û�п������������
	}
	return 1;
}

/*�����з�Exp����Ƿ����*/
/*���ǣ�Ǯ���͹���һЩExp*/
void PC_Player::CheckBuyExp()
{
	int ExpError = player1data.ExperienceValue - player2data.ExperienceValue;
	while (ExpError > 5 && player2data.Gold >= 4)
	{
		//����Exp!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		player2data.Gold -= 4;
		player2data.ExperienceValue += 4;
		player2data.CountExperience();
		ExpError = player1data.ExperienceValue - player2data.ExperienceValue;
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
bool PC_Player::CheckHighFeeChess()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int tempgold = 0, tempaddress = -1;
	//��һ���߼�����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int j = 0; j < 4; j++)
	{
		if (player2data.Used[j].money >= tempgold && player2data.Used[j].buy == false)
		{
			tempgold = player2data.Used[j].money;  //Ѱ����߷�����
			tempaddress = j;

		}
	}
	if (tempaddress >= 3)    //���ѿ���
	{
		if(pcBuyChess(tempaddress))
			return 0;
		
	}

}
/*---------------------------------------------------------------------------------------------*/
/*pc �������װ��*/
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
	/*�ٰ�2�ǻ���3��*/
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
	if (player2data.FightArray->num + player2data.PlayerArray->num <= player2data.Grade + 7)  //ȷ����������ս��
	{
		if (player2data.Gold >= player2data.Used[j].money && player2data.Used[j].buy == false)   //��������
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
		if (temp->getStar() == 1 && temp->getCoinsNeeded() <= 2)   //�����Ǽ���͵�
		{
			return temp;
		}
	}
}
PC_Player pc_player;
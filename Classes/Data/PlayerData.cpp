#include"PlayerData.h"
/*------------------Life System--------------------*/
/*回合结束，-blood*/
void PlayerData::LoseTurn()
{
	int HurtCount = 0;                                                               //mechanism: count_of_chess * fee_of_chess
																				     //which should be defined in 


	HealthValue -= HurtCount;
}
/*------------------Gold System--------------------*/
/*回合利息*/
void PlayerData::GoldInterest()
{
	if (Gold < 8)
		Gold = Gold * 1.2;  //20%
	else if (Gold < 18)
		Gold = Gold * 1.25;  //25%
	else
		Gold = Gold * 1.3;  //30%
}

/*------------------Exp System-------------------*/
/*通过Exp生成Level*/
void PlayerData::LevelUp()
{
	int level_count = 1;
	int tmp_exp = ExpValueTotal;
	if (0 == tmp_exp)
	{
		ExpInLevel = 0;
		Level = 1;
	}
	else
	{
		for (int i = 1;; i++)
		{
			tmp_exp -= i;
			if (tmp_exp < 0)
			{
				ExpInLevel = tmp_exp += i;
				break;
			}
			level_count++;
		}

		/*Check if level up, and add gold*/
		if (level_count > Level)
		{
			for (int i = Level + 1; i <= level_count; i++)
				Gold += i;
		}

		Level = level_count;
		ExpInLevelMax = Level;
	}
}
/*购买Exp*/
void PlayerData::BuyExp()
{
	if (Gold >= 3)
	{
		Gold -= 3;
		ExpValueTotal += 3;
		LevelUp();
	}
	//could add a Label when Gold not enough
}

PlayerData player1data;
PlayerData player2data;
#include"player.h"
;

<<<<<<< Updated upstream
=======
/*--------------创建Player相关函数-----------*/
Sprite* Player::createPlayer()
{
	return Player::create();
}

bool Player::init()
{
	if (!Sprite::create())
		return false;

	Health = 100; //生命值
	Level = 1; //玩家等级
	ExpValue = 0;   //经验值
	Money = 0;   //金币

	return true;
}

/*--------------属性相关函数实现-------------*/
void Player::ChangeHealth(int blood)
{
	Health -= blood;
}
void Player::ChangeMoney(int benefit)
{
	Money += benefit;
}
void Player::ChangeExp(int benefit)
{
	ExpValue += benefit;
	
	/*-------------升级判断-------------*/
	/*
		规则： Exp     Level
		        0        1
				1        2
				2		 2
				3        3
				4        3
				5        3
				6        4
			   ...      ...
	*/
	int tmpExp = ExpValue;
	int tmpLevel = 1;
	for (int i = 1; tmpExp >= 0; i++)
	{
		tmpExp -= i;
		if (tmpExp >= 0)
			tmpLevel++;
	}
	Level = tmpLevel;
	/*-------------上阵数判断------------*/
	BattleChessMaxNum = Level;  //等于级数

}
void Player::BuyChess()
{

}
>>>>>>> Stashed changes

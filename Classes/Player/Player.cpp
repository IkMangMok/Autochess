#include"player.h"
;

<<<<<<< Updated upstream
=======
/*--------------����Player��غ���-----------*/
Sprite* Player::createPlayer()
{
	return Player::create();
}

bool Player::init()
{
	if (!Sprite::create())
		return false;

	Health = 100; //����ֵ
	Level = 1; //��ҵȼ�
	ExpValue = 0;   //����ֵ
	Money = 0;   //���

	return true;
}

/*--------------������غ���ʵ��-------------*/
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
	
	/*-------------�����ж�-------------*/
	/*
		���� Exp     Level
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
	/*-------------�������ж�------------*/
	BattleChessMaxNum = Level;  //���ڼ���

}
void Player::BuyChess()
{

}
>>>>>>> Stashed changes

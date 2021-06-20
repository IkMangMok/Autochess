#include"MushRoom.h"

MushRoom::MushRoom()
{
	type = mushroom;
	AttackDistance = 225;
	Health = 400;
	HealthLimit = Health;
<<<<<<< HEAD
=======
	Mana = 0;
	ManaLimit = 50;
>>>>>>> lx
	Damage = 120;
	Armor = 15;
	AttackSpeed = 1.1f;
	CoinsNeeded = 2;
	SoldCoins = 2;
	star = 1;
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
}
<<<<<<< HEAD

=======
void MushRoom::Skill()
{
	auto value = (star == 1) ? 30 : (star == 2) ? 40 : 55;
	if (OfPlayer == 0)
	{
		for (int i = 0; i < player1data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player1data.FightArray->arr[i]));
			if (temp->getPlayer() == OfPlayer && !temp->Die())
			{
				temp->ChangeMana((15 + 15 * star) * Magic);
				Mana = 0;
			}
		}
	}
	if (OfPlayer == 1)
	{
		for (int i = 0; i < player2data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player1data.FightArray->arr[i]));
			if (temp->getPlayer() == OfPlayer && !temp->Die())
			{
				temp->ChangeMana((15 + 15 * star) * Magic);
				Mana = 0;
			}		
		}
	}
}
>>>>>>> lx
MushRoom* MushRoom::createChess()
{
	auto mushroom = MushRoom::create();
	
	mushroom->picturename = "Mushroom%d.png";
	mushroom->picturenum = 15;
	mushroom->chessAnimation(mushroom->picturename, mushroom->picturenum, mushroom, mushroom->getPosition(), 0.08f, -1);

	mushroom->autorelease();
	return mushroom;
}

upgrade_MushRoom::upgrade_MushRoom()
{
	type = upgrade_mushroom;
	AttackDistance = 225;
	Health = 700;
	HealthLimit = Health;
	Damage = 150;
	Armor = 15;
	AttackSpeed = 1.1f;
	CoinsNeeded = 0;
	SoldCoins = 7;
	star = 2;
}

upgrade_MushRoom* upgrade_MushRoom::createChess()
{
	auto mushroom = upgrade_MushRoom::create();

	mushroom->picturename = "Mushroom%d.png";
	mushroom->picturenum = 15;
	mushroom->chessAnimation(mushroom->picturename, mushroom->picturenum, mushroom, mushroom->getPosition(), 0.08f, -1);

	mushroom->autorelease();
	return mushroom;
}

_3star_MushRoom::_3star_MushRoom()
{
	type = _3star_mushroom;
	AttackDistance = 225;
	Health = 1000;
	HealthLimit = Health;
	Damage = 180;
	Armor = 15;
	AttackSpeed = 1.1f;
	CoinsNeeded = 0;
	SoldCoins = 17;
	star = 3;
}

_3star_MushRoom* _3star_MushRoom::createChess()
{
	auto mushroom = _3star_MushRoom::create();

	mushroom->picturename = "upgrade_Mushroom%d.png";
	mushroom->picturenum = 16;
	mushroom->chessAnimation(mushroom->picturename, mushroom->picturenum, mushroom, mushroom->getPosition(), 0.08f, -1);

	mushroom->autorelease();
	return mushroom;
}
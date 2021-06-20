#include"SunFlower.h"

SunFlower::SunFlower()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = sunflower;
	AttackDistance = 750;
	Health = 300;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 100;
	Magic = 1.0f;
	Damage = 60;
	Armor = 5;
	AttackSpeed = 0.8f;
	CoinsNeeded = 1;
	SoldCoins = 1;
	star = 1;
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
}

SunFlower* SunFlower::createChess()
{
	auto sunflower = SunFlower::create();
	sunflower->picturename = "Sunflower%d.png";
	sunflower->picturenum = 17;
	sunflower->chessAnimation(sunflower->picturename, sunflower->picturenum, sunflower, sunflower->getPosition(), 0.08f, -1);
	sunflower->autorelease();
	return sunflower;
}
void SunFlower::Skill()
{
	if (OfPlayer == 0)
	{
		for (int i = 0; i < player1data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player1data.FightArray->arr[i]));
				if (temp->getPlayer() == OfPlayer && !temp->Die())
				{
					temp->MagicHurt(-(50 + 50 * star) * Magic);
						Mana = 0;
				}
		}
	}
	if (OfPlayer == 1)
	{
		for (int i = 0; i < player2data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player2data.FightArray->arr[i]));
			if (temp->getPlayer() == OfPlayer && !temp->Die())
			{
				temp->MagicHurt(-(50 + 50 * star) * Magic);
				Mana = 0;
			}
		}
	}
}
upgrade_SunFlower::upgrade_SunFlower()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = upgrade_sunflower;
	AttackDistance = 750;
	Health = 500;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 100;
	Magic = 1.0f;
	Damage = 90;
	Armor = 5;
	AttackSpeed = 0.8f;
	CoinsNeeded = 0;
	SoldCoins = 3;
	star = 2;
}

upgrade_SunFlower* upgrade_SunFlower::createChess()
{
	auto sunflower = upgrade_SunFlower::create();

	sunflower->picturename = "upgrade_Sunflower%d.png";
	sunflower->picturenum = 17;
	sunflower->chessAnimation(sunflower->picturename, sunflower->picturenum, sunflower, sunflower->getPosition(), 0.08f, -1);

	sunflower->autorelease();
	return sunflower;
}

_3star_SunFlower::_3star_SunFlower()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = _3star_sunflower;
	AttackDistance = 750;
	Health = 800;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 100;
	Magic = 1.0f;
	Damage = 120;
	Armor = 5;
	AttackSpeed = 0.8f;
	CoinsNeeded = 0;
	SoldCoins = 8;
	star = 3;
}

_3star_SunFlower* _3star_SunFlower::createChess()
{
	auto sunflower = _3star_SunFlower::create();

	sunflower->picturename = "upgrade_Sunflower%d.png";
	sunflower->picturenum = 17;
	sunflower->chessAnimation(sunflower->picturename, sunflower->picturenum, sunflower, sunflower->getPosition(), 0.08f, -1);
	sunflower->autorelease();
	return sunflower;
}
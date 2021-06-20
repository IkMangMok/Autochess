#pragma once
#include"Chomper.h"
#include"Data/GameData.h"
#include"Data/PlayerData.h"

Chomper::Chomper()
{
	type = chomper;
	AttackDistance = 75;
	Health = 1000;
	HealthLimit = Health;
	Damage = 140;
	Armor = 30;
	ManaOrigin = 300;
	Mana = ManaOrigin;
	ManaLimit = 300;
	AttackSpeed = 0.8f;
	CoinsNeeded = 3;
	SoldCoins = 3;
	star = 1;
	picturename = "Flower%d.png";
	picturenum = 12;
	chessAnimation(picturename, picturenum, this, getPosition(), 0.08f, -1);
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
}

Chomper* Chomper::createChess()
{
	auto chomper = Chomper::create();
	
	chomper->autorelease();
	return chomper;
}
void Chomper::Skill()
{
	if (AttackTarget->getHealth() < Health)
	{
		auto Damaged = AttackTarget->getHealth();
		AttackTarget->setHealth(-1);
		AttackTarget->Die();
		Hurted(-Damaged * 0.3f);
		AttackTarget = (Chess*)nullptr;
		Mana = 150;
	}
	else
	{
		auto Damaged = AttackTarget->getHealth() * Magic * (0.3 + 0.15 * star);
		AttackTarget->Hurted(Damaged);
		Hurted(-Damaged * 0.3f);
		Mana = 0;
	}
}
upgrade_Chomper::upgrade_Chomper()
{
	type = upgrade_chomper;
	AttackDistance = 75;
	Health = 1600;
	HealthLimit = Health;
	Damage = 180;
	Armor = 30;
	ManaOrigin = 300;
	Mana = ManaOrigin;
	ManaLimit = 300;
	AttackSpeed = 0.8f;
	CoinsNeeded = 0;
	SoldCoins = 8;
	star = 2;
}
upgrade_Chomper* upgrade_Chomper::createChess()
{
	auto chomper = upgrade_Chomper::create();
	chomper->picturename = "Flower%d.png";
	chomper->picturenum = 12;
	chomper->chessAnimation(chomper->picturename, chomper->picturenum, chomper, chomper->getPosition(), 0.08f, -1);

	chomper->autorelease();
	return chomper;
}

_3star_Chomper::_3star_Chomper()
{
	type = _3star_chomper;
	AttackDistance = 75;
	Health = 2200;
	HealthLimit = Health;
	Damage = 220;
	Armor = 30;
	ManaOrigin = 300;
	Mana = ManaOrigin;
	ManaLimit = 300;
	AttackSpeed = 0.8f;
	CoinsNeeded = 0;
	SoldCoins = 26;
	star = 3;
}
_3star_Chomper* _3star_Chomper::createChess()
{
	auto chomper = _3star_Chomper::create();
	chomper->autorelease();
	return chomper;
}
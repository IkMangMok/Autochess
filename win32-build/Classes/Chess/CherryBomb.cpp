#pragma once
#include"CherryBomb.h"
#include"Data/GameData.h"
#include"Data/PlayerData.h"

float CountDistance(Chess* c1, Chess* c2)
{
	return sqrt(pow((c1->getPosition().x - c2->getPosition().x), 2)
		+ pow((c1->getPosition().y - c2->getPosition().y), 2));
}

CherryBomb::CherryBomb()        
{
	type = cherrybomb;
	AttackDistance = 375;
	Health = 700;
	HealthLimit = Health;
	Damage = 140;
	Armor = 10;
	ManaOrigin = 50;
	Mana = ManaOrigin;
	ManaLimit = 100;
	AttackSpeed = 0.9f;
	CoinsNeeded = 3;
	SoldCoins = 3;
	star = 1;
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
}

CherryBomb* CherryBomb::createChess()
{
	auto cherrybomb = CherryBomb::create();
	cherrybomb->picturename = "Cherry%d.png";
	cherrybomb->picturenum = 6;
	cherrybomb->chessAnimation(cherrybomb->picturename, cherrybomb->picturenum, cherrybomb, cherrybomb->getPosition(), 0.08f, -1);
	cherrybomb->autorelease();
	return cherrybomb;
}
void CherryBomb::Skill()
{
	float hurt = (star == 1) ? 150 : (star == 2) ? 250 : 450;
	if (OfPlayer == 0)
	{
		for (int i = 0; i < player2data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player2data.FightArray->arr[i]));    //AOEÉËº¦
			if (temp->getPlayer() != OfPlayer && !temp->Die() && CountDistance(AttackTarget, temp) < 75)
			{
				temp->MagicHurt(hurt * Magic);
				Mana = 0;
			}
		}
	}
	if (OfPlayer == 1)
	{
		for (int i = 0; i < player1data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player1data.FightArray->arr[i]));
			if (temp->getPlayer() != OfPlayer && !temp->Die())
			{
				temp->MagicHurt(hurt * Magic);
				Mana = 0;
			}
		}
	}
}
upgrade_CherryBomb::upgrade_CherryBomb()
{
	type = upgrade_cherrybomb;
	AttackDistance = 375;
	Health = 1200;
	HealthLimit = Health;
	Damage = 180;
	Armor = 10;
	ManaOrigin = 50;
	Mana = ManaOrigin;
	ManaLimit = 100;
	AttackSpeed = 0.9f;
	CoinsNeeded = 0;
	SoldCoins = 8;
	star = 2;
}
upgrade_CherryBomb* upgrade_CherryBomb::createChess()
{
	auto cherrybomb = upgrade_CherryBomb::create();
	cherrybomb->picturename = "Cherry%d.png";
	cherrybomb->picturenum = 6;
	cherrybomb->chessAnimation(cherrybomb->picturename, cherrybomb->picturenum, cherrybomb, cherrybomb->getPosition(), 0.08f, -1);
	
	cherrybomb->autorelease();
	return cherrybomb;
}

_3star_CherryBomb::_3star_CherryBomb()
{
	type = _3star_cherrybomb;
	AttackDistance = 375;
	Health = 1800;
	HealthLimit = Health;
	Damage = 220;
	Armor = 10;
	ManaOrigin = 50;
	Mana = ManaOrigin;
	ManaLimit = 100;
	AttackSpeed = 0.9f;
	CoinsNeeded = 0;
	SoldCoins = 26;
	star = 3;
}
_3star_CherryBomb* _3star_CherryBomb::createChess()
{
	auto cherrybomb = _3star_CherryBomb::create();
	cherrybomb->picturename = "Cherry%d.png";
	cherrybomb->picturenum = 6;
	cherrybomb->chessAnimation(cherrybomb->picturename, cherrybomb->picturenum, cherrybomb, cherrybomb->getPosition(), 0.08f, -1);

	cherrybomb->autorelease();
	return cherrybomb;
}
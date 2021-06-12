#include"CherryBomb.h"

CherryBomb::CherryBomb()        
{
	type = cherrybomb;
	AttackDistance = 375;
	Health = 700;
	HealthLimit = Health;
	Damage = 125;
	Armor = 10;
	AttackSpeed = 0.9f;
	CoinsNeeded = 3;
	SoldCoins = 3;
	star = 1;
}

CherryBomb* CherryBomb::createChess()
{
	auto cherrybomb = CherryBomb::create();
	auto temp = Sprite::create("cherrybomb.png");
	cherrybomb->addChild(temp);
	cherrybomb->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / cherrybomb->AttackSpeed);
	cherrybomb->autorelease();
	return cherrybomb;
}

upgrade_CherryBomb::upgrade_CherryBomb()
{
	type = upgrade_cherrybomb;
	AttackDistance = 375;
	Health = 1200;
	HealthLimit = Health;
	Damage = 150;
	Armor = 10;
	AttackSpeed = 0.9f;
	CoinsNeeded = 0;
	SoldCoins = 8;
}
upgrade_CherryBomb* upgrade_CherryBomb::createChess()
{
	auto cherrybomb = upgrade_CherryBomb::create();
	auto temp = Sprite::create("cherrybomb.png");	
	cherrybomb->addChild(temp);
	cherrybomb->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / cherrybomb->AttackSpeed);
	cherrybomb->autorelease();
	return cherrybomb;
}
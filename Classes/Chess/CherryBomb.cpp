#include"CherryBomb.h"

CherryBomb::CherryBomb()        
{
	type = cherrybomb;
	AttackDistance = 375;
	Health = 700;
	HealthLimit = Health;
	Damage = 140;
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
	cherrybomb->Blood->setBarChangeRate(Point(1, 0));
	cherrybomb->Blood->setType(ProgressTimer::Type::BAR);
	cherrybomb->Blood->setMidpoint(Point(0, 1));
	cherrybomb->Blood->setScaleX(0.22);
	cherrybomb->scheduleUpdate();
	cherrybomb->addChild(cherrybomb->Blood, 2);
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
	Damage = 180;
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
	cherrybomb->Blood->setBarChangeRate(Point(1, 0));
	cherrybomb->Blood->setType(ProgressTimer::Type::BAR);
	cherrybomb->Blood->setMidpoint(Point(0, 1));
	cherrybomb->Blood->setScaleX(0.22);
	cherrybomb->scheduleUpdate();
	cherrybomb->addChild(cherrybomb->Blood, 2);
	cherrybomb->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / cherrybomb->AttackSpeed);
	cherrybomb->autorelease();
	return cherrybomb;
}
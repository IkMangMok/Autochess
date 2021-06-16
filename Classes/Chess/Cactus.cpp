#include"Cactus.h"

Cactus::Cactus()        
{
	type = cactus;
	AttackDistance = 750;
	Health = 400;
	HealthLimit = Health;
	Damage = 70;
	Armor = 20;
	AttackSpeed = 1.2f;
	CoinsNeeded = 3;
	SoldCoins = 3;
	star = 1;
}

Cactus* Cactus::createChess()
{
	auto cactus = Cactus::create();

	auto temp = Sprite::create("cactus.png");
	cactus->Blood->setBarChangeRate(Point(1, 0));
	cactus->Blood->setType(ProgressTimer::Type::BAR);
	cactus->Blood->setMidpoint(Point(0, 1));
	cactus->Blood->setScaleX(0.22);
	cactus->scheduleUpdate();
	cactus->addChild(cactus->Blood, 2);
	cactus->addChild(temp);
	cactus->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 60.0f);
	cactus->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / cactus->AttackSpeed);
	cactus->autorelease();
	return cactus;
}

upgrade_Cactus::upgrade_Cactus()
{
	type = upgrade_cactus;
	AttackDistance = 750;
	Health = 700;
	HealthLimit = Health;
	Damage = 100;
	Armor = 20;
	AttackSpeed = 1.2f;
	CoinsNeeded = 0;
	SoldCoins = 8;
	star = 2;
}

upgrade_Cactus* upgrade_Cactus::createChess()
{
	auto cactus = upgrade_Cactus::create();

	auto temp = Sprite::create("upgrade_cactus.png");
	cactus->Blood->setBarChangeRate(Point(1, 0));
	cactus->Blood->setType(ProgressTimer::Type::BAR);
	cactus->Blood->setMidpoint(Point(0, 1));
	cactus->Blood->setScaleX(0.22);
	cactus->scheduleUpdate();
	cactus->addChild(cactus->Blood, 2);
	cactus->addChild(temp);
	cactus->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 60.0f);
	cactus->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / cactus->AttackSpeed);
	cactus->autorelease();
	return cactus;
}
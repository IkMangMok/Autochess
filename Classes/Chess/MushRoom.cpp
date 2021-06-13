#include"MushRoom.h"

MushRoom::MushRoom()
{
	type = mushroom;
	AttackDistance = 225;
	Health = 400;
	HealthLimit = Health;
	Damage = 100;
	Armor = 15;
	AttackSpeed = 1.1f;
	CoinsNeeded = 2;
	SoldCoins = 2;
	star = 1;
}

MushRoom* MushRoom::createChess()
{
	auto mushroom = MushRoom::create();
	mushroom->Blood->setBarChangeRate(Point(1, 0));
	mushroom->Blood->setType(ProgressTimer::Type::BAR);
	mushroom->Blood->setMidpoint(Point(0, 1));
	mushroom->Blood->setScaleX(0.22);
	mushroom->scheduleUpdate();
	mushroom->addChild(mushroom->Blood, 2);
	auto temp = Sprite::create("mushroom.png");
	mushroom->addChild(temp);
	mushroom->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / mushroom->AttackSpeed);
	mushroom->autorelease();
	return mushroom;
}

upgrade_MushRoom::upgrade_MushRoom()
{
	type = upgrade_mushroom;
	AttackDistance = 225;
	Health = 700;
	HealthLimit = Health;
	Damage = 120;
	Armor = 15;
	AttackSpeed = 1.1f;
	CoinsNeeded = 2;
	SoldCoins = 2;
	star = 1;
}

upgrade_MushRoom* upgrade_MushRoom::createChess()
{
	auto mushroom = upgrade_MushRoom::create();
<<<<<<< Updated upstream

=======
	mushroom->Blood->setBarChangeRate(Point(1, 0));
	mushroom->Blood->setType(ProgressTimer::Type::BAR);
	mushroom->Blood->setMidpoint(Point(0, 1));
	mushroom->Blood->setScaleX(0.22);
	mushroom->scheduleUpdate();
	mushroom->addChild(mushroom->Blood, 2);
>>>>>>> Stashed changes
	auto temp = Sprite::create("upgrade_mushroom.png");
	mushroom->addChild(temp);
	mushroom->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / mushroom->AttackSpeed);
	mushroom->autorelease();
	return mushroom;
}
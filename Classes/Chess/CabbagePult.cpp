#include"CabbagePult.h"

CabbagePult::CabbagePult()       
{
	type = cabbagepult;
	AttackDistance = 225;
	Health = 600;
	HealthLimit = Health;
	Damage = 90;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 2;
	SoldCoins = 2;
	star = 1;
}

CabbagePult* CabbagePult::createChess()
{
	auto CabbagePult = CabbagePult::create();

	auto temp = Sprite::create("cabbagepult.png");
	CabbagePult->Blood->setBarChangeRate(Point(1, 0));
	CabbagePult->Blood->setType(ProgressTimer::Type::BAR);
	CabbagePult->Blood->setMidpoint(Point(0, 1));
	CabbagePult->Blood->setScaleX(0.22);
	CabbagePult->scheduleUpdate();
	CabbagePult->addChild(CabbagePult->Blood, 2);
	CabbagePult->addChild(temp);
	CabbagePult->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / CabbagePult->AttackSpeed);
	CabbagePult->autorelease();
	
	return CabbagePult;
}

upgrade_CabbagePult::upgrade_CabbagePult()
{
	type = upgrade_cabbagepult;
	AttackDistance = 225;
	Health = 800;
	HealthLimit = Health;
	Damage = 120;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 4;
	star = 2;
}

upgrade_CabbagePult* upgrade_CabbagePult::createChess()
{
	auto CabbagePult = upgrade_CabbagePult::create();

	auto temp = Sprite::create("upgrade_cabbagepult.png");
	CabbagePult->Blood->setBarChangeRate(Point(1, 0));
	CabbagePult->Blood->setType(ProgressTimer::Type::BAR);
	CabbagePult->Blood->setMidpoint(Point(0, 1));
	CabbagePult->Blood->setScaleX(0.22);
	CabbagePult->addChild(CabbagePult->Blood, 2);
	CabbagePult->scheduleUpdate();
	CabbagePult->addChild(temp);
	CabbagePult->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / CabbagePult->AttackSpeed);
	CabbagePult->autorelease();
	return CabbagePult;
}
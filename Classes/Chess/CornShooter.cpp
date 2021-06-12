#include"CornShooter.h"

CornShooter::CornShooter()       
{
	type = cornshooter;
	AttackDistance = 225;
	Health = 600;
	HealthLimit = Health;
	Damage = 90;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 2;
	SoldCoins = 2;
}

CornShooter* CornShooter::createChess()
{
	auto CornShooter = CornShooter::create();

	auto temp = Sprite::create("cornshooter.png");
	CornShooter->addChild(temp);
	CornShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / CornShooter->AttackSpeed);
	CornShooter->autorelease();
	return CornShooter;
}

upgrade_CornShooter::upgrade_CornShooter()
{
	type = upgrade_cornshooter;
	AttackDistance = 225;
	Health = 900;
	HealthLimit = Health;
	Damage = 120;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 5;
	star = 1;
}

upgrade_CornShooter* upgrade_CornShooter::createChess()
{
	auto CornShooter = upgrade_CornShooter::create();

	auto temp = Sprite::create("cornshooter.png");
	CornShooter->addChild(temp);
	CornShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / CornShooter->AttackSpeed);
	CornShooter->autorelease();
	return CornShooter;
}
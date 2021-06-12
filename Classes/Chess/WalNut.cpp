#include"WalNut.h"

WalNut::WalNut()        //�������룺ͨ�����ܿ���Ⱥ���Ѫ���ý��/����
{
	type = walnut;
	AttackDistance = 80;
	Health = 1200;
	HealthLimit = Health;
	Damage = 30;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 1;
	star = 1;
}

WalNut* WalNut::createChess()
{
	auto walnut = WalNut::create();

	auto temp = Sprite::create("walnut.png");
	walnut->addChild(temp);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / walnut->AttackSpeed);
	walnut->autorelease();
	return walnut;
}

upgrade_WalNut::upgrade_WalNut()        //�������룺ͨ�����ܿ���Ⱥ���Ѫ���ý��/����
{
	type = upgrade_walnut;
	AttackDistance = 80;
	Health = 2000;
	HealthLimit = Health;
	Damage = 50;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 3;
	star = 2;
}

upgrade_WalNut* upgrade_WalNut::createChess()
{
	auto walnut = upgrade_WalNut::create();

	auto temp = Sprite::create("upgrade_walnut.png");
	walnut->addChild(temp);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / walnut->AttackSpeed);
	walnut->autorelease();
	return walnut;
}
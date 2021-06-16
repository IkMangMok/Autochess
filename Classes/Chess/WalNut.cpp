#include"WalNut.h"

WalNut::WalNut()        //�������룺ͨ�����ܿ���Ⱥ���Ѫ���ý��/����
{
	type = walnut;
	AttackDistance = 80;
	Health = 1200;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 80;
	Damage = 38;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 1;
	star = 1;
}
void WalNut::Skill()
{
	TimeSet = 5.0f;
	HurtRate = 0.8 - (0.1 * star);
	Mana = 0;
}
void WalNut::update(float dt)
{
	
	if (Mana == ManaLimit)           //�ͷż���
	{
		Skill();
		SkillFlag = 1;
	}
	if (SkillFlag)
	{
		TimeSet -= dt;
	}
	if (fabs(TimeSet) < 1e-1 && SkillFlag)
	{
		HurtRate = 1.0f;
		SkillFlag = 0;
	}
}
WalNut* WalNut::createChess()
{
	auto walnut = WalNut::create();
	walnut->Blood->setBarChangeRate(Point(1, 0));
	walnut->Blood->setType(ProgressTimer::Type::BAR);
	walnut->Blood->setMidpoint(Point(0, 1));
	walnut->Blood->setScaleX(0.22);
	walnut->scheduleUpdate();
	walnut->addChild(walnut->Blood, 2);
	auto temp = Sprite::create("walnut.png");
	walnut->addChild(temp);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 60.0f);
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
	Mana = 0;
	ManaLimit = 80;
	Damage = 60;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 3;
	star = 2;
}

upgrade_WalNut* upgrade_WalNut::createChess()
{
	auto walnut = upgrade_WalNut::create();
	walnut->Blood->setBarChangeRate(Point(1, 0));
	walnut->Blood->setType(ProgressTimer::Type::BAR);
	walnut->Blood->setMidpoint(Point(0, 1));
	walnut->Blood->setScaleX(0.22);
	walnut->scheduleUpdate();
	walnut->addChild(walnut->Blood, 2);
	auto temp = Sprite::create("upgrade_walnut.png");
	walnut->addChild(temp);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 60.0f);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / walnut->AttackSpeed);
	walnut->autorelease();
	return walnut;
}
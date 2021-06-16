#include"CornShooter.h"

CornShooter::CornShooter()       
{
	type = cornshooter;
	AttackDistance = 225;
	Health = 600;
	HealthLimit = Health;
	ManaOrigin = 0;
	Mana = ManaOrigin;
	ManaLimit = 100;
	Damage = 100;
	Armor = 20;
	AttackSpeed = 0.7f;
	CoinsNeeded = 2;
	SoldCoins = 2;
}
void CornShooter::Skill()
{
	float SDamage = ((star == 1) ? 100.f : (star == 2) ? 200.f : (star == 3) ? 450.f : 200.f);
	TimeSet = 0.5f + 0.5 * star;
	AttackTarget->MagicHurt(SDamage * Magic);      //造成伤害
	AttackTarget->setAttackSpeed((AttackTarget->getAttackSpeed()) / 2);          //减速50%
	Mana = 0;

}
void CornShooter::update(float dt)
{
	if (fabs(Mana - ManaLimit) < 1e-6 && AttackTarget != (Chess*)NULL)           //释放技能
	{
		Skill();
		SkillFlag = 1;
	}
	if (SkillFlag)
	{
		TimeSet -= dt;
	}
	if (fabs(TimeSet) < 1e-1 && SkillFlag && AttackTarget != (Chess*)NULL)
	{ 
		AttackTarget->setAttackSpeed(AttackTarget->getTempAttackSpeed());
		SkillFlag = 0;
	}
}
CornShooter* CornShooter::createChess()
{
	auto CornShooter = CornShooter::create();
	CornShooter->Blood->setBarChangeRate(Point(1, 0));
	CornShooter->Blood->setType(ProgressTimer::Type::BAR);
	CornShooter->Blood->setMidpoint(Point(0, 1));
	CornShooter->Blood->setScaleX(0.22);
	CornShooter->scheduleUpdate();
	CornShooter->addChild(CornShooter->Blood, 2);
	auto temp = Sprite::create("cornshooter.png");
	CornShooter->addChild(temp);
	CornShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 60.0f);
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
	ManaOrigin = 0;
	Mana = ManaOrigin;
	ManaLimit = 100;
	Damage = 140;
	Armor = 20;
	AttackSpeed = 0.7f;
	CoinsNeeded = 0;
	SoldCoins = 5;
	star = 1;
}

upgrade_CornShooter* upgrade_CornShooter::createChess()
{
	auto CornShooter = upgrade_CornShooter::create();
	CornShooter->Blood->setBarChangeRate(Point(1, 0));
	CornShooter->Blood->setType(ProgressTimer::Type::BAR);
	CornShooter->Blood->setMidpoint(Point(0, 1));
	CornShooter->Blood->setScaleX(0.22);
	CornShooter->scheduleUpdate();
	CornShooter->addChild(CornShooter->Blood, 2);
	auto temp = Sprite::create("cornshooter.png");
	CornShooter->addChild(temp);
	CornShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 60.0f);
	CornShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / CornShooter->AttackSpeed);
	CornShooter->autorelease();
	return CornShooter;
}
#include"SunFlower.h"

SunFlower::SunFlower()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = sunflower;
	AttackDistance = 750;
	Health = 300;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 50;
	Magic = 1.0f;
	Damage = 60;
	Armor = 5;
	AttackSpeed = 0.8f;
	CoinsNeeded = 1;
	SoldCoins = 1;
	star = 1;
}

SunFlower* SunFlower::createChess()
{
	auto sunflower = SunFlower::create();
	sunflower->Blood->setBarChangeRate(Point(1, 0));
	sunflower->Blood->setType(ProgressTimer::Type::BAR);
	sunflower->Blood->setMidpoint(Point(0, 1));
	sunflower->Blood->setScaleX(0.22);
	sunflower->scheduleUpdate();
	sunflower->addChild(sunflower->Blood, 2);
	auto temp = Sprite::create("sunflower.png");
	sunflower->addChild(temp);
	sunflower->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 60.0f);
	sunflower->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / sunflower->AttackSpeed);
	sunflower->autorelease();
	return sunflower;
}
void SunFlower::Skill()
{
	if (OfPlayer == 0)
	{
		for (int i = 0; i < player1data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player1data.FightArray->arr[i]));
				if (temp->getPlayer() == OfPlayer && !temp->Die())
				{
					temp->MagicHurt(-(50 + 50 * star) * Magic);
						Mana = 0;
				}
		}
	}
	if (OfPlayer == 1)
	{
		for (int i = 0; i < player2data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player2data.FightArray->arr[i]));
			if (temp->getPlayer() == OfPlayer && !temp->Die())
			{
				temp->MagicHurt(-(50 + 50 * star) * Magic);
				Mana = 0;
			}
		}
	}
}
upgrade_SunFlower::upgrade_SunFlower()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = upgrade_sunflower;
	AttackDistance = 750;
	Health = 500;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 50;
	Magic = 1.0f;
	Damage = 90;
	Armor = 5;
	AttackSpeed = 0.8f;
	CoinsNeeded = 0;
	SoldCoins = 3;
	star = 2;
}

upgrade_SunFlower* upgrade_SunFlower::createChess()
{
	auto sunflower = upgrade_SunFlower::create();
	sunflower->Blood->setBarChangeRate(Point(1, 0));
	sunflower->Blood->setType(ProgressTimer::Type::BAR);
	sunflower->Blood->setMidpoint(Point(0, 1));
	sunflower->Blood->setScaleX(0.22);
	sunflower->scheduleUpdate();
	sunflower->addChild(sunflower->Blood, 2);
	auto temp = Sprite::create("upgrade_sunflower.png");
	sunflower->addChild(temp);
	sunflower->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 60.0f);
	sunflower->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / sunflower->AttackSpeed);
	sunflower->autorelease();
	return sunflower;
}
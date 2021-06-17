#include"WalNut.h"

WalNut::WalNut()        //初步设想：通过技能可以群体回血或获得金币/经验
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
	SkillTime->pTime = 5.0f;
	HurtRate = 0.8 - (0.1 * star);
	Mana = 0;
	SkillTime->scheduleUpdate();
}
void WalNut::update(float dt)
{
	Blood->setPosition(Vec2(0, 40));
	Blood->setPercentage(float(Health) / float(HealthLimit) * 100);
	Blood->setTag(Health);
	if (Mana == ManaLimit)           //释放技能
	{
		Skill();
		flag = 1;
	}
	if (SkillTime->pTime < -1e-6 && flag)
	{
		HurtRate = 1.0f;
		flag = 0;
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
	auto action = walnut->chessAnimation("nut%d.png", 15, walnut, walnut->getPosition());
	temp->runAction(action);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / walnut->AttackSpeed);
	walnut->autorelease();
	return walnut;
}

upgrade_WalNut::upgrade_WalNut()        //初步设想：通过技能可以群体回血或获得金币/经验
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
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / walnut->AttackSpeed);
	walnut->autorelease();
	return walnut;
}

Animate* WalNut::chessAnimation(string picturename, const int picturenum, Chess* mychess,Point location, const float speed, const int loop )
{
	/*Sprite* sp = Sprite::create(picturename);
	sp->setPosition(location);
	mychess->addChild(sp);*/
	// sp->setFlippedX(true);//相对位置关系，先保留

	Animation* animation = Animation::create();

	const char* picname = picturename.c_str();

	for (int i = 0; i <= picturenum; i++) {
		char key[32];
		sprintf(key, picname, i);
		animation->addSpriteFrameWithFile(key);
	}

	animation->setDelayPerUnit(speed); //设定速度
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(loop); //loop=-1,循环

	auto action = Animate::create(animation);
	//sp->runAction(animate);
	return action;
}
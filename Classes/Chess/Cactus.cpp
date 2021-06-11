#include"Cactus.h"

Cactus::Cactus()        
{
	type = cactus;
	AttackDistance = 750;
	Health = 700;
	HealthLimit = Health;
	Damage = 150;
	Armor = 20;
	AttackSpeed = 1.2f;
	CoinsNeeded = 3;
}

Cactus* Cactus::createChess()
{
	auto cactus = Cactus::create();

	auto temp = Sprite::create("cactus.png");
	cactus->width = temp->getContentSize().width;
	cactus->height = temp->getContentSize().height;
	cactus->addChild(temp);
	cactus->setPosition(cactus->x, cactus->y);
	cactus->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / cactus->AttackSpeed);
	cactus->autorelease();
	return cactus;
}
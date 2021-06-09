#include"WalNut.h"

WalNut::WalNut()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	AttackDistance = 75;
	Health = 1200;
	HealthLimit = Health;
	Damage = 30;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 1;
}

WalNut* WalNut::createChess()
{
	auto walnut = WalNut::create();

	auto temp = Sprite::create("walnut.png");
	walnut->width = temp->getContentSize().width;
	walnut->height = temp->getContentSize().height;
	walnut->addChild(temp);
	walnut->setPosition(walnut->x, walnut->y);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / walnut->AttackSpeed);
	walnut->autorelease();
	return walnut;
}
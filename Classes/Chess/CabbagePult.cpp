#include"CabbagePult.h"

CabbagePult::CabbagePult()       
{
	AttackDistance = 225;
	Health = 600;
	HealthLimit = Health;
	Damage = 90;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 2;
}

CabbagePult* CabbagePult::createChess()
{
	auto CabbagePult = CabbagePult::create();

	auto temp = Sprite::create("cabbagepult.png");
	CabbagePult->width = temp->getContentSize().width;
	CabbagePult->height = temp->getContentSize().height;
	CabbagePult->addChild(temp);
	CabbagePult->setPosition(CabbagePult->x, CabbagePult->y);
	CabbagePult->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / CabbagePult->AttackSpeed);
	CabbagePult->autorelease();
	return CabbagePult;
}
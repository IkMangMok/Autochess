#include"PeaShooter.h"
#include"cocos2d.h"
#include"AppDelegate.h"
using namespace cocos2d;
USING_NS_CC;

PeaShooter::PeaShooter()
{
	 AttackDistance = 500;  
	 Health = 600;          
	 Damage = 80;
	 AttackSpeed = 1.0f;
}
PeaShooter* PeaShooter::createChess(string picture_name, float x1 = 0., float y1 = 0.)
{

	auto peaShooter = PeaShooter::create();
	peaShooter->set(x1, y1);

	auto temp = Sprite::create(picture_name);
	peaShooter->width = temp->getContentSize().width;
	peaShooter->height = temp->getContentSize().height;
	peaShooter->addChild(temp);
	peaShooter->setPosition(peaShooter->x, peaShooter->y);
	peaShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / peaShooter->AttackSpeed);
	peaShooter->autorelease();
	return peaShooter;

}
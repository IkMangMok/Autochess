#include"Chess1.h"
#include<string>
#include"cocos2d.h"
#include"AppDelegate.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;
#define schedule_selector(_SELECTOR) static_cast(&_SELECTOR)

Chess* Chess::createChess(string picture_name, float x1 = 0., float y1 = 0.)
{

	auto chess = new  Chess();
	chess->set(x1, y1);

	auto temp = Sprite::create(picture_name);

	chess->addChild(temp);
	chess->setPosition(chess->x, chess->y);
	chess->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / chess->AttackSpeed);
	chess->autorelease();
	return chess;
	
}


void Chess::set(float x1 = 0, float y1 = 0)  //传入数值，有两种重载形式
{
	x = x1;
	y = y1;
}
void Chess::set(Point point)
{
	x = point.x;
	y = point.y;
}

Point Chess::getPosition()
{
	return Point(x, y);
}

void Chess::Attack(float dt)
{
	if (AttackTarget != NULL && !Die())
	{
		float  distance = sqrt((AttackTarget->getPosition().x - x)  //获得距离
			* (AttackTarget->getPosition().x - x) +
			(AttackTarget->getPosition().y - y)
			* (AttackTarget->getPosition().y - y));
		if (distance < AttackDistance)                           //小于攻击距离则开始攻击
		{
			AttackTarget->Hurted(Damage);
			if (AttackTarget->Die())
				AttackTarget = NULL;
		}
	}
}

void Chess::Hurted(int Damage)
{
	Health -= Damage;
}

bool Chess::Die()
{
	if (Health <= 0)
	{
		setPosition(Point(10000, 10000));
		set(10000, 10000);
		return 1;
	}
	else
		return 0;
}
int Chess::GetAttackDistance()
{
	return AttackDistance;
}
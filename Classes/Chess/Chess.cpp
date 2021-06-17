#include"Chess.h"
#include<string>
#include"cocos2d.h"
#include"AppDelegate.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;

Chess* Chess::createChess(string picture_name)
{

	auto chess = new  Chess();

	auto temp = Sprite::create(picture_name);
	chess->Blood->setBarChangeRate(Point(1, 0));
	chess->Blood->setType(ProgressTimer::Type::BAR);
	chess->Blood->setMidpoint(Point(0, 1));
	chess->Blood->setPercentage(100);
	chess->Blood->setContentSize(Size(75, 10));
	chess->addChild(chess->Blood, 2);
	chess->addChild(temp);
	
	chess->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / chess->AttackSpeed);
	chess->scheduleUpdate();
	chess->autorelease();
	return chess;
	
}


void Chess::set(float x1 = 0, float y1 = 0)  //传入数值，有两种重载形式
{
	x = x1;
	y = y1;
}

Point Chess::getPosition()
{
	return Point(x, y);
}

void Chess::Attack(float dt)
{
  //  if (test_timer->pTime <= 0)
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
				Mana += 10;
				
                if (AttackTarget->Die())
                    AttackTarget = NULL;
            }
        }
    }
}

void Chess::Hurted(int Damage)
{
	if (Damage > 0)
	{
		Health = Health - Damage * (1.0f - Armor / (Armor + 100)) * HurtRate;    //受伤
		Mana = min(Mana + Damage / 10, ManaLimit);
	}
	else
	{
		Health = min(HealthLimit, Health - Damage);      //回血
	}
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
void Chess::update(float dt)
{
	Blood->setPosition(Vec2(0, 40));
	Blood->setPercentage(float(Health) / float(HealthLimit) * 100);
	Blood->setTag(Health);
	if (Mana == ManaLimit)           //释放技能
	{
		Skill();
	}
}
 void Chess::recover() 
 {
	Mana = ManaOrigin; 
	Health = HealthLimit;
	AttackTarget = (Chess*)NULL;
	Blood->setPercentage(100.f);
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / this->AttackSpeed);
	this->scheduleUpdate();
}


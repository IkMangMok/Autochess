#include"Chess1.h"
#include<string>
#include"cocos2d.h"
#include"AppDelegate.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;

Chess* Chess::createChess(string picture_name, Point point = Point(0, 0))
{

	auto chess = new  Chess();
	chess->set(point);

	auto temp = Sprite::create(picture_name);

	chess->addChild(temp);
	chess->setPosition(chess->x, chess->y);
	chess->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / chess->AttackSpeed);
   // chess->schedule(CC_SCHEDULE_SELECTOR(Chess::Move), 1.f / 60);
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
                if (AttackTarget->Die())
                    AttackTarget = NULL;
            }
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
void Chess::Move(float dt)
{
   // if (test_timer->pTime <= 0)
    {
        Point a(0, 0);
        Point chessPosition = getPosition();
        float distance = 9999999;
        if (AttackTarget == NULL || AttackTarget->Die())    //如果已经有攻击目标则不搜寻
        {
            for (int i = 0; i < pArray->num; i++)
            {
                auto temp = pArray->arr[i];
                Point atemp = ((Chess*)temp)->getPosition();
                float distanceTemp = sqrt((atemp.x - chessPosition.x) * (atemp.x - chessPosition.x) +
                    (atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //求距离
                if (distanceTemp < distance && distanceTemp>0) //确定攻击目标
                {
                    distance = distanceTemp;
                    a = atemp;
                    AttackTarget = (Chess*)temp;
                }
            }
        }
        else
        {
            distance = sqrt((AttackTarget->getPosition().x - chessPosition.x)
                * (AttackTarget->getPosition().x - chessPosition.x) +
                (AttackTarget->getPosition().y - chessPosition.y)
                * (AttackTarget->getPosition().y - chessPosition.y));
        }
        /*移动，以1e-2为单位移动
        */
        if (AttackTarget == NULL)  //无攻击目标则结束
        {
            return;
        }
        if (distance >= GetAttackDistance() && !AttackTarget->Die())    //距离大于射程且目标没死则移动
        {
            setPosition(getPosition() + (AttackTarget->getPosition() - getPosition()) * (float)1e-2);
            set(getPosition() + (AttackTarget->getPosition() - getPosition()) * (float)1e-2);  //将新位置传入类中
             //除以模长乘上固定参数即可改进
        }
    }
}

Point Chess::getTempPosition()
{
    return Point(xtemp, ytemp);
}
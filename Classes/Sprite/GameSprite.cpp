#include"GameSprite.h"

GameSprite* GameSprite::createGameSprite()
{
	auto temp = GameSprite::create();
	temp->retain();
	return temp;
}
bool GameSprite::init()
{

    return true;
}
void GameSprite::ChessMove(Chess* chess)
{
    
    Point a(0, 0);
    Point chessPosition = chess->getPosition();
    float distance = 9999999;
    if (chess->AttackTarget == NULL || chess->AttackTarget->Die())    //如果已经有攻击目标则不搜寻
    {
        for (int i = 0; i < FightArray->num; i++)
        {
            auto temp = FightArray->arr[i];
            Point atemp = ((Chess*)temp)->getPosition();
            float distanceTemp = sqrt((atemp.x - chessPosition.x) * (atemp.x - chessPosition.x) +
                (atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //求距离
            if (distanceTemp < distance && distanceTemp>0) //确定攻击目标
            {
                distance = distanceTemp;
                a = atemp;
                chess->AttackTarget = (Chess*)temp;
            }
        }
    }
    else
    {
        distance = sqrt((chess->AttackTarget->getPosition().x - chessPosition.x)
            * (chess->AttackTarget->getPosition().x - chessPosition.x) +
            (chess->AttackTarget->getPosition().y - chessPosition.y)
            * (chess->AttackTarget->getPosition().y - chessPosition.y));
    }
    //移动，以1e-2为单位移动

    if (chess->AttackTarget == NULL)  //无攻击目标则结束
    {
        return;
    }
    if (distance >= chess->GetAttackDistance() && !chess->AttackTarget->Die())    //距离大于射程且目标没死则移动
    {
        chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) / distance * 6);
        chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) / distance * 6);  //将新位置传入类中
        
    }
        //连续移动
}

void GameSprite::update(float dt)
{
   
    for (int i = 0; i < FightArray->num; i++)
    {
        ChessMove((Chess*)(FightArray->arr[i]));
    }
}



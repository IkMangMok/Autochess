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
    if (chess->AttackTarget == NULL || chess->AttackTarget->Die())    //����Ѿ��й���Ŀ������Ѱ
    {
        for (int i = 0; i < FightArray->num; i++)
        {
            auto temp = FightArray->arr[i];
            Point atemp = ((Chess*)temp)->getPosition();
            float distanceTemp = sqrt((atemp.x - chessPosition.x) * (atemp.x - chessPosition.x) +
                (atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //�����
            if (distanceTemp < distance && distanceTemp>0) //ȷ������Ŀ��
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
    //�ƶ�����1e-2Ϊ��λ�ƶ�

    if (chess->AttackTarget == NULL)  //�޹���Ŀ�������
    {
        return;
    }
    if (distance >= chess->GetAttackDistance() && !chess->AttackTarget->Die())    //������������Ŀ��û�����ƶ�
    {
        chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) / distance * 6);
        chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) / distance * 6);  //����λ�ô�������
        
    }
        //�����ƶ�
}

void GameSprite::update(float dt)
{
   
    for (int i = 0; i < FightArray->num; i++)
    {
        ChessMove((Chess*)(FightArray->arr[i]));
    }
}



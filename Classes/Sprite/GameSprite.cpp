#include"GameSprite.h"

GameSprite* GameSprite::createGameSprite()
{
	auto temp = GameSprite::create();
	temp->retain();
	return temp;
}
void GameSprite::PlayerArrayInit(ccArray* Array)
{
    for (int i = 0; i < Array->num; i++)
    {
        auto temp = ((Chess*)Array->arr[i]);
        temp->setPosition(temp->getTempPosition());
        temp->set(temp->getTempPosition());
        this->addChild(temp);
    }
}
bool GameSprite::init()
{
    PlayerArrayInit(player1data.PlayerArray);
    PlayerArrayInit(player2data.PlayerArray);
    PlayerArrayInit(player1data.FightArray);
    PlayerArrayInit(player2data.FightArray);

    return true;
}
IntMap GameSprite::MapIntReturn(Point point)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (sqrt((point.x - mapPosition[i][j].x) * (point.x - mapPosition[i][j].x)    //������ͼ���ж��Ƿ��ڸ�����
                + (point.y - mapPosition[i][j].y) * (point.y - mapPosition[i][j].y)) < 37.5 * sqrt(2))
                return IntMap(i, j);    //������ɢ������
        }
    }
    return IntMap(-1, -1);
}

void GameSprite::ChessMove(Chess* chess, PlayerData& playerdata)
{
    
    Point a(0, 0);
    Point chessPosition = chess->getPosition();
    float distance = 9999999;
    if (chess->AttackTarget == NULL || chess->AttackTarget->Die())    //����Ѿ��й���Ŀ������Ѱ
    {
        for (int i = 0; i < playerdata.FightArray->num; i++)
        {
            auto temp = playerdata.FightArray->arr[i];
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
    for (int i = 0; i < player1data.FightArray->num; i++)
    {
        ChessMove((Chess*)(player1data.FightArray->arr[i]), player1data);
    }
    for (int i = 0; i < player2data.FightArray->num; i++)
    {
        ChessMove((Chess*)(player2data.FightArray->arr[i]), player2data);
    }
}

void GameSprite::upgrade(float dt)
{
    Chess* temp[3] = { NULL,NULL,NULL };
    ccArray* tempArray[3] = {};
    int s = 0;  //��������������
    for (int i = 0; i < ChessNumber; i++)
    {
        if (player1data.chessnumber[i] >= 3)
        {
            for (int j = 0; j < player1data.PlayerArray->num; j++)
            {
                if (((Chess*)(player1data.PlayerArray->arr[j]))->getType() == i)
                {
                    temp[s] = ((Chess*)(player1data.PlayerArray->arr[j]));
                    tempArray[s] = player1data.PlayerArray;
                    s++;
                    if (s == 3)
                        break;

                }
            }
            if (temp[0] == NULL || temp[1] == NULL || temp[2] == NULL)   //���ڱ�ս��ûѰ�������������ս������
            {
                for (int j = 0; j < player1data.FightArray->num; j++)
                {
                    if (((Chess*)(player1data.FightArray->arr[j]))->getType() == i)
                    {
                        temp[s] = ((Chess*)(player1data.FightArray->arr[j]));
                        tempArray[s] = player1data.FightArray;
                        s++;
                        if (s == 3)
                            break;

                    }
                }
            }
            if (temp[0] != NULL && temp[1] != NULL && temp[2] != NULL)
            {
                auto upgrade_chess = upgradeChessCreate(i);
                for (int i = 0; i < 3; i++)
                {
                    ChessExist[MapIntReturn(temp[i]->getTempPosition()).x][MapIntReturn(temp[i]->getTempPosition()).y] = 0;
                    this->removeChild(temp[i]);
                    ccArrayRemoveObject(tempArray[i], temp[i]);
                }
                player1data.chessnumber[i] -= 3;
                ccArrayAppendObject(player1data.PlayerArray, upgrade_chess);            
                player1data.HaveNewChess = 1;
                return;
            }
            
        }
        
    }
}
Chess* GameSprite::upgradeChessCreate(int type)
{
    switch (type + 8)
    {
        case upgrade_sunflower:
            return upgrade_SunFlower::createChess();
            break;
        case upgrade_cactus:
            return upgrade_Cactus::createChess();
            break;
        case upgrade_cherrybomb:
            return upgrade_CherryBomb::createChess();
            break;
        case upgrade_cornshooter:
            return upgrade_CornShooter::createChess();
            break;
        case upgrade_walnut:
            return upgrade_WalNut::createChess();
            break;
        case upgrade_mushroom:
            return upgrade_MushRoom::createChess();
            break;
        case upgrade_pealauncher:
            return upgrade_PeaShooter::createChess();
            break;
        case upgrade_cabbagepult:
            return upgrade_CabbagePult::createChess();
            break;
        default:
            break;
    }

}


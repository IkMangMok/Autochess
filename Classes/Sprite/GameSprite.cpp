#include"GameSprite.h"

Chess* CreateChess(int type)
{
    switch (type)
    {
        case walnut:
            return WalNut::createChess();
            break;
        case pealauncher:
            return PeaShooter::createChess();
            break;
        case mushroom:
            return MushRoom::createChess();
            break;
        case sunflower:
            return SunFlower::createChess();
            break;
        case chomper:
            return Chomper::createChess();
            break;
        case cherrybomb:
            return CherryBomb::createChess();
            break;
        case ga_peashooter:
            return Ga_PeaShooter::createChess();
            break;
        case tomatoboom:
            return TomatoBoom::createChess();
            break;
        case upgrade_sunflower:
            return upgrade_SunFlower::createChess();
            break;
        case upgrade_chomper:
            return upgrade_Chomper::createChess();
            break;
        case upgrade_cherrybomb:
            return upgrade_CherryBomb::createChess();
            break;
        case upgrade_ga_peashooter:
            return upgrade_Ga_PeaShooter::createChess();
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
        case upgrade_tomatoboom:
            return upgrade_TomatoBoom::createChess();
            break;
        case _3star_sunflower:
            return _3star_SunFlower::createChess();
            break;
        case _3star_chomper:
            return _3star_Chomper::createChess();
            break;
        case _3star_cherrybomb:
            return _3star_CherryBomb::createChess();
            break;
        case _3star_ga_peashooter:
            return _3star_Ga_PeaShooter::createChess();
            break;
        case _3star_walnut:
            return _3star_WalNut::createChess();
            break;
        case _3star_mushroom:
            return _3star_MushRoom::createChess();
            break;
        case _3star_pealauncher:
            return _3star_PeaShooter::createChess();
            break;
        case _3star_tomatoboom:
            return _3star_TomatoBoom::createChess();
            break;
        default:
            break;
    }
}
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
       
        auto temp1 = CreateChess(temp->getType());
        temp1->setPosition(temp->getTempPosition());
        temp1->set(temp->getTempPosition());
        temp1->setTempPosition();
        temp1->setPlayer(temp->getPlayer());
        ccArrayRemoveObject(Array, temp);
        ccArrayInsertObjectAtIndex(Array, temp1, i);
        this->addChild(temp1);
        ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 1;
        
        
    }
}
bool GameSprite::init()
{
    PlayerArrayInit(player1data.PlayerArray);
    PlayerArrayInit(player2data.PlayerArray);      //  电脑玩家信息暂不显示
    PlayerArrayInit(player1data.FightArray);
    PlayerArrayInit(player2data.FightArray);
   
    return true;
}


void GameSprite::ChessMove(Chess* chess, PlayerData& playerdata, PlayerData& AttackPlayer)
{
    
    Point a(0, 0);
    Point chessPosition = chess->getPosition();
    float distance = 9999999;
   
   
     
    for (int i = 0; i < AttackPlayer.FightArray->num; i++)
    {
        auto temp = AttackPlayer.FightArray->arr[i];
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
    
    if (chess->AttackTarget != (Chess*)nullptr)
    {
        distance = CountDistance(chess, chess->AttackTarget);
    }
    //移动，以1e-2为单位移动

    else if (chess->AttackTarget == (Chess*)nullptr)  //无攻击目标则结束
    {
        return;
    }
    if (distance >= chess->GetAttackDistance() && !chess->AttackTarget->Die())    //距离大于射程且目标没死则移动
    {  
        chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) / distance * chess->getSpeed());
        chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) / distance * chess->getSpeed());  //将新位置传入类中
    }
        //连续移动
}

void GameSprite::update(float dt)
{
    for (int i = 0; i < player1data.FightArray->num; i++)
    {
        ChessMove((Chess*)(player1data.FightArray->arr[i]), player1data, player2data);
    }
    for (int i = 0; i < player2data.FightArray->num; i++)
    {
        ChessMove((Chess*)(player2data.FightArray->arr[i]), player2data, player1data);
    }
}

void GameSprite::upgrade(PlayerData &playerdata)
{
    Chess* temp[3] = { nullptr,nullptr,nullptr };
    ccArray* tempArray[3] = {};
    int s = 0;  //三个待升级棋子
    for (int i = 0; i < ChessNumber; i++)
    {
        if (playerdata.chessnumber[i] >= 3 && i < 16)
        {
            for (int j = 0; j < playerdata.PlayerArray->num; j++)
            {
                if (((Chess*)(playerdata.PlayerArray->arr[j]))->getType() == i)
                {
                    temp[s] = ((Chess*)(playerdata.PlayerArray->arr[j]));
                    tempArray[s] = playerdata.PlayerArray;
                    s++;
                    if (s == 3)
                        break;

                }
            }
            if (temp[0] == nullptr || temp[1] == nullptr || temp[2] == nullptr)   //若在备战区没寻满三个，则进入战斗区找
            {
                for (int j = 0; j < playerdata.FightArray->num; j++)
                {
                    if (((Chess*)(playerdata.FightArray->arr[j]))->getType() == i)
                    {
                        temp[s] = ((Chess*)(playerdata.FightArray->arr[j]));
                        tempArray[s] = playerdata.FightArray;
                        s++;
                        if (s == 3)
                            break;

                    }
                }
            }
            if (temp[0] != nullptr && temp[1] != nullptr && temp[2] != nullptr)
            {
                auto upgrade_chess = upgradeChessCreate(i);
                for (int i = 0; i < 3; i++)
                {
                    ChessExist[MapIntReturn(temp[i]->getTempPosition()).x][MapIntReturn(temp[i]->getTempPosition()).y] = 0;
                    this->removeChild(temp[i]);
                    ccArrayRemoveObject(tempArray[i], temp[i]);
                }
                playerdata.chessnumber[i] -= 3;
                ccArrayAppendObject(playerdata.PlayerArray, upgrade_chess);            
                playerdata.HaveNewChess = 1;
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
        case upgrade_chomper:
            return upgrade_Chomper::createChess();
            break;
        case upgrade_cherrybomb:
            return upgrade_CherryBomb::createChess();
            break;
        case upgrade_ga_peashooter:
            return upgrade_Ga_PeaShooter::createChess();
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
        case upgrade_tomatoboom:
            return upgrade_TomatoBoom::createChess();
            break;
        case _3star_sunflower:
            return _3star_SunFlower::createChess();
            break;
        case _3star_chomper:
            return _3star_Chomper::createChess();
            break;
        case _3star_cherrybomb:
            return _3star_CherryBomb::createChess();
            break;
        case _3star_ga_peashooter:
            return _3star_Ga_PeaShooter::createChess();
            break;
        case _3star_walnut:
            return _3star_WalNut::createChess();
            break;
        case _3star_mushroom:
            return _3star_MushRoom::createChess();
            break;
        case _3star_pealauncher:
            return _3star_PeaShooter::createChess();
            break;
        case _3star_tomatoboom:
            return _3star_TomatoBoom::createChess();
            break;
        default:
            break;
    }

}

/*PC_Player相关*/
void GameSprite::pcShowPlayerArray()
{
    for (int i = 0; i < player2data.PlayerArray->num; i++)
    {     
        ((Chess*)player2data.PlayerArray->arr[i])->setPosition(mapPosition[i][9].x, mapPosition[i][9].y);
        ((Chess*)player2data.PlayerArray->arr[i])->set(mapPosition[i][9].x, mapPosition[i][9].y);
    }
}
void GameSprite::pcShowFightArray()
{
    /*位置初始化*/
    for (int i = 0; i < player2data.FightArray->num; i++)
    {
        if (i >= 0 && i <= 7)
        {
            ((Chess*)player2data.FightArray->arr[i])->setPosition(mapPosition[i][5].x, mapPosition[i][5].y);   
            ((Chess*)player2data.FightArray->arr[i])->set(mapPosition[i][5].x, mapPosition[i][5].y);
            ChessExist[i][5] = 1;
        }
        else if (i >= 8 && i <= 15)
        {
            ((Chess*)player2data.FightArray->arr[i])->setPosition(mapPosition[i - 8][6].x, mapPosition[i - 8][6].y);        
            ((Chess*)player2data.FightArray->arr[i])->set(mapPosition[i - 8][6].x, mapPosition[i - 8][6].y);
            ChessExist[i][6] = 1;
        }
        else if (i >= 16 && i <= 23)
        {
            ((Chess*)player2data.FightArray->arr[i])->setPosition(mapPosition[i - 16][7].x, mapPosition[i - 16][7].y);
            ((Chess*)player2data.FightArray->arr[i])->set(mapPosition[i - 16][7].x, mapPosition[i - 16][7].y);
            ChessExist[i][7] = 1;
        }
        else if (i >= 24 && i <= 31)
        {
            ((Chess*)player2data.FightArray->arr[i])->setPosition(mapPosition[i - 24][8].x, mapPosition[i - 24][8].y);
            ((Chess*)player2data.FightArray->arr[i])->set(mapPosition[i - 24][8].x, mapPosition[i - 24][8].y);
            ChessExist[i][8] = 1;
        }
    }

}


float GameSprite::CountDistance(Chess* c1, Chess* c2)
{
    return sqrt(pow((c1->getPosition().x - c2->getPosition().x), 2)
        + pow((c1->getPosition().y - c2->getPosition().y), 2));
}
float GameSprite::CountDistance(Point p1, Point p2)
{
    return sqrt(pow((p1.x - p2.x), 2)
        + pow((p1.y - p2.y), 2));
}
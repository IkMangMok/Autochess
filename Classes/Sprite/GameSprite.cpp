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
void GameSprite::PlayerArrayInit(ccArray* Array,int playerinfo)
{
    for (int i = 0; i < Array->num; i++)
    {
        auto temp = ((Chess*)Array->arr[i]);
        temp->setPosition(temp->getTempPosition());
        temp->set(temp->getTempPosition());
       
        auto temp1 = CreateChess(temp->getType());
        if (playerinfo == 0)
        {
            temp1->setPosition(temp->getTempPosition());
            temp1->set(temp->getTempPosition());
            *(temp1->equipment) = *(temp->equipment);
            temp1->setTempPosition();
        }
        else
        {
            temp1->setPosition(temp->getTempPosition());
            temp1->set(temp->getTempPosition());
            temp1->setTempPosition();
            temp1->setPosition(10000,10000);
            temp1->set(10000, 10000);
        }
        temp1->setPlayer(temp->getPlayer());
        temp1->EquimentChange();
        if (ccArrayContainsObject(Array, temp))
            ccArrayRemoveObject(Array, temp);
        ccArrayInsertObjectAtIndex(Array, temp1, i);
        this->addChild(temp1);
        ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 1;
        
        
    }
}
bool GameSprite::init()
{
    PlayerArrayInit(player1data.PlayerArray, 0);
    PlayerArrayInit(player2data.PlayerArray, 1);      //  ????????????????????
    PlayerArrayInit(player1data.FightArray, 0);
    PlayerArrayInit(player2data.FightArray, 1);
   
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
            (atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //??????
        if (distanceTemp < distance && distanceTemp>0 && !((Chess*)temp)->Die()) //????????????
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
    //????????1e-2??????????

    else if (chess->AttackTarget == (Chess*)nullptr)  //????????????????
    {
        return;
    }
    if (distance >= chess->GetAttackDistance() && !chess->AttackTarget->Die())    //????????????????????????????
    {  
        chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) / distance * chess->getSpeed());
        chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) / distance * chess->getSpeed());  //????????????????
    }
        //????????
}

void GameSprite::update(float dt)
{
    for (int i = 0; i < player1data.FightArray->num; i++)
    {
        ((Chess*)(player1data.FightArray->arr[i]))->Die();
        ChessMove((Chess*)(player1data.FightArray->arr[i]), player1data, player2data);
    }
    for (int i = 0; i < player2data.FightArray->num; i++)
    {
        ((Chess*)(player2data.FightArray->arr[i]))->Die();
        ChessMove((Chess*)(player2data.FightArray->arr[i]), player2data, player1data);
    }
}

void GameSprite::upgrade(PlayerData &playerdata)
{
    
    for (int i = 0; i < 16; i++)
    {
        Chess* temp[3] = { NULL,NULL,NULL };
        ccArray* tempArray[3] = {};
        int s = 0;  //??????????????
        if (playerdata.chessnumber[i] >= 3 && i < 16)
        {
            for (int j = 0; j < playerdata.PlayerArray->num; j++)
            {
                if (((Chess*)(playerdata.PlayerArray->arr[j]))->getType() == i)
                {
                    if (s < 3)
                    {
                        temp[s] = ((Chess*)(playerdata.PlayerArray->arr[j]));
                        tempArray[s] = playerdata.PlayerArray;
                        s++;
                    }
                    if (s == 3)
                        break;

                }
            }
            if (s < 3)   //????????????????????????????????????
            {
                for (int j = 0; j < playerdata.FightArray->num; j++)
                {
                    if (((Chess*)(playerdata.FightArray->arr[j]))->getType() == i)
                    {
                        if (s < 3)
                        {
                            temp[s] = ((Chess*)(playerdata.FightArray->arr[j]));
                            tempArray[s] = playerdata.FightArray;
                            s++;
                        }
                        if (s == 3)
                            break;

                    }
                }
            }
            if (temp[0] != nullptr && temp[1] != nullptr && temp[2] != nullptr && s == 3
                && temp[0]->getType() == i && temp[1]->getType() == i && temp[2]->getType() == i)  //????Bug
            {
                auto upgrade_chess = upgradeChessCreate(i);  
               
                playerdata.chessnumber[i] -= 3;
                for (int k = 0; k < 3; k++)
                {
                    ccArrayAppendArray(upgrade_chess->equipment, temp[k]->equipment);
                    ChessExist[MapIntReturn(temp[k]->getTempPosition()).x][MapIntReturn(temp[k]->getTempPosition()).y] = 0;
                    temp[k]->retain();          //??retain??release??????????
                    temp[k]->removeFromParent();
                    if (ccArrayContainsObject(tempArray[k], temp[k]))
                    {
                        ccArrayRemoveObject(tempArray[k], temp[k]);    //_referanceCount>0 ????????retain????????????
                       // temp[i]->autorelease();
                    }                    
                }
                upgrade_chess->EquimentChange();
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

/*PC_Player????*/
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
    /*??????????*/
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
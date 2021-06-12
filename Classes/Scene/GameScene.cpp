#include"GameScene.h"
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace std;
 

void Mapinit()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            mapPosition[i][j].x = 587.5f + 75.f * i;   //地图内部
            mapPosition[i][j].y = 112.5f + 75.f * j;
        }
        mapPosition[i][0].x = 587.5f + (float)75 * (float)i;
        mapPosition[i][0].y = 87.5f;
        mapPosition[i][9].x = 587.5f + (float)75 * i;   //备战区
        mapPosition[i][9].y = 812.5f;
    }
}

Point GameScene::MapJudge(Point point)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)          // 备战区特判
            {
                if (point.y >= 50 && point.y <= 150 &&
                    point.x >= mapPosition[i][0].x - 37.5 && point.x <= mapPosition[i][0].x + 37.5)
                    return Point(mapPosition[i][j].x, mapPosition[i][j].y);
            }
            else if (j == 9)
            {
                if (point.y >= 750 && point.y <= 850 &&
                    point.x >= mapPosition[i][9].x - 37.5 && point.x <= mapPosition[i][9].x + 37.5)
                    return Point(mapPosition[i][j].x, mapPosition[i][j].y);
            }
            else if (sqrt((point.x - mapPosition[i][j].x) * (point.x - mapPosition[i][j].x)    //遍历地图，判断是否在格子内
                + (point.y - mapPosition[i][j].y) * (point.y - mapPosition[i][j].y)) < 37.5 * sqrt(2))
                return Point(mapPosition[i][j].x, mapPosition[i][j].y);
        }

    }
    return Point(-1, -1);
}

IntMap GameScene::MapIntReturn(Point point)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (sqrt((point.x - mapPosition[i][j].x) * (point.x - mapPosition[i][j].x)    //遍历地图，判断是否在格子内
                + (point.y - mapPosition[i][j].y) * (point.y - mapPosition[i][j].y)) < 37.5 * sqrt(2))
                return IntMap(i, j);    //返回离散型坐标
        }
    }
    return IntMap(-1, -1);
}

/*update timer&game turn info*/
void GameScene::TurnInfoInit()
{
    global_data->ChangeGameTurn();
    auto turn_label = Label::createWithTTF("TURN", "fonts/Marker Felt.ttf", 24);
    turn_label->setPosition(200, 800);
    this->addChild(turn_label);
    char* mTurn = new char[8];
    sprintf(mTurn, "Turn %02d", global_data->game_turn);
    turn_label->setString(mTurn);
}

static int audioID;

GameScene* GameScene::createScene()
{
	return GameScene::create();
}

GameScene::GameScene()
{

}
GameScene::~GameScene()
{

}

bool GameScene::init()
{
    Mapinit();
    TurnInfoInit();//回合数更新
	//audioID = AudioEngine::play2d("background music.MP3", true, 1.0f); //音乐
    

	this->addChild(map, 0);        //地图层

	this->addChild(playerLayer, 1);    //玩家层

	this->addChild(test_timer, 2); //计时器层

	this->addChild(gamesprite, 3); //棋子层

    this->addChild(Chesspile, 4);  //牌堆层

    /*-------------装备层------------*/
    package1->setPosition(0, 0);
    this->addChild(package1, 5);

	this->scheduleUpdate();
	return true;

}

void GameScene::update(float dt)
{
    if (player1data.HaveNewChess)                  //若有新棋子加入
    {
        bool flag = 1;
        for (int i = 0; i < 8; i++)
        {
            if (ChessExist[i][0] == 0)
            {
                gamesprite->addChild(((Chess*)(player1data.PlayerArray->arr[player1data.PlayerArray->num - 1])));
                ((Chess*)(player1data.PlayerArray->arr[player1data.PlayerArray->num - 1]))->
                    setPosition(mapPosition[i][0].x,
                        mapPosition[i][0].y);
                ((Chess*)(player1data.PlayerArray->arr[player1data.PlayerArray->num - 1]))->
                    set(mapPosition[i][0].x,
                        mapPosition[i][0].y);
                ((Chess*)(player1data.PlayerArray->arr[player1data.PlayerArray->num - 1]))->setTempPosition();
                player1data.HaveNewChess = 0;
                player1data.Gold -= ((Chess*)(player1data.PlayerArray->arr[player1data.PlayerArray->num - 1]))->getCoinsNeeded();
                ChessExist[i][0] = 1;        //添加成功
                flag = 0;
                break;
            }
        }
        if (flag)
        {                      
            ccArrayRemoveObject(player1data.PlayerArray,
                ((Chess*)(player1data.PlayerArray->arr[player1data.PlayerArray->num - 1])));   //添加失败
            player1data.HaveNewChess = 0;
        }
    }
    if (test_timer->pTime > 0.1f)
        ChessMoveInMouse();
    if (test_timer->pTime < -1e-6)
    {
        gamesprite->scheduleUpdate();
    }
}
void GameScene::SoldChess(Chess* temp, int i, ccArray* Array)
{
    ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
    gamesprite->removeChild(temp);       //卖出
    ccArrayRemoveObject(Array, temp);
    player1data.Gold += temp->getCoinsNeeded();
}
void GameScene::ChessMoveInMouse()
{
    auto MouseListener = EventListenerMouse::create();
    MouseListener = EventListenerMouse::create();
    MouseListener->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);
    MouseListener->onMouseUp = CC_CALLBACK_1(GameScene::onMouseUp, this);
    MouseListener->onMouseDown = CC_CALLBACK_1(GameScene::onMouseDown, this);
    MouseListener->onMouseScroll = CC_CALLBACK_1(GameScene::onMouseScroll, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListener, this);
}

void GameScene::onMouseDown(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    
    if ((int)e->getMouseButton() == 0 || (int)e->getMouseButton() == 1) //触发标志
    {
        /*选中对象*/
        int Obj_is_Selected = 0;

        /*选取装备*/
        if (!Obj_is_Selected && test_timer->pTime > 1e-6)
        {
            for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
            {
                float dx = (e->getCursorX() - ((Equipment*)(player1data.UnequipedEquipment->arr[i]))->getPosition().x);
                float dy = (e->getCursorY() - ((Equipment*)(player1data.UnequipedEquipment->arr[i]))->getPosition().y);
                float distance = sqrt(dx * dx + dy * dy);
                if (distance < 20)
                {
                    MouseSelectedEquip = i;  //确定选中的装备
                    Obj_is_Selected = 1;
                }
            }
        }

        /*选取棋子*/
        if (!Obj_is_Selected)
        {
            for (int i = 0; i < FightArray->num; i++)
            {
                float distance = sqrt((e->getCursorX() -
                    ((Chess*)(FightArray->arr[i]))->getPosition().x)
                    * (e->getCursorX() - ((Chess*)(FightArray->arr[i]))->getPosition().x) +
                    (e->getCursorY() - ((Chess*)(FightArray->arr[i]))->getPosition().y)
                    * (e->getCursorY() - ((Chess*)(FightArray->arr[i]))->getPosition().y));
                if (distance < 50)
                {
                    if ((int)e->getMouseButton() == 0)
                        MouseToChess = i;    //确定选取的棋子
                    else if ((int)e->getMouseButton() == 1)
                    {
                        auto temp = ((Chess*)(FightArray->arr[i]));
                        SoldChess(temp, i, FightArray);
                        return;
                    }
                    ((Chess*)(FightArray->arr[i]))->setTempPosition();  //记录原始位置
                    return;
                }
            }

            for (int i = 0; i < player1data.PlayerArray->num; i++)
            {
                float distance = sqrt((e->getCursorX() -
                    ((Chess*)(player1data.PlayerArray->arr[i]))->getPosition().x)
                    * (e->getCursorX() - ((Chess*)(player1data.PlayerArray->arr[i]))->getPosition().x) +
                    (e->getCursorY() - ((Chess*)(player1data.PlayerArray->arr[i]))->getPosition().y)
                    * (e->getCursorY() - ((Chess*)(player1data.PlayerArray->arr[i]))->getPosition().y));
                if (distance < 50)
                {
                    if ((int)e->getMouseButton() == 0)
                        MouseToChess = i + FightNumber;    //确定选取的棋子
                    else if ((int)e->getMouseButton() == 1)
                    {
                        auto temp = ((Chess*)(player1data.PlayerArray->arr[i]));
                        SoldChess(temp, i, player1data.PlayerArray);
                        return;
                    }
                    ((Chess*)(player1data.PlayerArray->arr[i]))->setTempPosition();   //记录原始位置
                    return;
                }
            }
        }
    }
}

void GameScene::onMouseUp(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    if ((int)e->getMouseButton() == 0)
    {
        /*取消装备选取*/
        if (MouseSelectedEquip != -1)
        {
            if (EquipSearchChess(e->getCursorX(), e->getCursorY(), MouseSelectedEquip))//装备搜索到附近的棋子
            {
                ((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(10000, 10000);
                ccArrayRemoveObjectAtIndex(player1data.UnequipedEquipment, MouseSelectedEquip);
                this->removeChild((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]));
                player1data.occupied_slot--;
            }
            else  //搜索失败，返回原有位置
            {
                ((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(player1data.slotPoint[MouseSelectedEquip]);
            }

            MouseSelectedEquip = -1;
        }

        /*取消棋子选取*/
        if (MouseToChess >= 0 && MouseToChess < FightNumber)
        {
            auto temp = ((Chess*)(FightArray->arr[MouseToChess]));
            if (ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] == 1)   //拒绝重合
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
            }
            else if (MapIntReturn(temp->getPosition()).y != 0 && MapIntReturn(temp->getPosition()).y != 9)   //若不在备战席
            {
                
                Point temppoint = MapJudge(temp->getPosition());
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
            }
            else    //若在备战席，则将其放入
            {
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
              
                ccArrayAppendObject(player1data.PlayerArray, temp);
                ccArrayRemoveObject(FightArray, temp);
                
            }
        }
        else if (MouseToChess >= FightNumber)
        {
            auto temp = ((Chess*)(player1data.PlayerArray->arr[MouseToChess - FightNumber]));
            if (ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] == 1)   //拒绝重合
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
            }
            else if (MapIntReturn(temp->getPosition()).y == 0 || MapIntReturn(temp->getPosition()).y == 9)  //若在备战席
            {
                Point temppoint = MapJudge(temp->getPosition());
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
            }
            else if(test_timer->pTime > 1e-6)        //若进入战斗区
            {
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
              
                ccArrayAppendObject(FightArray, temp);
                temp->is_alive = 1;
                ccArrayRemoveObject(player1data.PlayerArray, temp);
               
                //player1data.HaveNewChess = 1;
                
            }
            else                            //其他不可控情况
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
            }
        }
        MouseToChess = -1;                   //取消选取
       
    }
}

void GameScene::onMouseMove(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    if (MouseSelectedEquip != -1 && test_timer->pTime > 1e-6)
    {
        ((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(e->getCursorX(), e->getCursorY());
    }
    if (MouseToChess != -1)
    {
        if (test_timer->pTime < -1e-6 && MouseToChess < FightNumber)
        {
            MouseToChess = -1;
            return;
        }
        else if (MouseToChess < FightNumber)             //小于FightNumber为战斗区，大于FightNumber为备战区
        {
            auto temp = (Chess*)(FightArray->arr[MouseToChess]);
            
            if (MapJudge(temp->getPosition()) != Point(-1, -1))
            {
                temp->setPosition(e->getCursorX(), e->getCursorY());
                temp->set(e->getCursorX(), e->getCursorY());  //移动之
            }
            else
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
                MouseToChess = -1;                        //回到原位，取消选取
            }
        }
        else if (MouseToChess >= FightNumber)
        {
            auto temp = (Chess*)(player1data.PlayerArray->arr[MouseToChess - FightNumber]);
            if (MapJudge(temp->getPosition()) != Point(-1, -1))
            {
                temp->setPosition(e->getCursorX(), e->getCursorY());
                temp->set(e->getCursorX(), e->getCursorY());  //移动之
            }
            else
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
                MouseToChess = -1;                           //回到原位，取消选取
            }
        }
    }
}

void GameScene::onMouseScroll(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    e->getScrollX();
    e->getScrollY();

}

bool GameScene::EquipSearchChess(const float EquipX, const float EquipY, const int EquipIndex)
{
    for (int i = 0; i < FightArray->num; i++)//先在战斗区寻找
    {
        float dx = EquipX - ((Chess*)(FightArray->arr[i]))->getPosition().x;
        float dy = EquipY - ((Chess*)(FightArray->arr[i]))->getPosition().y;
        float distance = sqrt(dx * dx + dy * dy);
        if (distance < 20) //搜索精度设定为20
        {
            switch (((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex])->type)
            {
                case GUN:
                    ((Gun*)player1data.UnequipedEquipment->arr[EquipIndex])->EquipToChess((Chess*)(FightArray->arr[i]));
                    break;
                case KNIFE:
                    ((Knife*)player1data.UnequipedEquipment->arr[EquipIndex])->EquipToChess((Chess*)(FightArray->arr[i]));
                    break;
            }
            return true;
        }
    }
    for (int i = 0; i < PlayerArray->num; i++)//接下来在备战区寻找
    {
        float dx = EquipX - ((Chess*)(PlayerArray->arr[i]))->getPosition().x;
        float dy = EquipY - ((Chess*)(PlayerArray->arr[i]))->getPosition().y;
        float distance = sqrt(dx * dx + dy * dy);
        if (distance < 20) //搜索精度设定为20
        {
            switch (((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex])->type)
            {
                case GUN:
                    ((Gun*)player1data.UnequipedEquipment->arr[EquipIndex])->EquipToChess((Chess*)(PlayerArray->arr[i]));
                    break;
                case KNIFE:
                    ((Knife*)player1data.UnequipedEquipment->arr[EquipIndex])->EquipToChess((Chess*)(PlayerArray->arr[i]));
                    break;
            }
            return true;
        }
    }
    return false;
}
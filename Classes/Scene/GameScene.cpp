#include"GameScene.h"
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace std;
 

void Mapinit()           //地图信息初始化
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
/*判断棋子位于地图的哪一格，并返回该格坐标*/
Point GameScene::MapJudge(Point point)       
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)         // 备战区特判
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
/*判断该坐标位于哪一格，并返回离散坐标*/
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
	//audioID = AudioEngine::play2d("background music.MP3", true, 1.0f); //音乐
	
	this->addChild(map, 0);        //地图层

	this->addChild(playerLayer, 1);    //玩家层

	this->addChild(test_timer, 2); //计时器层

	this->addChild(gamesprite, 3); //棋子层

    this->addChild(Chesspile, 4);  //牌堆层
   
    this->addChild(hasl, 5);       //设置层及信息层

    this->scheduleUpdate();

    
	
    playerLayer->scheduleUpdate();

	return true;

}

void GameScene::addChess(PlayerData& playerdata, int playerinfo)
{

    if (playerdata.HaveNewChess)                  //若有新棋子加入
    {
        bool flag = 1;
        auto temp = ((Chess*)(playerdata.PlayerArray->arr[playerdata.PlayerArray->num - 1]));
        if (playerinfo == 0)
        {
            for (int i = 0; i < 8; i++)
            {

                if (ChessExist[i][0 + 9 * playerinfo] == 0)
                {
                    playerdata.Gold -= temp->getCoinsNeeded();
                    gamesprite->addChild(temp);
                    temp->setPosition(mapPosition[i][0 + 9 * playerinfo].x, mapPosition[i][0 + 9 * playerinfo].y);
                    temp->set(mapPosition[i][0 + 9 * playerinfo].x, mapPosition[i][0 + 9 * playerinfo].y);
                    temp->setTempPosition();
                    playerdata.HaveNewChess = 0;
                    //temp->setPlayer(0);
                    temp->setPlayer(playerinfo);//抽奖
                    playerdata.chessnumber[temp->getType()]++;     //记录其棋子升级信息
                    ChessExist[i][0 + 9 * playerinfo] = 1;        //添加成功
                    flag = 0;
                    playerdata.HaveNewChess = 0;        //防止莫名其妙的BUG
                    flag = 0;
                    break;
                }
            }
        }
        else
        {
            playerdata.Gold -= temp->getCoinsNeeded();
            gamesprite->addChild(temp);
            temp->setPosition(10000, 10000);
            temp->set(10000, 10000);
            temp->setPlayer(playerinfo);//抽奖
            playerdata.chessnumber[temp->getType()]++;
            playerdata.HaveNewChess = 0;        //防止莫名其妙的BUG
            flag = 0;
            playerdata.HaveNewChess = 0;        //防止莫名其妙的BUG
            flag = 0;
        }
        if (flag)
        {
            ccArrayRemoveObject(playerdata.PlayerArray, temp);   //添加失败
            playerdata.HaveNewChess = 0;
            
        }
    }
}
/***************************************
功能：
1.将棋子addChild
2.鼠标监听器
3.计时判断，在计时器小于0时开启战斗
*************************************/
void GameScene::update(float dt)
{
    if (test_timer->pTime > 1e-6)
    {
        gamesprite->upgrade(player1data);             //监测是否可升级
        gamesprite->upgrade(player2data);
        addChess(player1data, 0);
        addChess(player2data, 1);
        pc_player.pcJudgeMoneyUsage();
    }
   
    addChess(player1data, 0);
    addChess(player2data, 1);
    
    ChessMoveInMouse();
    if (test_timer->pTime < -1e-6)
    {
        if (PC_ShowFlag)
        {
            pc_player.pcCreateBattleArray();
            pc_player.pcEquip();
            gamesprite->pcShowFightArray();  //显示电脑玩家信息
            gamesprite->pcShowPlayerArray();
            PC_ShowFlag = 0;
        }
        test_timer->setPosition(10000, 10000);
        gamesprite->scheduleUpdate();
        Win();
    }
}

void GameScene::WinRetain(ccArray* Array)
{
    for (int i = 0; i < Array->num; i++)
    {
        auto temp = ((Chess*)Array->arr[i]);

        temp->retain();                    //保存
        temp->removeFromParent();          //gamesprite将被重新创建，因此先将其remove
        temp->recover();                  //恢复原样
    }
}
/*判断战斗是否结束*/
void GameScene::JudgeWin(PlayerData& playerdata, int sum[])
{
    for (int i = 0; i < playerdata.FightArray->num; i++)
    {
        auto temp = ((Chess*)(playerdata.FightArray->arr[i]));
        if (!(temp->Die()))                   //记录战斗双方棋子个数
        {
            sum[temp->getPlayer()]++;
        }
    }
}
void GameScene::Win()           
{
    int sum[2] = {};
    JudgeWin(player1data, sum);
    JudgeWin(player2data, sum);
   
    if (sum[1] == 0 || sum[0] == 0)          //有一方的棋子个数为0
    {
        Sleep(3000);
        if (sum[1] == 0)
            player2data.Hurted(2 + 2 * sum[0]);
        else if (sum[0] == 0)
        {
            player1data.Hurted(2 + 2 * sum[1]);
        }
        WinRetain(player1data.PlayerArray);
        WinRetain(player2data.PlayerArray);
        WinRetain(player1data.FightArray);
        WinRetain(player2data.FightArray);
       
       // AudioEngine::stop(audioID);
        gamesprite->unscheduleUpdate();
        player1data.recover();
        player2data.recover();
        
       
        if (player1data.HealthValue > 0 && player2data.HealthValue > 0)
            _director->replaceScene(GameScene::createScene());
        else
        {
            string name = player1data.HealthValue <= 0 ? "player2":"player1";
            auto label = Label::createWithTTF(name + " win!", "fonts/Marker Felt.ttf", 36);
            this->addChild(label);
            label->setTextColor(Color4B::WHITE);
            label->setPosition(800, 400);
            auto move = FadeOut::create(5.0f);
            label->runAction(move);
            this->unscheduleUpdate();
            _director->replaceScene(TransitionFade::create(8.0f, AutoChess::createScene()));
        }
    }
    return;
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

    if (FindMouseTarget(player1data.FightArray, e) == 1)       //在战斗区寻找目标
       FindMouseTarget(player1data.PlayerArray, e);  //寻找不到则在备战区寻找
}
void GameScene::ToPlayerArray(Chess* chess, PlayerData& playerdata)
{
    chess->setPosition(MapJudge(chess->getPosition()));
    chess->set(MapJudge(chess->getPosition()));

    ChessExist[MapIntReturn(chess->getPosition()).x][MapIntReturn(chess->getPosition()).y] = 1;
    ChessExist[MapIntReturn(chess->getTempPosition()).x][MapIntReturn(chess->getTempPosition()).y] = 0;
    chess->setTempPosition();
    ccArrayAppendObject(playerdata.PlayerArray, chess);
    ccArrayRemoveObject(player1data.FightArray, chess);
}
void GameScene::ToFightArray(Chess* chess, PlayerData& playerdata)
{
    chess->setPosition(MapJudge(chess->getPosition()));   //将其定位至坐标中点
    chess->set(MapJudge(chess->getPosition()));

    ChessExist[MapIntReturn(chess->getPosition()).x][MapIntReturn(chess->getPosition()).y] = 1;      //修改地图棋子存在状况
    ChessExist[MapIntReturn(chess->getTempPosition()).x][MapIntReturn(chess->getTempPosition()).y] = 0;
    chess->setTempPosition();
    ccArrayAppendObject(player1data.FightArray, chess);    //放入战斗区
    ccArrayRemoveObject(playerdata.PlayerArray, chess);
}
void GameScene::onMouseUp(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    if ((int)e->getMouseButton() == 0)
    {
        
        if (MouseToChess >= 0 && MouseToChess < FightNumber)
        {
            auto temp = ((Chess*)(player1data.FightArray->arr[MouseToChess]));
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
                temp->setTempPosition();
            }
            else    //若在备战席，则将其放入
            {
                ToPlayerArray(temp, player1data);
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
                temp->setTempPosition();
            }
            else if (test_timer->pTime > 1e-6)       //若进入战斗区
            {
                if(player1data.FightArray->num<player1data.Grade)
                    ToFightArray(temp, player1data);
                else
                {
                    temp->setPosition(MapJudge(temp->getTempPosition()));
                    temp->set(MapJudge(temp->getTempPosition()));
                    auto label = Label::createWithTTF("Not enough Grade!", "fonts/Marker Felt.ttf", 36);
                    this->addChild(label);
                    label->setTextColor(Color4B::WHITE);
                    label->setPosition(800, 400);
                    auto move = FadeOut::create(2.0f);
                    label->runAction(move);
                    MouseToChess = -1;
                }
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
    if (MouseToChess != -1)
    {
        if (test_timer->pTime < 1e-2 && MouseToChess < FightNumber)
        {
            auto temp = (Chess*)(player1data.FightArray->arr[MouseToChess]);
            temp->setPosition(MapJudge(temp->getTempPosition()));
            temp->set(MapJudge(temp->getTempPosition()));
            MouseToChess = -1;
            return;
        }
        else if (MouseToChess < FightNumber)             //小于FightNumber为战斗区，大于FightNumber为备战区
        {
            auto temp = (Chess*)(player1data.FightArray->arr[MouseToChess]);
            auto point = MapJudge(temp->getPosition());
            if (point != Point(-1, -1) && point.y <= mapPosition[0][4].y + 37.5)
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
            auto point = MapJudge(temp->getPosition());
            if (point != Point(-1, -1) && point.y <= mapPosition[0][4].y + 37.5)
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


void GameScene::SoldChess(Chess* temp, ccArray* Array)        //整合函数
{
    ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
    player1data.Gold += temp->getSoldCoins();
    gamesprite->removeChild(temp);       //卖出
    ccArrayRemoveObject(Array, temp);
}

bool GameScene::FindMouseTarget(ccArray* Array, EventMouse* e)    
{
    int temp = 0;
    if (Array == player1data.PlayerArray)
        temp = FightNumber;
    for (int i = 0; i < Array->num; i++)
    {
        float distance = sqrt((e->getCursorX() -
            ((Chess*)(Array->arr[i]))->getPosition().x)
            * (e->getCursorX() - ((Chess*)(Array->arr[i]))->getPosition().x) +
            (e->getCursorY() - ((Chess*)(Array->arr[i]))->getPosition().y)
            * (e->getCursorY() - ((Chess*)(Array->arr[i]))->getPosition().y));
        if (distance < 50)
        {
            if ((int)e->getMouseButton() == 0)
                MouseToChess = i + temp;    //确定选取的棋子
            else if ((int)e->getMouseButton() == 1 && test_timer->pTime > 1e-2)
            {
                auto temp1 = ((Chess*)(Array->arr[i]));
                SoldChess(temp1, Array);
                return 0;
            }
            ((Chess*)(Array->arr[i]))->setTempPosition();  //记录原始位置
            return 0;
        }
    }
    return 1;
}
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
    Coins->retain();
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
   
    Coins->setPosition(380, 390);   //临时记录
    this->addChild(Coins);

	this->scheduleUpdate();
	return true;

}

void GameScene::addChess(PlayerData &playerdata)
{
    if (playerdata.HaveNewChess)                  //若有新棋子加入
    {
        bool flag = 1;
        auto temp = ((Chess*)(playerdata.PlayerArray->arr[playerdata.PlayerArray->num - 1]));
        for (int i = 0; i < 8; i++)
        {

            if (ChessExist[i][0] == 0)
            {
                playerdata.Gold -= temp->getCoinsNeeded();
                gamesprite->addChild(temp);
                temp->setPosition(mapPosition[i][0].x, mapPosition[i][0].y);
                temp->set(mapPosition[i][0].x, mapPosition[i][0].y);
                temp->setTempPosition();
                playerdata.HaveNewChess = 0;
                //temp->setPlayer(0);
                temp->setPlayer(rand() % 2);//抽奖
                playerdata.chessnumber[temp->getType()]++;     //记录其棋子升级信息
                ChessExist[i][0] = 1;        //添加成功
                flag = 0;
                playerdata.HaveNewChess = 0;        //防止莫名其妙的BUG
                flag = 0;
                break;
            }
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
        gamesprite->upgrade(dt);             //监测是否可升级
    addChess(player1data);
    addChess(player2data);
    Coins->setString(to_string(player1data.Gold));  //临时记录
    
    ChessMoveInMouse();
    if (test_timer->pTime < -1e-6)
    {
        test_timer->setPosition(10000, 10000);
        gamesprite->scheduleUpdate();
        Win();
    }
}

/*判断战斗是否结束*/
void GameScene::Win()           
{
    int sum[2] = {};
    for (int i = 0; i < FightArray->num; i++)
    {
        auto temp = ((Chess*)(FightArray->arr[i]));
        if (!(temp->Die()))                   //记录战斗双方棋子个数
        {
            sum[temp->getPlayer()]++;
        }
    }
    if (sum[1] == 0 || sum[0] == 0)          //有一方的棋子个数为0
    {
        //player2data.Hurted(3);
        for (int i = 0; i < player1data.PlayerArray->num; i++)      
        {
            auto temp = ((Chess*)player1data.PlayerArray->arr[i]);
          
            temp->retain();                    //保存
            temp->removeFromParent();          //gamesprite将被重新创建，因此先将其remove
            temp->recover();                  //恢复原样
        }
        for (int i = 0; i < FightArray->num; i++)
        {
            auto temp = ((Chess*)FightArray->arr[i]);
          
            temp->retain();
            temp->removeFromParent();
            temp->recover();
        }
       
       // AudioEngine::stop(audioID);
        gamesprite->unscheduleUpdate();
        player1data.recover();
        Sleep(300);
        _director->replaceScene(GameScene::createScene());
    }
    else
    {
        //player1data.Hurted(3);

       // AudioEngine::stop(audioID);
       // _director->replaceScene(GameScene::createScene());
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

    if (FindMouseTarget(FightArray, e) == 1)         //在战斗区寻找目标
       FindMouseTarget(player1data.PlayerArray, e);  //寻找不到则在备战区寻找
}

void GameScene::onMouseUp(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    if ((int)e->getMouseButton() == 0)
    {
        
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
                temp->setTempPosition();
            }
            else    //若在备战席，则将其放入
            {
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
                temp->setTempPosition();
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
                temp->setTempPosition();
            }
            else if (test_timer->pTime > 1e-6)       //若进入战斗区
            {
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
                temp->setTempPosition();
              
                ccArrayAppendObject(FightArray, temp);
                ccArrayRemoveObject(player1data.PlayerArray, temp);
               
                
                
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


void GameScene::SoldChess(Chess* temp, ccArray* Array)        //整合函数
{
    ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
    player1data.Gold += temp->getSoldCoins();
    gamesprite->removeChild(temp);       //卖出
    ccArrayRemoveObject(Array, temp);
}

bool GameScene::FindMouseTarget(ccArray* Array, EventMouse* e)       //应修复：卖出正在打架的棋子
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
            else if ((int)e->getMouseButton() == 1)
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
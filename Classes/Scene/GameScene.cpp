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
            mapPosition[i][j].x = 587.5f + 75.f * i;   //��ͼ�ڲ�
            mapPosition[i][j].y = 112.5f + 75.f * j;
        }
        mapPosition[i][0].x = 587.5f + (float)75 * (float)i;
        mapPosition[i][0].y = 87.5f;
        mapPosition[i][9].x = 587.5f + (float)75 * i;   //��ս��
        mapPosition[i][9].y = 812.5f;
    }
}

Point GameScene::MapJudge(Point point)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)          // ��ս������
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
            else if (sqrt((point.x - mapPosition[i][j].x) * (point.x - mapPosition[i][j].x)    //������ͼ���ж��Ƿ��ڸ�����
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
            if (sqrt((point.x - mapPosition[i][j].x) * (point.x - mapPosition[i][j].x)    //������ͼ���ж��Ƿ��ڸ�����
                + (point.y - mapPosition[i][j].y) * (point.y - mapPosition[i][j].y)) < 37.5 * sqrt(2))
                return IntMap(i, j);    //������ɢ������
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
	//audioID = AudioEngine::play2d("background music.MP3", true, 1.0f); //����
	
	this->addChild(map, 0);        //��ͼ��

	this->addChild(playerLayer, 1);    //��Ҳ�

	this->addChild(test_timer, 2); //��ʱ����

	this->addChild(gamesprite, 3); //���Ӳ�

    this->addChild(Chesspile, 4);  //�ƶѲ�

	this->scheduleUpdate();
	return true;

}

void GameScene::update(float dt)
{
    if (player1data.HaveNewChess)                  //���������Ӽ���
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
                ChessExist[i][0] = 1;        //��ӳɹ�
                flag = 0;
                break;
            }
        }
        if (flag)
        {                      
            ccArrayRemoveObject(player1data.PlayerArray,
                ((Chess*)(player1data.PlayerArray->arr[player1data.PlayerArray->num - 1])));   //���ʧ��
            player1data.HaveNewChess = 0;
        }
    }
    ChessMoveInMouse();
    if (test_timer->pTime < -1e-6)
    {
        gamesprite->scheduleUpdate();
    }
}
void GameScene::SoldChess(Chess* temp, int i, ccArray* Array)
{
    ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
    gamesprite->removeChild(temp);       //����
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
                MouseToChess = i;    //ȷ��ѡȡ������
            else if ((int)e->getMouseButton() == 1)
            {
                auto temp = ((Chess*)(FightArray->arr[i]));
                SoldChess(temp, i, FightArray);
                return;
            }
            ((Chess*)(FightArray->arr[i]))->setTempPosition();  //��¼ԭʼλ��
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
                MouseToChess = i + FightNumber;    //ȷ��ѡȡ������
            else if ((int)e->getMouseButton() == 1)
            {
                auto temp = ((Chess*)(player1data.PlayerArray->arr[i]));
                SoldChess(temp, i, player1data.PlayerArray);
                return;
            }
            ((Chess*)(player1data.PlayerArray->arr[i]))->setTempPosition();   //��¼ԭʼλ��
            return;
        }
    }   
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
            if (ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] == 1)   //�ܾ��غ�
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
            }
            else if (MapIntReturn(temp->getPosition()).y != 0 && MapIntReturn(temp->getPosition()).y != 9)   //�����ڱ�սϯ
            {
                
                Point temppoint = MapJudge(temp->getPosition());
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
            }
            else    //���ڱ�սϯ���������
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
            if (ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] == 1)   //�ܾ��غ�
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
            }
            else if (MapIntReturn(temp->getPosition()).y == 0 || MapIntReturn(temp->getPosition()).y == 9)  //���ڱ�սϯ
            {
                Point temppoint = MapJudge(temp->getPosition());
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
            }
            else if(test_timer->pTime > 1e-6)        //������ս����
            {
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
              
                ccArrayAppendObject(FightArray, temp);
                ccArrayRemoveObject(player1data.PlayerArray, temp);
               
                //player1data.HaveNewChess = 1;
                
            }
            else                            //�������ɿ����
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
            }
        }
        MouseToChess = -1;                   //ȡ��ѡȡ
       
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
        else if (MouseToChess < FightNumber)             //С��FightNumberΪս����������FightNumberΪ��ս��
        {
            auto temp = (Chess*)(FightArray->arr[MouseToChess]);
            
            if (MapJudge(temp->getPosition()) != Point(-1, -1))
            {
                temp->setPosition(e->getCursorX(), e->getCursorY());
                temp->set(e->getCursorX(), e->getCursorY());  //�ƶ�֮
            }
            else
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
                MouseToChess = -1;                        //�ص�ԭλ��ȡ��ѡȡ
            }
        }
        else if (MouseToChess >= FightNumber)
        {
            auto temp = (Chess*)(player1data.PlayerArray->arr[MouseToChess - FightNumber]);
            if (MapJudge(temp->getPosition()) != Point(-1, -1))
            {
                temp->setPosition(e->getCursorX(), e->getCursorY());
                temp->set(e->getCursorX(), e->getCursorY());  //�ƶ�֮
            }
            else
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
                MouseToChess = -1;                           //�ص�ԭλ��ȡ��ѡȡ
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
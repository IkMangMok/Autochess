#include"GameScene.h"
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace std;
 

void Mapinit()           //��ͼ��Ϣ��ʼ��
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
/*�ж�����λ�ڵ�ͼ����һ�񣬲����ظø�����*/
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
/*�жϸ�����λ����һ�񣬲�������ɢ����*/
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
    Coins->retain();
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
   
    Coins->setPosition(380, 390);   //��ʱ��¼
    this->addChild(Coins);

	this->scheduleUpdate();
	return true;

}

void GameScene::addChess(PlayerData &playerdata)
{
    if (playerdata.HaveNewChess)                  //���������Ӽ���
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
                temp->setPlayer(rand() % 2);//�齱
                playerdata.chessnumber[temp->getType()]++;     //��¼������������Ϣ
                ChessExist[i][0] = 1;        //��ӳɹ�
                flag = 0;
                playerdata.HaveNewChess = 0;        //��ֹĪ�������BUG
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ccArrayRemoveObject(playerdata.PlayerArray, temp);   //���ʧ��
            playerdata.HaveNewChess = 0;
            
        }
    }
}
/***************************************
���ܣ�
1.������addChild
2.��������
3.��ʱ�жϣ��ڼ�ʱ��С��0ʱ����ս��
*************************************/
void GameScene::update(float dt)
{
    if (test_timer->pTime > 1e-6)
        gamesprite->upgrade(dt);             //����Ƿ������
    addChess(player1data);
    addChess(player2data);
    Coins->setString(to_string(player1data.Gold));  //��ʱ��¼
    
    ChessMoveInMouse();
    if (test_timer->pTime < -1e-6)
    {
        test_timer->setPosition(10000, 10000);
        gamesprite->scheduleUpdate();
        Win();
    }
}

/*�ж�ս���Ƿ����*/
void GameScene::Win()           
{
    int sum[2] = {};
    for (int i = 0; i < FightArray->num; i++)
    {
        auto temp = ((Chess*)(FightArray->arr[i]));
        if (!(temp->Die()))                   //��¼ս��˫�����Ӹ���
        {
            sum[temp->getPlayer()]++;
        }
    }
    if (sum[1] == 0 || sum[0] == 0)          //��һ�������Ӹ���Ϊ0
    {
        //player2data.Hurted(3);
        for (int i = 0; i < player1data.PlayerArray->num; i++)      
        {
            auto temp = ((Chess*)player1data.PlayerArray->arr[i]);
          
            temp->retain();                    //����
            temp->removeFromParent();          //gamesprite�������´���������Ƚ���remove
            temp->recover();                  //�ָ�ԭ��
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

    if (FindMouseTarget(FightArray, e) == 1)         //��ս����Ѱ��Ŀ��
       FindMouseTarget(player1data.PlayerArray, e);  //Ѱ�Ҳ������ڱ�ս��Ѱ��
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
                temp->setTempPosition();
            }
            else    //���ڱ�սϯ���������
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
                temp->setTempPosition();
            }
            else if (test_timer->pTime > 1e-6)       //������ս����
            {
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
                temp->setTempPosition();
              
                ccArrayAppendObject(FightArray, temp);
                ccArrayRemoveObject(player1data.PlayerArray, temp);
               
                
                
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


void GameScene::SoldChess(Chess* temp, ccArray* Array)        //���Ϻ���
{
    ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
    player1data.Gold += temp->getSoldCoins();
    gamesprite->removeChild(temp);       //����
    ccArrayRemoveObject(Array, temp);
}

bool GameScene::FindMouseTarget(ccArray* Array, EventMouse* e)       //Ӧ�޸����������ڴ�ܵ�����
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
                MouseToChess = i + temp;    //ȷ��ѡȡ������
            else if ((int)e->getMouseButton() == 1)
            {
                auto temp1 = ((Chess*)(Array->arr[i]));
                SoldChess(temp1, Array);
                return 0;
            }
            ((Chess*)(Array->arr[i]))->setTempPosition();  //��¼ԭʼλ��
            return 0;
        }
    }
    return 1;
}
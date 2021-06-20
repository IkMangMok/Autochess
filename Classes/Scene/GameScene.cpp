#include"GameScene.h"
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace std;
string name;

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

void GameScene::TurnInfoInit()
{
    global_data->ChangeGameTurn();
    auto turn_label = Label::createWithTTF("TURN", "fonts/Marker Felt.ttf", 24);
    turn_label->setPosition(200, 800);
    this->addChild(turn_label, 2);
    char* mTurn = new char[8];
    sprintf(mTurn, "Turn %02d", global_data->game_turn);
    turn_label->setString(mTurn);
}

/*�ж�����λ�ڵ�ͼ����һ�񣬲����ظø�����*/
Point GameScene::MapJudge(Point point)       
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)         // ��ս������
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

static int audioID;

GameScene* GameScene::createScene(string& settingname)
{
    name = settingname;
    return GameScene::create();
}
string GameScene::getName()
{
    return name;
}
GameScene::GameScene()
{
   
}
GameScene::~GameScene()
{

}

bool GameScene::init()
{
  //  if (!Scene::initWithPhysics()) { return false; }
    TurnInfoInit();
    Mapinit();
	audioID = AudioEngine::play2d("background music.MP3", true, 1.0f); //����
	
	this->addChild(map, 0);        //��ͼ��

	this->addChild(playerLayer, 1);    //��Ҳ�

	this->addChild(test_timer, 2); //��ʱ����

	this->addChild(gamesprite, 3); //���Ӳ�

    this->addChild(Chesspile, 4);  //�ƶѲ�
   
    this->addChild(hasl, 5);       //���ò㼰��Ϣ��

    layerPackage->setPosition(0, 0);
    this->addChild(layerPackage, 6);

    this->scheduleUpdate();

    
    map->scheduleUpdate();
    playerLayer->scheduleUpdate();

	return true;

}

void GameScene::addChess(PlayerData& playerdata, int playerinfo)
{

    if (playerdata.HaveNewChess)                  //���������Ӽ���
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
                    temp->retain();
                    playerdata.HaveNewChess = 0;
                    //temp->setPlayer(0);
                    temp->setPlayer(playerinfo);
                    playerdata.chessnumber[temp->getType()]++;     //��¼������������Ϣ
                    ChessExist[i][0 + 9 * playerinfo] = 1;        //��ӳɹ�
                    flag = 0;
                    playerdata.HaveNewChess = 0;        //��ֹĪ�������BUG
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
            temp->setPlayer(playerinfo);
            playerdata.chessnumber[temp->getType()]++;
            playerdata.HaveNewChess = 0;        //��ֹĪ�������BUG
            flag = 0;
            playerdata.HaveNewChess = 0;        //��ֹĪ�������BUG
            flag = 0;
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
    {
        gamesprite->upgrade(player1data);             //����Ƿ������
        gamesprite->upgrade(player2data);
        addChess(player1data, 0);
        addChess(player2data, 1);
        pc_player.pcJudgeMoneyUsage();
    }
   
    addChess(player1data, 0);
    addChess(player2data, 1);
    
    ChessMoveInMouse();
    if (test_timer->pTime < -1e-2)
    {
        if (PC_ShowFlag)
        {
            pc_player.pcCreateBattleArray();
            pc_player.pcEquip();
            gamesprite->pcShowFightArray();  //��ʾ���������Ϣ
            gamesprite->pcShowPlayerArray();
            PC_ShowFlag = 0;
        }
        GameStartMouseInit();   //ȡ����ս�������ӵ�ѡȡ
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

        temp->retain();                    //����
        temp->removeFromParent();          //gamesprite�������´���������Ƚ���remove
        temp->recover();                  //�ָ�ԭ��
    }
}
/*�ж�ս���Ƿ����*/
void GameScene::JudgeWin(PlayerData& playerdata, int sum[])
{
    for (int i = 0; i < playerdata.FightArray->num; i++)
    {
        auto temp = ((Chess*)(playerdata.FightArray->arr[i]));
        if (!(temp->Die()))                   //��¼ս��˫�����Ӹ���
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
   
    if (sum[1] == 0 || sum[0] == 0)          //��һ�������Ӹ���Ϊ0
    {    
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
        /*remove from parent*/
        layerPackage->removeAllChildren();
        AudioEngine::stop(audioID);
        if (player1data.HealthValue > 0 && player2data.HealthValue > 0)
            _director->replaceScene(GameScene::createScene(name));
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
            
            player1data.remain();
            player2data.remain();
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    ChessExist[i][j] = 0;
                }
            }
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

    /*ѡ�ж���ı�־*/
    int Obj_is_Selected = 0;

    /*װ��ѡȡ*/
    if (!Obj_is_Selected && test_timer->pTime > 1e-6)
    {
        for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
        {
            float dx = (e->getCursorX() - ((Equipment*)(player1data.UnequipedEquipment->arr[i]))->getPosition().x);
            float dy = (e->getCursorY() - ((Equipment*)(player1data.UnequipedEquipment->arr[i]))->getPosition().y);
            float distance = sqrt(dx * dx + dy * dy);
            if (distance < 20)
            {
                MouseSelectedEquip = i;  //ȷ��ѡ�е�װ��
                Obj_is_Selected = 1;
            }
        }
    }

    if (!Obj_is_Selected)
    {
        if (FindMouseTarget(player1data.FightArray, e) == 1)       //��ս����Ѱ��Ŀ��
            FindMouseTarget(player1data.PlayerArray, e);  //Ѱ�Ҳ������ڱ�ս��Ѱ��
    }
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
    chess->setPosition(MapJudge(chess->getPosition()));   //���䶨λ�������е�
    chess->set(MapJudge(chess->getPosition()));

    ChessExist[MapIntReturn(chess->getPosition()).x][MapIntReturn(chess->getPosition()).y] = 1;      //�޸ĵ�ͼ���Ӵ���״��
    ChessExist[MapIntReturn(chess->getTempPosition()).x][MapIntReturn(chess->getTempPosition()).y] = 0;
    chess->setTempPosition();
    ccArrayAppendObject(player1data.FightArray, chess);    //����ս����
    ccArrayRemoveObject(playerdata.PlayerArray, chess);
}
void GameScene::onMouseUp(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    if ((int)e->getMouseButton() == 0)
    {
        /*ȡ��װ��ѡȡ*/
        if (MouseSelectedEquip != -1)
        {
            if (EquipSearchChess(e->getCursorX(), e->getCursorY(), MouseSelectedEquip))//װ������������������
            {
                player1data.occupied_slot--;
            }
            else  //����ʧ�ܣ�����ԭ��λ��
            {
                ((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(player1data.slotPoint[MouseSelectedEquip]);
            }
            MouseSelectedEquip = -1;
        }
    }
    if ((int)e->getMouseButton() == 0)
    {
        
        if (MouseToChess >= 0 && MouseToChess < FightNumber)
        {
            auto temp = ((Chess*)(player1data.FightArray->arr[MouseToChess]));
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
                ToPlayerArray(temp, player1data);
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
    if (MouseSelectedEquip != -1 && test_timer->pTime > 1e-6)
    {
        ((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(e->getCursorX(), e->getCursorY());
    }
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
        else if (MouseToChess < FightNumber)             //С��FightNumberΪս����������FightNumberΪ��ս��
        {
            auto temp = (Chess*)(player1data.FightArray->arr[MouseToChess]);
            auto point = MapJudge(temp->getPosition());
            if (point != Point(-1, -1) && point.y <= mapPosition[0][4].y + 37.5)
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
            auto point = MapJudge(temp->getPosition());
            if (point != Point(-1, -1) && point.y <= mapPosition[0][4].y + 37.5)
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
    ccArrayAppendArray(player1data.UnequipedEquipment, temp->equipment);
    temp->retain();
    gamesprite->removeChild(temp);       //����
    ccArrayRemoveObject(Array, temp);

}

bool GameScene::FindMouseTarget(ccArray* Array, EventMouse* e)    
{
    int temp = 0;
    if (Array == player1data.PlayerArray)
        temp = FightNumber;
    
    if (test_timer->pTime > 0 || (test_timer->pTime < 0 && temp == FightNumber)) 
    {
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
                {
                    MouseToChess = i + temp;    //ȷ��ѡȡ������
                }
                else if ((int)e->getMouseButton() == 1 && test_timer->pTime > 1e-2)
                {
                    auto temp1 = ((Chess*)(Array->arr[i]));
                    SoldChess(temp1, Array);
                    return 0;
                }
                ((Chess*)(Array->arr[i]))->setTempPosition();  //��¼ԭʼλ��
                return 0;
            }
        }
    }
    return 1;
}

void GameScene::GameStartMouseInit()
{
    if (test_timer->pTime < 1e-2 && test_timer->pTime > -1e-2)
    {
        if (MouseToChess < FightNumber && MouseToChess != -1)
        {
            auto temp = (Chess*)(player1data.FightArray->arr[MouseToChess]);
            temp->setPosition(temp->getTempPosition());
            temp->set(temp->getTempPosition());
            MouseToChess = -1;
        }
    }
}

bool GameScene::EquipSearchChess(const float EquipX, const float EquipY, const int EquipIndex)
{
    for (int i = 0; i < player1data.FightArray->num; i++)//����ս����Ѱ��
    {
        auto temp= (Chess*)(player1data.FightArray->arr[i]);
        float dx = EquipX - ((Chess*)(player1data.FightArray->arr[i]))->getPosition().x;
        float dy = EquipY - ((Chess*)(player1data.FightArray->arr[i]))->getPosition().y;
        float distance = sqrt(dx * dx + dy * dy);
        if (distance < 20) //���������趨Ϊ20
        {               
            ccArrayAppendObject(temp->equipment, ((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex])); 
            ((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex])->retain();
            ((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex])->removeFromParent();
            ccArrayRemoveObjectAtIndex(player1data.UnequipedEquipment, EquipIndex);
           
            return true;
        }
    }
    for (int i = 0; i < player1data.PlayerArray->num; i++)//�������ڱ�ս��Ѱ��
    {
        auto temp = (Chess*)(player1data.PlayerArray->arr[i]);
        float dx = EquipX - ((Chess*)(player1data.PlayerArray->arr[i]))->getPosition().x;
        float dy = EquipY - ((Chess*)(player1data.PlayerArray->arr[i]))->getPosition().y;
        float distance = sqrt(dx * dx + dy * dy);
        if (distance < 20) //���������趨Ϊ20
        {
            temp->EquipToChess(((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex]));
            ccArrayAppendObject(temp->equipment, ((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex]));
            ((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex])->retain();
            ((Equipment*)player1data.UnequipedEquipment->arr[EquipIndex])->removeFromParent();
            ccArrayRemoveObjectAtIndex(player1data.UnequipedEquipment, EquipIndex);
          
            
            return true;
        }
    }
    return false;
}
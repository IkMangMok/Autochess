#include"scene1.h"
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include "AudioEngine.h"

#include<iostream>

USING_NS_CC;
using namespace std;

Scene* scene1::createScene()
{
    return scene1::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in AutoChessScene.cpp\n");
}

static int audioID;
bool scene1::init()
{

    if (!Scene::init())
    {
        return false;
    }

    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*���²�����ʾ�غ���*/
    global_data.ChangeGameTurn();
    auto turn_label = Label::createWithTTF("TURN ", "fonts/Marker Felt.ttf", 24);
    turn_label->setPosition(200, 800);
    this->addChild(turn_label);
    char* mTurn = new char[8];
    sprintf(mTurn, "Turn %02d", global_data.game_turn);
    turn_label->setString(mTurn);

    

    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(AutoChess::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    /*---------------------MenuItemImage BackInScene1----------------------*/
    auto BackInScene1 = MenuItemImage::create(
        "BackToMenu.png",
        "BackToMenu.png",
        CC_CALLBACK_1(scene1::scene1Back, this));

    if (BackInScene1 == nullptr ||
        BackInScene1->getContentSize().width <= 0 ||
        BackInScene1->getContentSize().height <= 0)
    {
        problemLoading("'BackToMenu.png' and 'BackToMenu.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + 50;// +BackInScene1->getContentSize().height / 2 + visibleSize.height / 2;
        BackInScene1->setPosition(Vec2(x, y));
    }

    auto back_in_scene1 = Menu::create(BackInScene1, NULL);  //���ذ�ť
    back_in_scene1->setPosition(Vec2::ZERO);
    this->addChild(back_in_scene1, 1);

    auto  BuyChess = MenuItemImage::create(
        "buy.jpg", "buy.jpg", CC_CALLBACK_1(scene1::PlayerBuyChess, this));
        

    auto buychess = Menu::create(BuyChess, NULL);  //���ذ�ť
    buychess->setPosition(Vec2(500, 500));
    this->addChild(buychess, 1);

    /*----------------------Button OpenPackage---------------
    auto OpenPackage = MenuItemImage::create(
        "PackageButton.png",
        "PackageButton.png",
        CC_CALLBACK_1(scene1::openPackage, this));

    if (OpenPackage == nullptr ||
        OpenPackage->getContentSize().width <= 0 ||
        OpenPackage->getContentSize().height <= 0)
    {
        problemLoading("'PackageButton.png' and 'PackageButton.png'");
    }
    else
    {
        float x = 1000;
        float y = 50;// +BackInScene1->getContentSize().height / 2 + visibleSize.height / 2;
        OpenPackage->setPosition(Vec2(x, y));
    }

    auto open_package = Menu::create(OpenPackage, NULL);  //���ذ�ť
    open_package->setPosition(Vec2::ZERO);
    this->addChild(open_package, 1);-*/

    /*------------------------TMXTiledMap _tileMap---------------------*/
    auto _tileMap = TMXTiledMap::create("test_map1.tmx");              // my first tiled map
    _tileMap->setPosition(origin.x, origin.y);
    this->addChild(_tileMap);
    this->addChild(test_timer, 1);

    /*------------------------Package* package------------------------*/
    package->setPosition(0, 0);
    if(player_data1.occupied_slot<12)
        package->ObtainEquipment(global_data.game_turn);
    this->addChild(package);

    if (player_data1.package_is_opened == 1)
    {

        (package->package_image)->setPosition(1298, 397);   //��ʾ�������

        package->ShowEquipment();                                 //��ʾ�����е�װ��
    }

   /* auto person = Chess::createChess("test_chess_1.png", Point(0,0));
    this->addChild(person, 0);
   
    auto person1 = TestChess::createChess("test_chess_2.png", 0, 0);

    this->addChild(person1, 0);
    */
 //  auto person2 = Chess::createChess("test_chess_1.png", Point(0, 0));
   /*this->addChild(person2, 0);
   // person2->scheduleUpdate();
    ccArrayAppendObject(pArray, person);  //�����ӷ���������
    ccArrayAppendObject(pArray, person1);
    ccArrayAppendObject(pArray, person2);*/
  
    
    /*for (int i = 0; i < pArray->num; i++)
    {
        this->addChild(((Chess*)(pArray->arr[i])), 0);
    }*/
    
    this->scheduleUpdate();  //���ӻụ���������Է� 

    return true;
    
}


void scene1::ChessMove(Chess *chess)
{
    
    Point a(0, 0);
    Point chessPosition = chess->getPosition();
    float distance = 9999999;
    if (chess->AttackTarget == NULL || chess->AttackTarget->Die())    //����Ѿ��й���Ŀ������Ѱ
    {
        for (int i = 0; i < pArray->num; i++)
        {
            auto temp = pArray->arr[i];
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
        distance= sqrt((chess->AttackTarget->getPosition().x - chessPosition.x)
            * (chess->AttackTarget->getPosition().x - chessPosition.x) +
            (chess->AttackTarget->getPosition().y - chessPosition.y)
            * (chess->AttackTarget->getPosition().y - chessPosition.y));
    }
    /*�ƶ�����1e-2Ϊ��λ�ƶ�
    */
    if (chess->AttackTarget == NULL)  //�޹���Ŀ�������
    {
        return;
    }
    if (distance >= chess->GetAttackDistance() && !chess->AttackTarget->Die())    //������������Ŀ��û�����ƶ�
    {
        chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * (float)1e-2);
        chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * (float)1e-2);  //����λ�ô�������
        //����ģ�����Ϲ̶��������ɸĽ�
    }

}
void scene1::update(float dt)
{
    //if (package_shown == 1)
      //  package->ShowEquipment();       //չʾ����

    if (test_timer->pTime > 0.1f)
    {
        ChessMoveInMouse();   //�ƶ�����
        
    }
    else if (fabs(test_timer->pTime) <= 0.1f)
    {
        for (int i = 0; i < pArray->num; i++)
        {
            ((Chess*)(pArray->arr[i]))->setTempPosition();
        }
    }
    else
    {
        test_timer->setPosition(10000, 10000);

        for (int i = 0; i < pArray->num; i++)
        {
            ChessMove((Chess*)(pArray->arr[i]));
        }
        Win();
    }
}
void scene1::SceneMouseBack(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
}

void scene1::ChessMoveInMouse()
{
    auto MouseListener = EventListenerMouse::create();
    MouseListener = EventListenerMouse::create();
    MouseListener->onMouseDown = CC_CALLBACK_1(scene1::onMouseDown, this);
    MouseListener->onMouseMove = CC_CALLBACK_1(scene1::onMouseMove, this);
    MouseListener->onMouseUp = CC_CALLBACK_1(scene1::onMouseUp, this);
    MouseListener->onMouseScroll = CC_CALLBACK_1(scene1::onMouseScroll, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListener, this);
}

/*���������*/
void scene1::onMouseDown(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    if ((int)e->getMouseButton() == 0&& test_timer->pTime > 0)  //����Ŵ���
    {
        /*����Ѿ�ѡ�еı�־*/
        int Obj_is_Selected = 0;

        /*�ж��Ƿ�ѡ��װ������Χ20��*/
        if (!Obj_is_Selected)
        {
            for (int i = 0; i < player_data1.UnequipedEquipment->num; i++)
            {
                float dx = (e->getCursorX() - ((Equipment*)(player_data1.UnequipedEquipment->arr[i]))->getPosition().x);
                float dy = (e->getCursorY() - ((Equipment*)(player_data1.UnequipedEquipment->arr[i]))->getPosition().y);
                float distance = sqrt(dx * dx + dy * dy);
                if (distance < 20)
                {
                    MouseSelectedEquip = i;  //ȷ��ѡ�е�װ��
                    Obj_is_Selected = 1;
                }
            }
        }
  
        /*�ж��Ƿ�ѡ�����ӣ���Χ20��*/
        if (!Obj_is_Selected)
        {
            for (int i = 0; i < pArray->num; i++)
            {
                float distance = sqrt((e->getCursorX() -
                    ((Chess*)(pArray->arr[i]))->getPosition().x)
                    * (e->getCursorX() - ((Chess*)(pArray->arr[i]))->getPosition().x) +
                    (e->getCursorY() - ((Chess*)(pArray->arr[i]))->getPosition().y)
                    * (e->getCursorY() - ((Chess*)(pArray->arr[i]))->getPosition().y));
                if (distance < 20)
                    MouseToChess = i;    //ȷ��ѡȡ������
            }
        }
    }

}

/*���ɿ����*/
void scene1::onMouseUp(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    if ((int)e->getMouseButton() == 0)
    {
        if (MouseToChess != -1)
            MouseToChess = -1;                   //ȡ��ѡȡ
    
        if (MouseSelectedEquip != -1)
        {
            if (EquipSearchChess(e->getCursorX(), e->getCursorY(), MouseSelectedEquip))           //���ҵ�Ŀ�����ӣ�����EquipSearchChess�У���ɼӳ�
            {
                ((Equipment*)(player_data1.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(10000, 10000);
                ccArrayRemoveObjectAtIndex(player_data1.UnequipedEquipment, MouseSelectedEquip);                                  //��Array���Ƴ�װ��
                player_data1.occupied_slot--;
            }
            else              //δ�ҵ�Ŀ��λ�ã����ر���
            {
                ((Equipment*)(player_data1.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(player_data1.slotPoint[MouseSelectedEquip]);//û�ҵ��ӳɵ����ӣ��ص�����
            }
            
            MouseSelectedEquip = -1;
        }
        
    }

}

/*װ��������*/
bool scene1::EquipSearchChess(const float EquipX, const float EquipY, const int EquipIndex)
{
    for (int i = 0; i < pArray->num; i++)
    {
        float dx = EquipX - ((Chess*)(pArray->arr[i]))->getPosition().x;
        float dy = EquipY - ((Chess*)(pArray->arr[i]))->getPosition().y;
        float distance = sqrt(dx * dx + dy * dy);
        if (distance < 20)
        {
            switch (((Equipment*)player_data1.UnequipedEquipment->arr[i])->type)
            {
                case GUN:
                    ((Gun*)player_data1.UnequipedEquipment->arr[EquipIndex])->EquipToChess((Chess*)(pArray->arr[i]));
                    break;
                case KNIFE:
                    ((Knife*)player_data1.UnequipedEquipment->arr[EquipIndex])->EquipToChess((Chess*)(pArray->arr[i]));
                    break;
            }
            return true;
        }
    }
    return false;
}

void scene1::onMouseMove(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    if (MouseSelectedEquip != -1 && test_timer->pTime > 0)
    {
        ((Equipment*)(player_data1.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(e->getCursorX(), e->getCursorY());//�ƶ���
    }
    if (MouseToChess != -1 && test_timer->pTime > 0)
    {
        ((Chess*)(pArray->arr[MouseToChess]))->setPosition(e->getCursorX(), e->getCursorY());
        ((Chess*)(pArray->arr[MouseToChess]))->set(e->getCursorX(), e->getCursorY());  //�ƶ�֮
    }
}

void scene1::onMouseScroll(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    e->getScrollX();
    e->getScrollY();

}

void scene1::Win()
{
    int sum = 0;
    for (int i = 0; i < pArray->num; i++)
    {
        sum += ((Chess*)(pArray->arr[i]))->Die();
    }
    if (sum == pArray->num - 1)          //����δ�������ϵͳ��Ŀǰ�ж���Ϸ�����ķ���Ϊֻʣһ�����ӣ����������ϵͳ���ٶ�������޸�
    {
        for (int i = 0; i < pArray->num; i++)
        {
            ((Chess*)(pArray->arr[i]))->setPosition(((Chess*)(pArray->arr[i]))->getTempPosition());
            ((Chess*)(pArray->arr[i]))->set(((Chess*)(pArray->arr[i]))->getTempPosition());   //�ص���սʱ��λ��
        }

        package->removeAllChildren();//�Ƴ�װ��
        _director->replaceScene(scene1::createScene());
    }
    else
        return;
}

void scene1::PlayerBuyChess(cocos2d::Ref* pSender)
{
    auto temp = Chess::createChess("test_chess_1.png", Point(rand() % 1000, rand() % 1000));
    temp->OfPlayer = player1;
    this->addChild(temp, 2);
    ccArrayAppendObject(pArray, temp);
    //player1->BuyChess();
}


void scene1::scene1Back(cocos2d::Ref* pSender)
{
    AudioEngine::stop(audioID);
    _director->replaceScene(AutoChess::createScene());
} 

/*��װ������
void scene1::openPackage(cocos2d::Ref* pSender)
{
    //AudioEngine::stop(audioID);
    package->setPosition(1298, 397);
    package_shown = 1;
}*/

/*��ȡװ��
void scene1::ObtainEquipment()
{
    if (global_data.game_turn % 5 == 0)
    {
        Gun* tmp = Gun::createGun();
        this->addChild(tmp);
        tmp->initWithFile("Gun.png");
        tmp->setPosition(10000, 10000);
        ccArrayAppendObject(player_data1.UnequipedEquipment, tmp);
        player_data1.occupied_slot++;
    }
}
void scene1::ShowEquipment()
{
    for (int i = 0; i < (player_data1.occupied_slot); i++)
    {
        ((Gun*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(player_data1.slotPoint[i]);
    }
}*/

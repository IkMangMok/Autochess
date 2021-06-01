#include"scene1.h"
#include"AppDelegate.h"
#include"AutoChessScene.h"
<<<<<<< HEAD
#include "AudioEngine.h"
#include<iostream>
=======
>>>>>>> lx

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
<<<<<<< HEAD

static int audioID;
=======
>>>>>>> lx
bool scene1::init()
{

    if (!Scene::init())
    {
        return false;
    }

 
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

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
<<<<<<< HEAD
        "BackToMenu.png",
        "BackToMenu.png",
=======
        "Back_test.png",
        "Back_test.png",
>>>>>>> lx
        CC_CALLBACK_1(scene1::scene1Back, this));

    if (BackInScene1 == nullptr ||
        BackInScene1->getContentSize().width <= 0 ||
        BackInScene1->getContentSize().height <= 0)
    {
<<<<<<< HEAD
        problemLoading("'BackToMenu.png' and 'BackToMenu.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + 50;// +BackInScene1->getContentSize().height / 2 + visibleSize.height / 2;
=======
        problemLoading("'Back_test.png' and 'Back_test.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width-25;
        float y = origin.y+880;// +BackInScene1->getContentSize().height / 2 + visibleSize.height / 2;
>>>>>>> lx
        BackInScene1->setPosition(Vec2(x, y));
    }

    auto back_in_scene1 = Menu::create(BackInScene1, NULL);  //���ذ�ť
    back_in_scene1->setPosition(Vec2::ZERO);
    this->addChild(back_in_scene1, 1);
<<<<<<< HEAD

    auto  BuyChess = MenuItemImage::create(
        "buy.jpg", "buy.jpg", CC_CALLBACK_1(scene1::PlayerBuyChess, this));
        

    auto buychess = Menu::create(BuyChess, NULL);  //���ذ�ť
    buychess->setPosition(Vec2(500, 500));
    this->addChild(buychess, 1);

    /*------------------------TMXTiledMap _tileMap---------------------*/
    auto _tileMap = TMXTiledMap::create("test_map1.tmx");              // my first tiled map
    _tileMap->setPosition(origin.x, origin.y);
    this->addChild(_tileMap);
    this->addChild(test_timer, 1);
 
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
    MouseListener->onMouseMove = CC_CALLBACK_1(scene1::onMouseMove, this);
    MouseListener->onMouseUp = CC_CALLBACK_1(scene1::onMouseUp, this);
    MouseListener->onMouseDown = CC_CALLBACK_1(scene1::onMouseDown, this);
    MouseListener->onMouseScroll = CC_CALLBACK_1(scene1::onMouseScroll, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListener, this);
}

void scene1::onMouseDown(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    if ((int)e->getMouseButton() == 0&& test_timer->pTime > 0)  //����Ŵ���
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

void scene1::onMouseUp(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    if ((int)e->getMouseButton() == 0)
        MouseToChess = -1;                   //ȡ��ѡȡ
}

void scene1::onMouseMove(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
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


=======
    

    /*------------------------TMXTiledMap _tileMap---------------------*/
    auto _tileMap = TMXTiledMap::create("playmap2.tmx");              // my first tiled map
    _tileMap->setPosition(origin.x-1, origin.y-1);
    this->addChild(_tileMap);

    /*------------------------���ذ�ť����������ͣ��---------------------*/
    /*MenuItemToggle* toggleItem = MenuItemToggle::createWithCallback(
        menu_selector(HelloWorld::togglemenuCallBack),
        MenuItemFont::create("On"),
        MenuItemFont::create("Off"),
        NULL);
    /*auto _openItem = MenuItemImage::create(
        "SettingSceneImages/openMusicItem_1.png",
        "SettingSceneImages/openMusicItem_2.png"
    );
    auto _closeItem = MenuItemImage::create(
        "SettingSceneImages/closeMusicItem_1.png",
        "SettingSceneImages/closeMusicItem_2.png");
    //��ϰ�ť
    auto setMusicMenuToggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingScene::menuSetMusicCallback, this),
        _openItem, _closeItem, NULL);
    setMusicMenuToggle->setPosition(Point(0, 0));


    /*------------------------Blood---------------------*/

    string picture = "duck.jpg";
    auto icon = Sprite::create(picture);   //ͷ��
    icon->setPosition(Point(icon->getContentSize().width-20, origin.y + visibleSize.height - icon->getContentSize().height)); //����λ��
    this->addChild(icon);            //�ӵ�Ĭ��ͼ������ȥ

    string name = "player";//������ӡ������֡����ܣ�������Լ���������
    auto nameLabel = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 24);
    if (nameLabel == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        nameLabel->setPosition(Vec2(origin.x+ nameLabel->getContentSize().width+40,origin.y + visibleSize.height - nameLabel->getContentSize().height));
        this->addChild(nameLabel, 1);
    }
    auto bloodFrame = Sprite::create("BloodFrame.png");   //�������ȿ�
    bloodFrame->setPosition(Point(230, visibleSize.height - 60)); //���ÿ��λ��
    this->addChild(bloodFrame);            //�ӵ�Ĭ��ͼ������ȥ
    ProgressTimer* Blood = ProgressTimer::create(Sprite::create("Blood.png"));//����һ��������
    Blood->setBarChangeRate(Point(1, 0));//���ý������ı仯����
    Blood->setType(ProgressTimer::Type::BAR);//���ý�����������
    Blood->setMidpoint(Point(0, 1));//���ý��ȵ��˶�����
    Blood->setPosition(Point(230, visibleSize.height - 60));

    float lifespan = 75.0f;//���������˺�����

    Blood->setPercentage(lifespan);//���ó�ʼֵΪ0
    this->addChild(Blood);

    int length = (int)lifespan;
    string life = to_string(length);
    auto lifeLabel = Label::createWithTTF(life, "fonts/Marker Felt.ttf", 20);
    if (lifeLabel == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        lifeLabel->setPosition(Point(230, visibleSize.height - 85));
        this->addChild(lifeLabel, 1);
    }
   



    auto person = Chess::createChess("test_chess_1.png", 112, 112);
    this->addChild(person, 0);
    person->scheduleUpdate();
    auto person1 = Chess::createChess("test_chess_2.png", 112, 176);
    this->addChild(person1, 0);
    person1->scheduleUpdate();
  //  auto person2 = Chess::createChess("person.jpg", 1000, 200);
   // this->addChild(person2, 0);
   // person2->scheduleUpdate();
    ccArrayAppendObject(pArray, person);
    ccArrayAppendObject(pArray, person1);
 //   ccArrayAppendObject(pArray, person2);

    this->scheduleUpdate();  //�������ӻụ���������Է� 
    return true;


    
}

void scene1::scene1Back(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
} 

void scene1::ChessMove(Chess *chess)
{
    
    Point a(0, 0);
    Point chessPosition = chess->getPosition();
    float distance = 9999999;
    if (chess->AttackTarget == NULL)    //����Ѿ��й���Ŀ������Ѱ
    {
        for (int i = 0; i < pArray->num; i++)
        {
            auto temp = pArray->arr[i];
            Point atemp = ((Chess*)temp)->getPosition();
            int distanceTemp = sqrt((atemp.x - chessPosition.x) * (atemp.x - chessPosition.x) +
                (atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //�����
            if (distanceTemp < distance && distanceTemp>0)  //ȷ������Ŀ��
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
    chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * 1e-2);  
    chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * 1e-2);  //����λ�ô�������
}
void scene1::update(float dt)
{
    for (int i = 0; i < pArray->num; i++)
    {
        ChessMove((Chess*)(pArray->arr[i]));
    } 
}
>>>>>>> lx

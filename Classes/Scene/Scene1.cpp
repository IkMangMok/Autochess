#include"scene1.h"
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include "AudioEngine.h"
#include"time.h"

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
        BackInScene1->setPosition(100,200);
    }

    auto back_in_scene1 = Menu::create(BackInScene1, NULL);  //返回按钮
    back_in_scene1->setPosition(Vec2::ZERO);
    this->addChild(back_in_scene1, 1);

    /*auto  BuyChess = MenuItemImage::create(
        "buy.jpg", "buy.jpg", CC_CALLBACK_1(scene1::PlayerBuyChess, this));
        

    auto buychess = Menu::create(BuyChess, NULL);  //返回按钮
    buychess->setPosition(Vec2(500, 500));
    this->addChild(buychess, 1);*/

    /*------------------------TMXTiledMap _tileMap---------------------*/
    auto _tileMap = TMXTiledMap::create("playmap2.tmx");              // my first tiled map
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
    ccArrayAppendObject(pArray, person);  //将棋子放入数组中
    ccArrayAppendObject(pArray, person1);
    ccArrayAppendObject(pArray, person2);*/
  
    
    /*for (int i = 0; i < pArray->num; i++)
    {
        this->addChild(((Chess*)(pArray->arr[i])), 0);
    }*/

    srand(time(NULL));
    
    openChessStore();

    this->scheduleUpdate();  //棋子会互相搜索到对方 
    return true;
    
}


void scene1::ChessMove(Chess *chess)
{
    
    Point a(0, 0);
    Point chessPosition = chess->getPosition();
    float distance = 9999999;
    if (chess->AttackTarget == NULL || chess->AttackTarget->Die())    //如果已经有攻击目标则不搜寻
    {
        for (int i = 0; i < pArray->num; i++)
        {
            auto temp = pArray->arr[i];
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
    }
    else
    {
        distance= sqrt((chess->AttackTarget->getPosition().x - chessPosition.x)
            * (chess->AttackTarget->getPosition().x - chessPosition.x) +
            (chess->AttackTarget->getPosition().y - chessPosition.y)
            * (chess->AttackTarget->getPosition().y - chessPosition.y));
    }
    /*移动，以1e-2为单位移动
    */
    if (chess->AttackTarget == NULL)  //无攻击目标则结束
    {
        return;
    }
    if (distance >= chess->GetAttackDistance() && !chess->AttackTarget->Die())    //距离大于射程且目标没死则移动
    {
        chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * (float)1e-2);
        chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * (float)1e-2);  //将新位置传入类中
        //除以模长乘上固定参数即可改进
    }

}
void scene1::update(float dt)
{
    if (test_timer->pTime > 0.1f)
    {
        ChessMoveInMouse();   //移动棋子
      
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
    if ((int)e->getMouseButton() == 0&& test_timer->pTime > 0)  //左键才触发
    {
        for (int i = 0; i < pArray->num; i++)
        {
            float distance = sqrt((e->getCursorX() -
                ((Chess*)(pArray->arr[i]))->getPosition().x)
                * (e->getCursorX() - ((Chess*)(pArray->arr[i]))->getPosition().x) +
                (e->getCursorY() - ((Chess*)(pArray->arr[i]))->getPosition().y)
                * (e->getCursorY() - ((Chess*)(pArray->arr[i]))->getPosition().y));
            if (distance < 20)
                MouseToChess = i;    //确定选取的棋子
        }
    }

}

void scene1::onMouseUp(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    if ((int)e->getMouseButton() == 0)
        MouseToChess = -1;                   //取消选取
}

void scene1::onMouseMove(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    if (MouseToChess != -1 && test_timer->pTime > 0)
    {
        ((Chess*)(pArray->arr[MouseToChess]))->setPosition(e->getCursorX(), e->getCursorY());
        ((Chess*)(pArray->arr[MouseToChess]))->set(e->getCursorX(), e->getCursorY());  //移动之
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
    if (sum == pArray->num - 1)          //由于未加入玩家系统，目前判断游戏结束的方法为只剩一个棋子，待加入玩家系统后再对其进行修改
    {
        for (int i = 0; i < pArray->num; i++)
        {
            ((Chess*)(pArray->arr[i]))->setPosition(((Chess*)(pArray->arr[i]))->getTempPosition());
            ((Chess*)(pArray->arr[i]))->set(((Chess*)(pArray->arr[i]))->getTempPosition());   //回到备战时的位置
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
    _director->replaceScene(AutoChess::createScene());
} 

void scene1::openChessStore()
{
    auto open = MenuItemImage::create("Back_test.png", "Back_test.png", CC_CALLBACK_1(scene1::chessStore, this));
    auto Open = Menu::create(open, NULL);
    Open->setPosition(1530,850);
    this->addChild(Open, 1);
}

void scene1::closeChessStore()
{
    auto close = MenuItemImage::create("close_store.png", "close_store.png", CC_CALLBACK_1(scene1::closeLayer, this));
    auto Close = Menu::create(close, NULL);
    s_layer->addChild(Close, 1);
    Close->setPosition(155, 490);
}

void scene1::closeLayer(cocos2d::Ref* pSender)
{
    s_layer->setVisible(false);
}

//野怪从哪里出来？野怪要做吗,僵尸？
//棋子商店的购买以及数据的传输，Used数组出现在手牌区就可以了应该

void scene1::storeChess(int i)
{
    auto sprite1 = Sprite::create(Used[i].address);
    s_layer->addChild(sprite1);
    sprite1->setPosition(40, 430-120*i);

    auto label1 = Label::createWithTTF(chessValue[Used[i].money - 1], "fonts/Marker Felt.ttf", 24);
    label1->setPosition(130, 430-120*i);
    s_layer->addChild(label1);

}

void scene1::buy1(cocos2d::Ref* pSender)
{
    x = x + 90;
    auto sprite = Sprite::create(Used[0].address);
    this->addChild(sprite);
    sprite->setPosition(x, 90);
}

void scene1::buy2(cocos2d::Ref* pSender)
{
    x = x + 90;
    auto sprite = Sprite::create(Used[1].address);
    this->addChild(sprite);
    sprite->setPosition(x, 90);
}

void scene1::buy3(cocos2d::Ref* pSender)
{
    x = x + 90;
    auto sprite = Sprite::create(Used[2].address);
    this->addChild(sprite);
    sprite->setPosition(x, 90);
}

void scene1::buy4(cocos2d::Ref* pSender)
{
    x = x + 90;
    auto sprite = Sprite::create(Used[3].address);
    this->addChild(sprite);
    sprite->setPosition(x, 90);//x的坐标是一个很严重的需要更改的问题
}

void scene1::chessStore(cocos2d::Ref* pSender)
{
    static int x,y,width,height;
    x = 1420;
    y = 200;
    width = 180;
    height = 500;
    s_layer = LayerColor::create(Color4B::WHITE);
    s_layer->setPosition(x, y);
    s_layer->changeHeight(height);
    s_layer->changeWidth(width);
    this->addChild(s_layer, 1);

    /*-------------------set background----------------------*/
    auto sprite = Sprite::create("store_bg.png");
    sprite->setPosition(80, 250);
    s_layer->addChild(sprite);

    /*-------------------set label-------------------------*/
    auto label = Label::createWithTTF("STORE", "fonts/Marker Felt.ttf", 24);
    label->setPosition(80, 490);
    s_layer->addChild(label);

    for (int i = 0; i <= 3; i++)
    {
        int deter = 0;
        deter = rand() % 8;
        Used[i].address = chess_store[deter].address;
        Used[i].money = chess_store[deter].money;
    }

    /*--------------------set chess---------------------------*/
    storeChess(i1);
    auto buy1= MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(scene1::buy1, this));
    auto Buy1= Menu::create(buy1, NULL);
    s_layer->addChild(Buy1, 1);
    Buy1->setPosition(125, 460 - 120 * i1);

    storeChess(i2);
    auto buy2 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(scene1::buy2, this));
    auto Buy2 = Menu::create(buy2, NULL);
    s_layer->addChild(Buy2, 1);
    Buy2->setPosition(125, 460 - 120 * i2);

    storeChess(i3);
    auto buy3 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(scene1::buy3, this));
    auto Buy3 = Menu::create(buy3, NULL);
    s_layer->addChild(Buy3, 1);
    Buy3->setPosition(125, 460 - 120 * i3);

    storeChess(i4);
    auto buy4 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(scene1::buy4, this));
    auto Buy4 = Menu::create(buy4, NULL);
    s_layer->addChild(Buy4, 1);
    Buy4->setPosition(125, 460 - 120 * i4);

    /*----------------------close store-----------------*/
    closeChessStore();
}




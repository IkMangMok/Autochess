#include"scene1.h"
#include"Chess/Chess1.h"
#include<iostream>
#include"AppDelegate.h"
#include"AutoChessScene.h"
using namespace std;
USING_NS_CC;

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
        BackInScene1->setPosition(Vec2(x, y));
    }

    auto back_in_scene1 = Menu::create(BackInScene1, NULL);
    back_in_scene1->setPosition(Vec2::ZERO);
    this->addChild(back_in_scene1, 1);
    
    /*------------------------TMXTiledMap _tileMap---------------------*/
    auto _tileMap = TMXTiledMap::create("test_map1.tmx");              // my first tiled map
    _tileMap->setPosition(origin.x, origin.y);
    this->addChild(_tileMap);


    /*-----------------------Chess test_chess_1------------------------*/
    auto test_chess_1 = Chess::create("test_chess_1.png");
    test_chess_1->setPosition(112, 112);
    this->addChild(test_chess_1, 0);

    //Size size = _tileMap->getMapSize();  //可获取地图尺寸
    //移动演示一：移动到预定坐标处
    ActionInterval* forward_type1 = MoveTo::create(8, Vec2(156, 48));  //这个函数设置了移动的时间以及目的地
    test_chess_1->runAction(forward_type1);           //执行动作：按照forward_type1所设定的方式移动


    /*-----------------------Chess test_chess_2------------------------*/
    auto test_chess_2 = Chess::create("test_chess_2.png");
    test_chess_2->setPosition(112, 176);
    this->addChild(test_chess_2, 0);

    //移动演示二：按照预定移动矢量移动 
    ActionInterval* forward_type2 = MoveBy::create(4, Vec2(-64, -64));  //设定去程的移动时间及移动矢量
    ActionInterval* backward_type2 = forward_type2->reverse();       //使用reverse()成员函数，设定回程的移动时间及矢量
    Action* self_def_movetype2 = Repeat::create(dynamic_cast<FiniteTimeAction*>(Sequence::create(forward_type2, backward_type2, NULL)), 2);  //重复移动函数（参数为动作及重复次数）
    test_chess_2->runAction(self_def_movetype2);     //执行动作：按照self_def_movetype2所设定的方式移动

    /*-----------------------Chess person------------------------*/
    //auto person = Chess::createChess("person.jpg", 0, 0);
    
    //this->addChild(person, 0);
   // this->scheduleUpdate();
    /*-----------------------Chess person------------------------*/
    //auto person1 = Chess::createChess("person.jpg", 500, 500);
   // this->addChild(person1, 0);
   // this->scheduleUpdate();
    //person->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);
   // person1->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);

    return true;

}

void scene1::scene1Back(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
} 
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

    //Size size = _tileMap->getMapSize();  //�ɻ�ȡ��ͼ�ߴ�
    //�ƶ���ʾһ���ƶ���Ԥ�����괦
    ActionInterval* forward_type1 = MoveTo::create(8, Vec2(156, 48));  //��������������ƶ���ʱ���Լ�Ŀ�ĵ�
    test_chess_1->runAction(forward_type1);           //ִ�ж���������forward_type1���趨�ķ�ʽ�ƶ�


    /*-----------------------Chess test_chess_2------------------------*/
    auto test_chess_2 = Chess::create("test_chess_2.png");
    test_chess_2->setPosition(112, 176);
    this->addChild(test_chess_2, 0);

    //�ƶ���ʾ��������Ԥ���ƶ�ʸ���ƶ� 
    ActionInterval* forward_type2 = MoveBy::create(4, Vec2(-64, -64));  //�趨ȥ�̵��ƶ�ʱ�估�ƶ�ʸ��
    ActionInterval* backward_type2 = forward_type2->reverse();       //ʹ��reverse()��Ա�������趨�س̵��ƶ�ʱ�估ʸ��
    Action* self_def_movetype2 = Repeat::create(dynamic_cast<FiniteTimeAction*>(Sequence::create(forward_type2, backward_type2, NULL)), 2);  //�ظ��ƶ�����������Ϊ�������ظ�������
    test_chess_2->runAction(self_def_movetype2);     //ִ�ж���������self_def_movetype2���趨�ķ�ʽ�ƶ�

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
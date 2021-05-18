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
<<<<<<< HEAD
=======
<<<<<<< Updated upstream
=======
>>>>>>> hjr
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
<<<<<<< HEAD
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
=======

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
    
>>>>>>> hjr
    
    auto person = Chess::createChess("person.jpg", 0, 0);
    
    this->addChild(person, 0);
   // this->scheduleUpdate();
    
    auto person1 = Chess::createChess("person.jpg", 500, 500);
    this->addChild(person1, 0);
   // this->scheduleUpdate();
    person->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);
    person1->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);
<<<<<<< HEAD
=======
>>>>>>> Stashed changes
>>>>>>> hjr
    return true;

  

}

void scene1::scene1Back(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
} 
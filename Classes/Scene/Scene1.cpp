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
    
    auto person = Chess::createChess("person.jpg", 0, 0);
    
    this->addChild(person, 0);
   // this->scheduleUpdate();
    
    auto person1 = Chess::createChess("person.jpg", 500, 500);
    this->addChild(person1, 0);
   // this->scheduleUpdate();
    person->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);
    person1->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);
    return true;

  

}

void scene1::menuCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
} 
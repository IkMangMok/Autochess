#include "HelpScene.h"
#include<iostream>
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include "Timer/RoundTimer.h"

using namespace std;
USING_NS_CC;

Scene* HelpScene::createScene()
{
    return HelpScene::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in AutoChessScene.cpp\n");
}
bool HelpScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /*---------------------MenuItemImage HelpBack----------------------*/
    auto BackInHelp = MenuItemImage::create(
        "BackToMenu.png",
        "BackToMenu.png",
        CC_CALLBACK_1(HelpScene::helpBack, this));

    if (BackInHelp == nullptr ||
        BackInHelp->getContentSize().width <= 0 ||
        BackInHelp->getContentSize().height <= 0)
    {
        problemLoading("'BackToMenu.png' and 'BackToMenu.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + BackInHelp->getContentSize().height / 2 + visibleSize.height / 2;
        BackInHelp->setPosition(Vec2(x, y));
    }

    auto back_in_help = Menu::create(BackInHelp, NULL);
    back_in_help->setPosition(Vec2::ZERO);
    this->addChild(back_in_help, 1);


    /*-------------------Lable Help---------------*/
    auto label = Label::createWithTTF("Help", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    /*-------------------RoundTimer test_timer---------------*/
    RoundTimer* test_timer = RoundTimer::create(300);
    test_timer->setPosition(50, 50);
    this->addChild(test_timer);


    return true;

}

void HelpScene::helpBack(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
}
#include "SettingScene.h"
#include<iostream>
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include"AudioEngine.h"
using namespace std;
USING_NS_CC;
static int audioID;
Scene* SettingScene::createScene()
{
    return SettingScene::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in AutoChessScene.cpp\n");
}
bool SettingScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*---------------------MenuItemImage HelpBack----------------------*/
    auto BackInSetting = MenuItemImage::create(
        "BackToMenu.png",
        "BackToMenu.png",
        CC_CALLBACK_1(SettingScene::settingBack, this));

    if (BackInSetting == nullptr ||
        BackInSetting ->getContentSize().width <= 0 ||
        BackInSetting ->getContentSize().height <= 0)
    {
        problemLoading("'BackToMenu.png' and 'BackToMenu.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + BackInSetting->getContentSize().height / 2 + visibleSize.height / 2;
        BackInSetting->setPosition(Vec2(x, y));
    }

    auto back_in_setting = Menu::create(BackInSetting, NULL);
    back_in_setting->setPosition(Vec2::ZERO);
    this->addChild(back_in_setting, 1);


    /*-------------------Lable Help---------------*/
    auto label = Label::createWithTTF("Setting", "fonts/Marker Felt.ttf", 24);
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
    audioID = AudioEngine::play2d("init_music.mp3", true, 1.0f);
    return true;

}

void SettingScene::settingBack(cocos2d::Ref* pSender)
{
    AudioEngine::stop(audioID);
    _director->replaceScene(AutoChess::createScene());
}
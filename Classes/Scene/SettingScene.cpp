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
        BackInSetting->setPosition(Vec2(x, y+100));
    }


    auto back_in_setting = Menu::create(BackInSetting,NULL);
    back_in_setting->setPosition(Vec2::ZERO);
    this->addChild(back_in_setting, 1);

    /*--------------------Music Switch--------------*/
    auto soundoff = MenuItemImage::create("music_off.png", "music_off.png", CC_CALLBACK_1(SettingScene::MusicEnd, this));
    auto SoundOff = Menu::create(soundoff, NULL);
    SoundOff->setPosition(800, 300);
    this->addChild(SoundOff, 1);

    auto soundon = MenuItemImage::create("music_on.png", "music_on.png", CC_CALLBACK_1(SettingScene::MusicOn, this));
    auto SoundOn = Menu::create(soundon, NULL);
    SoundOff->setPosition(800, 300);
    this->addChild(SoundOn, 1);


    /*-------------------Lable Help---------------*/
    auto label = Label::createWithTTF("Setting", "fonts/Marker Felt.ttf", 48);
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

<<<<<<< Updated upstream
    auto sprite1 = Sprite::create("help_bg.jpg");
    sprite1->setPosition(800, 460);
    this->addChild(sprite1);


=======
    /*--------------------Music Switch-------------*/
    auto sound_on = MenuItemImage::create("music_on.png", "music_on.png", CC_CALLBACK_1(SettingScene::musicOn, this));
    auto SoundOn = Menu::create(sound_on, NULL);
    SoundOn->setPosition(800, 400);
    this->addChild(SoundOn, 1);

    auto sound_off = MenuItemImage::create("music_off.png", "music_off.png", CC_CALLBACK_1(SettingScene::musicOff, this));
    auto SoundOff = Menu::create(sound_off, NULL);
    SoundOff->setPosition(800, 300);
    this->addChild(SoundOff, 1);


    auto sprite_bg = Sprite::create("help_bg.jpg");
    sprite_bg->setPosition(800, 460);
    this->addChild(sprite_bg);
>>>>>>> Stashed changes

    return true;

}

void SettingScene::settingBack(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
}
<<<<<<< Updated upstream
void SettingScene::MusicEnd(cocos2d::Ref* pSender)
{
    AudioEngine::pauseAll();
}
void SettingScene::MusicOn(cocos2d::Ref* pSender)
{
    AudioEngine::resumeAll();
=======

void SettingScene::musicOn(cocos2d::Ref* pSender)
{
    AudioEngine::resumeAll();
}

void SettingScene::musicOff(cocos2d::Ref* pSender)
{
    AudioEngine::pauseAll();
>>>>>>> Stashed changes
}
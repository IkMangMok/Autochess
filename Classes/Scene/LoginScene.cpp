#include "cocos2d.h"
#include "AppDelegate.h"
#include"AutoChessScene.h"
#include "LoginScene.h"
#include "GameScene.h"

USING_NS_CC_EXT;
USING_NS_CC;

using namespace ui;

string settingname;

Scene* LoginScene::createScene()
{
    return LoginScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in AutoChessScene.cpp\n");
}

bool LoginScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto sprite_bg = Sprite::create("help_bg.jpg");
    sprite_bg->setPosition(800, 460);
    this->addChild(sprite_bg);

    /*-------------------Lable Login---------------*/
    auto label = Label::createWithTTF("Login", "fonts/Marker Felt.ttf", 48);
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

    /*-------------------Login frame---------------*/

    auto editbox = EditBox::create(Size(299, 59), Scale9Sprite::create("nameframe.png"));
    // editbox1->openKeyboard();

    editbox->setAnchorPoint(Point(0, 0));
    editbox->setPosition(Point(visibleSize.width / 2 - 125, visibleSize.height / 2 + 100));
    editbox->setDelegate(this);
    editbox->setPlaceHolder("InputNickname:");//占位字符 
    editbox->setMaxLength(100);
    editbox->setFontColor(Color3B::BLACK);
    editbox->setTag(1);
    this->addChild(editbox, 1);

    /*-------------------Mode Switch------------------*/

    auto label2 = Label::createWithTTF("Select Mode", "fonts/Marker Felt.ttf", 36);
    if (label2 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label2->setPosition(820, 450);

        // add the label as a child to this layer
        this->addChild(label2, 1);
    }

    auto mode1 = MenuItemImage::create("modeSwitch_1.png", "modeSwitch_1.png", CC_CALLBACK_1(LoginScene::modeAI, this));
    auto MODE1 = Menu::create(mode1, NULL);
    MODE1->setPosition(620, 350);
    this->addChild(MODE1, 1);

    auto mode2 = MenuItemImage::create("modeSwitch_2.png", "modeSwitch_2.png", CC_CALLBACK_1(LoginScene::modeServer, this));
    auto MODE2 = Menu::create(mode2, NULL);
    MODE2->setPosition(820, 350);
    this->addChild(MODE2, 1);

    auto mode3 = MenuItemImage::create("modeSwitch_3.png", "modeSwitch_3.png", CC_CALLBACK_1(LoginScene::modeClient, this));
    auto MODE3 = Menu::create(mode3, NULL);
    MODE3->setPosition(1020, 350);
    this->addChild(MODE3, 1);


    /*-------------------Next button---------------*/
    
    /*auto next = MenuItemImage::create(
        "next.png",
        "next.png",
        CC_CALLBACK_1(LoginScene::menuGameStart, this));

    if (next == nullptr ||
        next->getContentSize().width <= 0 ||
        next->getContentSize().height <= 0)
    {
        problemLoading("'GameStart.jpg' and 'GameStart.jpg'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 2 - 50;
        next->setPosition(Vec2(x, y));
    }

    auto nextbutton = Menu::create(next, NULL);
    nextbutton->setPosition(Vec2::ZERO);
    this->addChild(nextbutton, 1);
    */

    return true;
}

void LoginScene::editBoxEditingDidBegin(EditBox* editBox)
{
    CCLOG("start edit");
}

void LoginScene::editBoxEditingDidEnd(EditBox* editBox)
{
    CCLOG("end edit");
}

void LoginScene::editBoxReturn(EditBox* editBox)
{
    CCLOG("editboxreturn");
    settingname = editBox->getText();
}

void LoginScene::editBoxTextChanged(EditBox* editBox, const std::string& text)
{
    CCLOG("textchanged");
}

void LoginScene::LoginBack(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
}

void LoginScene::menuGameStart(Ref* pSender)   //开始游戏
{
    global_data->GameStartInit(); //初始化全局数据

    _director->replaceScene(GameScene::createScene(settingname));
}

void LoginScene::modeAI(cocos2d::Ref* pSender)
{
    global_data->GameStartInit(); //初始化全局数据

    _director->replaceScene(GameScene::createScene(settingname));
}

void LoginScene::modeServer(cocos2d::Ref* pSender)
{
    global_data->GameStartInit(); //初始化全局数据

    _director->replaceScene(GameScene::createScene(settingname));
}

void LoginScene::modeClient(cocos2d::Ref* pSender)
{
    global_data->GameStartInit(); //初始化全局数据

    _director->replaceScene(GameScene::createScene(settingname));
}
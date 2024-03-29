/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 ;
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "AutoChessScene.h"
#include "HelpScene.h"
#include "SettingScene.h"
#include "LoginScene.h"
#include "GameScene.h"

USING_NS_CC;
static int audioID;
Scene* AutoChess::createScene()
{
    return AutoChess::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in AutoChessScene.cpp\n");
}

// on "init" you need to initialize your instance
bool AutoChess::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    /*----------------MenuItemImage closeItem---------------------*/
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
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /*----------------MenuItemImage GameStart 开始游戏---------------------*/
    auto GameStart = MenuItemImage::create(
        "GameStart.jpg",
        "GameStart.jpg",
        CC_CALLBACK_1(AutoChess::menuGameStart, this));

    if (GameStart == nullptr ||
        GameStart->getContentSize().width <= 0 ||
        GameStart->getContentSize().height <= 0)
    {
        problemLoading("'GameStart.jpg' and 'GameStart.jpg'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + GameStart->getContentSize().height / 2 + visibleSize.height / 2;
        GameStart->setPosition(Vec2(x, y));
    }

    auto gamestart = Menu::create(GameStart, nullptr);
    gamestart->setPosition(Vec2::ZERO);
    this->addChild(gamestart, 1);

    /*----------------MenuItemImage Help 帮助---------------------*/
    auto Help = MenuItemImage::create(
        "Help.png",
        "Help.png",
        CC_CALLBACK_1(AutoChess::menuHelp, this));

    if (Help == nullptr ||
        Help->getContentSize().width <= 0 ||
        Help->getContentSize().height <= 0)
    {
        problemLoading("'Help.png' and 'Help.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y +  visibleSize.height / 2 - 60;
        Help->setPosition(Vec2(x, y));
    }

    auto menuhelp = Menu::create(Help, nullptr);
    menuhelp->setPosition(Vec2::ZERO);
    this->addChild(menuhelp, 1);

    /*----------------MenuItemImage Setting 设置---------------------*/
    auto Setting = MenuItemImage::create(
        "Setting.png",
        "Setting.png",
        CC_CALLBACK_1(AutoChess::menuSetting, this));

    if (Setting == nullptr ||
        Setting->getContentSize().width <= 0 ||
        Setting->getContentSize().height <= 0)
    {
        problemLoading("'Setting.png' and 'Setting.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 2 - 150;
        Setting->setPosition(Vec2(x, y));
    }

    auto menusetting = Menu::create(Setting, nullptr);
    menusetting->setPosition(Vec2::ZERO);
    this->addChild(menusetting, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Main Menu", "fonts/Marker Felt.ttf", 24);

    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    auto sprite1 = Sprite::create("startbg.png");
    sprite1->setPosition(800, 460);
    this->addChild(sprite1);

    return true;
}


void AutoChess::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application

    //AudioEngine::end();

    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void AutoChess::menuGameStart(Ref* pSender)   //开始游戏
{
    global_data->GameStartInit(); //初始化全局数据

    _director->replaceScene(LoginScene::createScene());


}

void AutoChess::menuHelp(Ref* pSender)   //帮助
{

    _director->replaceScene(HelpScene::createScene());
}
void AutoChess::menuSetting(Ref* pSender)   //帮助
{

    _director->replaceScene(SettingScene::createScene());
}


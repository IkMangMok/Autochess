#include "cocos2d.h"
#include "AppDelegate.h"
#include"AutoChessScene.h"
#include "LoginScene.h"
#include"Scene1.h"

USING_NS_CC_EXT;
USING_NS_CC;

using namespace ui;

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

    /*-------------------Lable Login---------------*/
    auto label = Label::createWithTTF("Login", "fonts/Marker Felt.ttf", 36);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height/2+100));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    /*-------------------Login frame---------------*/

    auto editbox = EditBox::create(Size(259, 39), Scale9Sprite::create("nameframe.png"));
    // editbox1->openKeyboard();

    editbox->setAnchorPoint(Point(0, 0));
    editbox->setPosition(Point(visibleSize.width / 2-125, visibleSize.height / 2));
    editbox->setDelegate(this);
    editbox->setPlaceHolder("name:");//占位字符
    editbox->setMaxLength(100);
    editbox->setFontColor(Color3B::BLACK);//设置输入字体的颜色
    editbox->setTag(1);
    this->addChild(editbox, 1);

    /*-------------------Next button---------------*/
    
    auto next = MenuItemImage::create(
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
   // CCLOG("get-->%s", editBox->getText());
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

    _director->replaceScene(scene1::createScene());  //切换场景
}
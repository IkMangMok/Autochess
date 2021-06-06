#include "HelpScene.h"
#include<iostream>
#include"AppDelegate.h"
#include"AutoChessScene.h"
#include "Timer/RoundTimer.h"
#include"AudioEngine.h"
#include"2d\CCAnimation.h"



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
static void chessAnimation(string picturename, const int picturenum, Point location, Scene* myScene, const float speed = 0.08f, const int loop = -1)
{
    Sprite* sp = Sprite::create(picturename);
    sp->setPosition(location);

   // sp->setFlippedX(true);//X轴翻转(根据后续双方位置关系来定，待定)

    myScene->addChild(sp);
    

    Animation* animation = Animation::create();

    const char* picname = picturename.c_str();

    for (int i = 0; i <= picturenum; i++) {
        char key[32];
        sprintf(key, picname, i);
        animation->addSpriteFrameWithFile(key);
    }

    animation->setDelayPerUnit(speed); //调节速度
    animation->setRestoreOriginalFrame(true); //是否返回第一帧
    animation->setLoops(loop); //重复次数   -1无限循环

    FiniteTimeAction* animate = Animate::create(animation);
    sp->runAction(animate);
}

static void shootbullet(string picturename, Point srcPos, Point dstPos, Scene* myScene)
{
    Sprite* bullet = Sprite::create(picturename);        // 加载子弹图片
    myScene->addChild(bullet);
    bullet->setPosition(srcPos);  // 设置子弹的发射位置

    //设置动作       
    Point deltaPos = dstPos - srcPos;
    auto move = MoveBy::create(1.f, deltaPos);
    auto back = MoveTo::create(0.f, srcPos);
    auto appear = FadeIn::create(0.f);
    auto disappear = FadeOut::create(0.f);

    auto actionTo = Sequence::createWithTwoActions(appear, move);
    auto actionBack = Sequence::createWithTwoActions(disappear, back);
    auto all = Sequence::createWithTwoActions(actionTo, actionBack);
    bullet->runAction(RepeatForever::create(all));
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
    auto label = Label::createWithTTF("Help", "fonts/Marker Felt.ttf", 48);
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

    /*auto sprite_bg = Sprite::create("help_bg.jpg");
    sprite_bg->setPosition(800, 460);
    this->addChild(sprite_bg);*/

    /*-------------------test animation---------------*/

   // chessAnimation("Cherry%d.png", 6, Point(origin.x + visibleSize.width / 2,origin.y + visibleSize.height / 2 - 300), this, 0.1f);  
   // chessAnimation("upgrade_bean%d.png", 15, Point(origin.x + visibleSize.width / 2,origin.y + visibleSize.height / 2 - 400), this);
   // chessAnimation("Flower%d.png", 12, Point(origin.x + visibleSize.width / 2,origin.y + visibleSize.height / 2 - 250), this);
    //chessAnimation("Mushroom%d.png", 15, Point(origin.x + visibleSize.width / 2,origin.y + visibleSize.height / 2 - 350), this);

    chessAnimation("nut%d.png", 15, Point(origin.x + visibleSize.width / 2 + 100, origin.y + visibleSize.height / 2 - 100), this);
    chessAnimation("Bean%d.png", 12, Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - 100), this, 0.1f);
    Sprite* dead = Sprite::create("Beandead.png");       
    this->addChild(dead);
    dead->setPosition(Point(origin.x + visibleSize.width / 2 + 100, origin.y + visibleSize.height / 2 - 200));  // 设置子弹的发射位置

    //设置动作         
    auto disappear = FadeOut::create(1.f);    
    dead->runAction(disappear);

    shootbullet("pea.png", Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - 100),
        Point(origin.x + visibleSize.width / 2 + 100, origin.y + visibleSize.height / 2 - 100), this);    


    return true;

}

void HelpScene::helpBack(cocos2d::Ref* pSender)
{

    _director->replaceScene(AutoChess::createScene());
}

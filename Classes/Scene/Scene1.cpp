#include"scene1.h"
#include"AppDelegate.h"
#include"AutoChessScene.h"

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
        "Back_test.png",
        "Back_test.png",
        CC_CALLBACK_1(scene1::scene1Back, this));

    if (BackInScene1 == nullptr ||
        BackInScene1->getContentSize().width <= 0 ||
        BackInScene1->getContentSize().height <= 0)
    {
        problemLoading("'Back_test.png' and 'Back_test.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width-25;
        float y = origin.y+880;// +BackInScene1->getContentSize().height / 2 + visibleSize.height / 2;
        BackInScene1->setPosition(Vec2(x, y));
    }

    auto back_in_scene1 = Menu::create(BackInScene1, NULL);  //返回按钮
    back_in_scene1->setPosition(Vec2::ZERO);
    this->addChild(back_in_scene1, 1);
    

    /*------------------------TMXTiledMap _tileMap---------------------*/
    auto _tileMap = TMXTiledMap::create("playmap2.tmx");              // my first tiled map
    _tileMap->setPosition(origin.x-1, origin.y-1);
    this->addChild(_tileMap);

    /*------------------------开关按钮（声音、暂停）---------------------*/
    /*MenuItemToggle* toggleItem = MenuItemToggle::createWithCallback(
        menu_selector(HelloWorld::togglemenuCallBack),
        MenuItemFont::create("On"),
        MenuItemFont::create("Off"),
        NULL);
    /*auto _openItem = MenuItemImage::create(
        "SettingSceneImages/openMusicItem_1.png",
        "SettingSceneImages/openMusicItem_2.png"
    );
    auto _closeItem = MenuItemImage::create(
        "SettingSceneImages/closeMusicItem_1.png",
        "SettingSceneImages/closeMusicItem_2.png");
    //组合按钮
    auto setMusicMenuToggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingScene::menuSetMusicCallback, this),
        _openItem, _closeItem, NULL);
    setMusicMenuToggle->setPosition(Point(0, 0));


    /*------------------------Blood---------------------*/

    string picture = "duck.jpg";
    auto icon = Sprite::create(picture);   //头像
    icon->setPosition(Point(icon->getContentSize().width-20, origin.y + visibleSize.height - icon->getContentSize().height)); //设置位置
    this->addChild(icon);            //加到默认图层里面去

    string name = "player";//后续添加“起名字”功能，让玩家自己输入名字
    auto nameLabel = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 24);
    if (nameLabel == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        nameLabel->setPosition(Vec2(origin.x+ nameLabel->getContentSize().width+40,origin.y + visibleSize.height - nameLabel->getContentSize().height));
        this->addChild(nameLabel, 1);
    }
    
   



    auto person = Chess::createChess("test_chess_1.png", 112, 112);
    this->addChild(person, 0);
    person->scheduleUpdate();
    auto person1 = Chess::createChess("test_chess_2.png", 112, 176);
    this->addChild(person1, 0);
    person1->scheduleUpdate();
  //  auto person2 = Chess::createChess("person.jpg", 1000, 200);
   // this->addChild(person2, 0);
   // person2->scheduleUpdate();
    ccArrayAppendObject(pArray, person);
    ccArrayAppendObject(pArray, person1);
 //   ccArrayAppendObject(pArray, person2);

    this->scheduleUpdate();  //两个棋子会互相搜索到对方 
    return true;


    
}

void scene1::scene1Back(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
} 

void scene1::ChessMove(Chess *chess)
{
    
    Point a(0, 0);
    Point chessPosition = chess->getPosition();
    float distance = 9999999;
    if (chess->AttackTarget == NULL)    //如果已经有攻击目标则不搜寻
    {
        for (int i = 0; i < pArray->num; i++)
        {
            auto temp = pArray->arr[i];
            Point atemp = ((Chess*)temp)->getPosition();
            int distanceTemp = sqrt((atemp.x - chessPosition.x) * (atemp.x - chessPosition.x) +
                (atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //求距离
            if (distanceTemp < distance && distanceTemp>0)  //确定攻击目标
            {
                distance = distanceTemp;
                a = atemp;
                chess->AttackTarget = (Chess*)temp;
            }
        }
    }
    else
    {
        distance= sqrt((chess->AttackTarget->getPosition().x - chessPosition.x)
            * (chess->AttackTarget->getPosition().x - chessPosition.x) +
            (chess->AttackTarget->getPosition().y - chessPosition.y)
            * (chess->AttackTarget->getPosition().y - chessPosition.y));
    }
    /*移动，以1e-2为单位移动
    */
    chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * 1e-2);  
    chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * 1e-2);  //将新位置传入类中
}
void scene1::update(float dt)
{
    for (int i = 0; i < pArray->num; i++)
    {
        ChessMove((Chess*)(pArray->arr[i]));
    } 
}

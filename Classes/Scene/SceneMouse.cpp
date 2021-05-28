#include"SceneMouse.h"

Scene* SceneMouse::createScene()
{
    return SceneMouse::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in AutoChessScene.cpp\n");
}
bool SceneMouse::init()
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


    /*---------------------MenuItemImage BackInSceneMouse----------------------*/
    auto BackInSceneMouse = MenuItemImage::create(
        "BackToMenu.png",
        "BackToMenu.png",
        CC_CALLBACK_1(SceneMouse::SceneMouseBack, this));

    if (BackInSceneMouse == nullptr ||
        BackInSceneMouse->getContentSize().width <= 0 ||
        BackInSceneMouse->getContentSize().height <= 0)
    {
        problemLoading("'BackToMenu.png' and 'BackToMenu.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + 50;// +BackInSceneMouse->getContentSize().height / 2 + visibleSize.height / 2;
        BackInSceneMouse->setPosition(Vec2(x, y));
    }

    auto back_in_SceneMouse = Menu::create(BackInSceneMouse, NULL);  //返回按钮
    back_in_SceneMouse->setPosition(Vec2::ZERO);
    this->addChild(back_in_SceneMouse, 1);


    /*------------------------TMXTiledMap _tileMap---------------------*/
    auto _tileMap = TMXTiledMap::create("test_map1.tmx");              // my first tiled map
    _tileMap->setPosition(origin.x, origin.y);
    this->addChild(_tileMap);

    auto person = Chess::createChess("test_chess_1.png", 1120, 1120);
    this->addChild(person, 0);

    auto person1 = TestChess::createChess("test_chess_2.png", 112, 176);
    this->addChild(person1, 0);

    auto person2 = Chess::createChess("test_chess_1.png", 1000, 200);
    this->addChild(person2, 0);
    // person2->scheduleUpdate();
    ccArrayAppendObject(pArray, person);  //将棋子放入数组中
    ccArrayAppendObject(pArray, person1);
    ccArrayAppendObject(pArray, person2);

    this->scheduleUpdate();  //两个棋子会互相搜索到对方 
    return true;

}



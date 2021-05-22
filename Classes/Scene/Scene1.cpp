#include"scene1.h"
USING_NS_CC;

Scene* scene1::createScene()
{
    return scene1::create();
}

bool scene1::init()
{
<<<<<<< Updated upstream
=======
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*---------------------MenuItemImage BackInScene1----------------------*/
    auto BackInScene1 = MenuItemImage::create(
        "BackToMenu.png",
        "BackToMenu.png",
        CC_CALLBACK_1(scene1::scene1Back, this));

    if (BackInScene1 == nullptr ||
        BackInScene1->getContentSize().width <= 0 ||
        BackInScene1->getContentSize().height <= 0)
    {
        problemLoading("'BackToMenu.png' and 'BackToMenu.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + 50;// +BackInScene1->getContentSize().height / 2 + visibleSize.height / 2;
        BackInScene1->setPosition(Vec2(x, y));
    }

    auto back_in_scene1 = Menu::create(BackInScene1, NULL);
    back_in_scene1->setPosition(Vec2::ZERO);
    this->addChild(back_in_scene1, 1);
    
<<<<<<< Updated upstream
=======
    /*------------------------TMXTiledMap _tileMap---------------------*/
    auto _tileMap = TMXTiledMap::create("test_map1.tmx");              // my first tiled map
    _tileMap->setPosition(origin.x, origin.y);
    this->addChild(_tileMap);


    /*-----------------------Chess test_chess_1------------------------*/
    auto test_chess_1 = Chess::create("test_chess_1.png");
    test_chess_1->setPosition(112, 112);
    this->addChild(test_chess_1, 0);


    /*-----------------------Chess test_chess_2------------------------*/
    auto test_chess_2 = Chess::create("test_chess_2.png");
    test_chess_2->setPosition(112, 176);
    this->addChild(test_chess_2, 0);

>>>>>>> Stashed changes
    
    /*-----------------------Chess person------------------------*/
    //auto person = Chess::createChess("person.jpg", 0, 0);
    
    //this->addChild(person, 0);
   // this->scheduleUpdate();
    /*-----------------------Chess person------------------------*/
    //auto person1 = Chess::createChess("person.jpg", 500, 500);
   // this->addChild(person1, 0);
   // this->scheduleUpdate();
<<<<<<< Updated upstream
    person->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);
    person1->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);
>>>>>>> Stashed changes
    return true;
=======
    //person->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);
   // person1->schedule(CC_SCHEDULE_SELECTOR(Chess::scan), 0.01f);

    return true;

>>>>>>> Stashed changes
}

void scene1::scene1Back(cocos2d::Ref* pSender)
{
    _director->replaceScene(AutoChess::createScene());
} 
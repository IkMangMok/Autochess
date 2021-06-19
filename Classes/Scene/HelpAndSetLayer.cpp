#include "HelpAndSetLayer.h"

HelpAndSetLayer* HelpAndSetLayer::createLayer()
{
	auto layer = HelpAndSetLayer::create();
	layer->retain();

	layer->autorelease();
	return layer;
}

bool HelpAndSetLayer::init()
{
    this->setPosition(0, 0);
    MenuItemImage* BackInScene = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
        CC_CALLBACK_1(HelpAndSetLayer::BackToMenu, this));
    Menu* back_in_scene = Menu::create(BackInScene, nullptr);
    back_in_scene->setPosition(12, 885);
    this->addChild(back_in_scene, 1);


    return true;
}

void HelpAndSetLayer::BackToMenu(cocos2d::Ref* pSender)
{
    player1data.remain();
    player2data.remain();
	_director->replaceScene(AutoChess::createScene());
}


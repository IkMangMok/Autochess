#pragma once
#include"AutoChessScene.h"
#include "VictoryScene.h"

Scene* VictoryScene::createVictoryScene()
{
	return VictoryScene::create();
}

bool VictoryScene::init()
{
	if (!Scene::create())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("startbg.png");
	sprite1->setPosition(800, 460);
	this->addChild(sprite1);

	/*---------------MenuItemImage* BackToMenu--------------*/
	auto BackToMenu = MenuItemImage::create("BackToMenu.png", "BackToMenu.png",CC_CALLBACK_1(VictoryScene::backToMenu,this));
	this->addChild(BackToMenu);
	BackToMenu->setPosition(600, 100);

	auto back_to_menu = Menu::create(BackToMenu, NULL);
	back_to_menu->setPosition(Vec2::ZERO);
	this->addChild(back_to_menu, 1);


	/*----------------Sprite* victory_image-----------------*/
	auto victory_image = Sprite::create("VictoryImage.png");
	this->addChild(victory_image);
	victory_image->setPosition(600, 450);


	return true;
}
void VictoryScene::backToMenu(cocos2d::Ref* pSender)
{
	_director->replaceScene(AutoChess::createScene());
}
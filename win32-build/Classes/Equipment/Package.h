#pragma once
#include "cocos2d.h"
#include "Data/GameData.h"
#include "Data/PlayerData.h"
#include "Equipment.h"
#include "EquipmentFile.h"

USING_NS_CC;

class Package:public Layer
{
public:
	
	static Package* createPackage();
	virtual bool init();

	CREATE_FUNC(Package);
private:
	int TotalSlot = 12;

	Sprite* packageImage = Sprite::create("Package.png");
	MenuItemImage* OpenPackage = MenuItemImage::create(
		"PackageButton.png",
		"PackageButton.png",
		CC_CALLBACK_1(Package::openPackage, this));
	MenuItemImage* ClosePackage = MenuItemImage::create(
		"PackageButton.png",
		"PackageButton.png",
		CC_CALLBACK_1(Package::closePackage, this));

	void SlotPositionInit();     //初始化插槽坐标数组
	void openPackage(cocos2d::Ref* pSender);   //打开背包按钮
	void closePackage(cocos2d::Ref* pSender);  //关闭背包数组
	void ShowEquipment();             //打开背包时，展示装备
	void HideEquipment();             //关闭背包时，隐藏装备

	void ObtainEquipment(int game_turn);  //按回合发放装备

	friend class GameScene;
};


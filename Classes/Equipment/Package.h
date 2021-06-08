#pragma once
#include "cocos2d.h"
#include "Data/GameData.h"
#include "Data/PlayerData.h"

#include "Equipment/Equipment.h"
#include "Equipment/Gun.h"
#include "Equipment/Knife.h"

#define GUN 1
#define KNIFE 2

USING_NS_CC;


class Package :public Layer
{
public:
	static Package* createPackage();
	CREATE_FUNC(Package);
	virtual bool init();

private:
	int total_slot = 12;  //4列*3行插槽
	int once_shown = 0;   //新场景中是否曾经打开背包

	Sprite* package_image = Sprite::create("Package.png");   //创造图片
	MenuItemImage* OpenPackage = MenuItemImage::create(
		"PackageButton.png",
		"PackageButton.png",
		CC_CALLBACK_1(Package::openPackage, this));
	MenuItemImage* ClosePackage = MenuItemImage::create(
		"PackageButton.png",
		"PackageButton.png",
		CC_CALLBACK_1(Package::closePackage, this));


	void SlotPositionInit();  //初始化插槽位置
	void openPackage(cocos2d::Ref* pSender);              //打开背包
	void closePackage(cocos2d::Ref* pSender);             //关闭背包
	void Package::ShowEquipment();                        //显示背包装备
	void Package::HideEquipment();

	void EquipMove(Equipment* equip);

	void ObtainEquipment(int game_turn);        //获取装备


	friend class scene1;
};

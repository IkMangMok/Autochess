#pragma once
#include "cocos2d.h"
#include "Data/GameData.h"
#include "Data/PlayerData.h"
#include "Equipment.h"
#include "Gun.h"
#include "Knife.h"

USING_NS_CC;

class Package:public Layer
{
public:
	static Package* createPackage();
	CREATE_FUNC(Package);
	virtual bool init();

private:
	int total_slot = 12;
	
	Sprite* package_image = Sprite::create("Package.png");
	MenuItemImage* OpenPackage = MenuItemImage::create(
		"PackageButton.png",
		"PackageButton.png",
		CC_CALLBACK_1(Package::openPackage, this));
	MenuItemImage* ClosePackage = MenuItemImage::create(
		"PackageButton.png",
		"PackageButton.png",
		CC_CALLBACK_1(Package::closePackage, this));

	void SlotPositionInit();     //��ʼ�������������
	void openPackage(cocos2d::Ref* pSender);   //�򿪱�����ť
	void closePackage(cocos2d::Ref* pSender);  //�رձ�������
	void ShowEquipment();             //�򿪱���ʱ��չʾװ��
	void HideEquipment();             //�رձ���ʱ������װ��

	void ObtainEquipment(int game_turn);  //���غϷ���װ��

	friend class GameScene;
};


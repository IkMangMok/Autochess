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

	void SlotPositionInit();     //��ʼ�������������
	void openPackage(cocos2d::Ref* pSender);   //�򿪱�����ť
	void closePackage(cocos2d::Ref* pSender);  //�رձ�������
	void ShowEquipment();             //�򿪱���ʱ��չʾװ��
	void HideEquipment();             //�رձ���ʱ������װ��

	void ObtainEquipment(int game_turn);  //���غϷ���װ��

	friend class GameScene;
};


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
	int total_slot = 12;  //4��*3�в��
	int once_shown = 0;   //�³������Ƿ������򿪱���

	Sprite* package_image = Sprite::create("Package.png");   //����ͼƬ
	MenuItemImage* OpenPackage = MenuItemImage::create(
		"PackageButton.png",
		"PackageButton.png",
		CC_CALLBACK_1(Package::openPackage, this));
	MenuItemImage* ClosePackage = MenuItemImage::create(
		"PackageButton.png",
		"PackageButton.png",
		CC_CALLBACK_1(Package::closePackage, this));


	void SlotPositionInit();  //��ʼ�����λ��
	void openPackage(cocos2d::Ref* pSender);              //�򿪱���
	void closePackage(cocos2d::Ref* pSender);             //�رձ���
	void Package::ShowEquipment();                        //��ʾ����װ��
	void Package::HideEquipment();

	void EquipMove(Equipment* equip);

	void ObtainEquipment(int game_turn);        //��ȡװ��


	friend class scene1;
};

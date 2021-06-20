#include "Package.h"

Package* Package::createPackage()
{
	return Package::create();
}
bool Package::init()
{
	if (!Layer::create())
		return false;

	/*init slot's position*/
	SlotPositionInit();
	/*gain new equipment*/
	ObtainEquipment(global_data->game_turn);
	/*init image of package frame*/
	packageImage = Sprite::create("Package.png");
	this->addChild(packageImage);
	packageImage->setPosition(10000, 10000);
	/*init open button*/
	OpenPackage->setPosition(400, 400);
	auto open_package = Menu::create(OpenPackage, NULL);
	open_package->setPosition(Vec2::ZERO);
	this->addChild(open_package, 1);
	/*init close button*/
	ClosePackage->setPosition(10000, 10000);
	auto close_package = Menu::create(ClosePackage, NULL);
	close_package->setPosition(Vec2::ZERO);
	this->addChild(close_package, 2);


	if (player1data.is_package_opened == 1)
	{
		/*show the frame*/
		(this->packageImage)->setPosition(1298, 397);

		/*reset the button*/
		(this->OpenPackage)->setPosition(10000, 10000);
		(this->ClosePackage)->setPosition(400, 400);

		/*show equipment*/
		ShowEquipment();
	}
	/*---------------init end -----------------*/
	return true;
}
void Package::SlotPositionInit()     //初始化插槽坐标数组
{
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int tmpX_1 = 1300 + j * 50;         //背包插槽的坐标
			int tmpY_1 = 610 - i * 70;

			if (index < player1data.occupied_slot)
				player1data.packageSlot[i][j].is_occupied = 1;
			else
				player1data.packageSlot[i][j].is_occupied = 0; //初始化为未占用状态
			if (index < player2data.occupied_slot)
				player2data.packageSlot[i][j].is_occupied = 1;
			else
				player2data.packageSlot[i][j].is_occupied = 0; //初始化为未占用状态
			
			//player1data.packageSlot[i][j].is_equiped = -1; //未装备，初始化为-1
			player1data.slotPoint[index].set(tmpX_1, tmpY_1);
			index++;
		}
	}
}
void Package::openPackage(cocos2d::Ref* pSender)   //打开背包按钮
{
	/*show the package frame*/
	(this->packageImage)->setPosition(1298, 397);

	/*reset the position of button*/
	(this->OpenPackage)->setPosition(10000, 10000);
	(this->ClosePackage)->setPosition(400, 400);

	/*show the unequiped-equipment*/
	ShowEquipment();

	/*reset the index*/
	player1data.is_package_opened = 1;
}
void Package::closePackage(cocos2d::Ref* pSender)  //关闭背包数组
{
	/*remove the frame of package*/
	(this->packageImage)->setPosition(10000, 10000);

	/*reset the button*/
	(this->OpenPackage)->setPosition(400, 400);
	(this->ClosePackage)->setPosition(10000, 10000);

	/*hide the unequiped-equipment*/
	HideEquipment();

	/*reset the index*/
	player1data.is_package_opened = 0;
}
void Package::ShowEquipment()             //打开背包时，展示装备
{
	for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
	{

		((Equipment*)(player1data.UnequipedEquipment->arr[i]))->retain();
		((Equipment*)(player1data.UnequipedEquipment->arr[i]))->removeFromParent();

	}
	for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
	{
		if (i < 12)
			((Equipment*)(player1data.UnequipedEquipment->arr[i]))->setPosition(player1data.slotPoint[i]);
		this->addChild((Equipment*)(player1data.UnequipedEquipment->arr[i]));
			
		
	}
}
void Package::HideEquipment()             //关闭背包时，隐藏装备
{
	for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
	{
		switch (((Equipment*)player1data.UnequipedEquipment->arr[i])->type)
		{
			case GUN:
				((Gun*)(player1data.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);
				((Gun*)(player1data.UnequipedEquipment->arr[i]))->removeFromParent();
				break;
			case KNIFE:
				((Knife*)(player1data.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);
				((Knife*)(player1data.UnequipedEquipment->arr[i]))->removeFromParent();
				break;
		}
	}
}

void Package::ObtainEquipment(int game_turn)  //按回合发放装备
{
	if (/*game_turn % 3 == 0 &&*/ game_turn > -1)
	{
		/*player1*/
		if (player1data.occupied_slot < 12)
		{
			int a = rand() % 10;
			if (a <= 7)
			{
				Gun* tmp = Gun::createGun();
				ccArrayAppendObject(player1data.UnequipedEquipment, tmp);
				tmp->setPosition(10000, 10000);
			}
			else
			{
				Knife* tmp = Knife::createKnife();
				ccArrayAppendObject(player1data.UnequipedEquipment, tmp);
				tmp->setPosition(10000, 10000);
			}
			player1data.occupied_slot++;
		}
		/*player2*/
		if (player2data.occupied_slot < 12)
		{
			int b = rand() % 10;
			if (b <= 7)
			{
				Gun* tmp = Gun::createGun();
				ccArrayAppendObject(player2data.UnequipedEquipment, tmp);
				tmp->setPosition(10000, 10000);
			}
			else
			{
				Knife* tmp = Knife::createKnife();
				ccArrayAppendObject(player2data.UnequipedEquipment, tmp);
				tmp->setPosition(10000, 10000);
			}
			player2data.occupied_slot++;
		}
	}
}
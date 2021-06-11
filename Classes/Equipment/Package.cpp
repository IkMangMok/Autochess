#include "Package.h"

Package* Package::createPackage()
{
	return Package::create();
}

bool Package::init()
{
	if (!Layer::create())
		return  false;

	/*init slot's position*/
	SlotPositionInit();
	/*gain new equipment*/
	ObtainEquipment(global_data->game_turn);
	/*init image of package frame*/
	package_image = Sprite::create("Package.png");
	this->addChild(package_image);
	package_image->setPosition(10000, 10000);
	/*init open button*/
	OpenPackage->setPosition(800, 500);
	auto open_package = Menu::create(OpenPackage, NULL);
	open_package->setPosition(Vec2::ZERO);
	this->addChild(open_package, 1);
	/*init close button*/
	ClosePackage->setPosition(10000, 10000);
	auto close_package = Menu::create(ClosePackage, NULL);
	close_package->setPosition(Vec2::ZERO);
	this->addChild(close_package, 2);

	/*----------------------Array of Equipments------------------*/
	for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
	{
		switch (((Equipment*)player1data.UnequipedEquipment->arr[i])->type)
		{
			case GUN:
				this->addChild((Gun*)(player1data.UnequipedEquipment->arr[i]));
				if (1 == player1data.is_package_opened)
					((Gun*)(player1data.UnequipedEquipment->arr[i]))->setPosition(player1data.slotPoint[i]);
				else
					((Gun*)(player1data.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);
				break;

			case KNIFE:
				this->addChild((Knife*)(player1data.UnequipedEquipment->arr[i]));
				if (1 == player1data.is_package_opened)
					((Knife*)(player1data.UnequipedEquipment->arr[i]))->setPosition(player1data.slotPoint[i]);
				else
					((Knife*)(player1data.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);
				break;
		}

		if (player1data.is_package_opened == 1)
		{
			/*show the package frame*/
			(this->package_image)->setPosition(1298, 397);

			/*reset the position of button*/
			(this->OpenPackage)->setPosition(10000, 10000);
			(this->ClosePackage)->setPosition(800, 500);

			/*show the unequiped-equipment*/
			ShowEquipment();
		}
		/*---------init end----------*/
		return true;
	}

}

/*init slot's position*/
void Package::SlotPositionInit()
{
	/*only 12 slots totally,so init one by one*/
	int index = 0;
	for(int i=0;i<3;i++)
		for (int j = 0; j < 4; j++)
		{
			int tmpX_1 = 1300 + j * 50;         //背包插槽的坐标
			int tmpY_1 = 610 - i * 70;
			player1data.packageSlot[i][j].is_occupied = 0; //初始化为未占用状态
			player1data.packageSlot[i][j].is_equiped = -1; //未装备，初始化为-1
			player1data.slotPoint[index].set(tmpX_1, tmpY_1);
			index++;
		}
}

/*open package*/
void Package::openPackage(cocos2d::Ref* pSender)
{
	/*show the package frame*/
	(this->package_image)->setPosition(1298, 397);

	/*reset the position of button*/
	(this->OpenPackage)->setPosition(10000, 10000);
	(this->ClosePackage)->setPosition(800, 500);

	/*show the unequiped-equipment*/
	ShowEquipment();

	/*reset the index*/
	player1data.is_package_opened = 1;
}

/*close the package*/
void Package::closePackage(cocos2d::Ref* pSender)
{
	/*remove the frame of package*/
	(this->package_image)->setPosition(10000, 10000);

	/*reset the button*/
	(this->OpenPackage)->setPosition(800, 500);
	(this->ClosePackage)->setPosition(10000, 10000);

	/*hide the unequiped-equipment*/
	HideEquipment();

	/*reset the index*/
	player1data.is_package_opened = 0;
}

/*obtain your equipment (by game turn)*/
void Package::ObtainEquipment(int game_turn)
{
	if (game_turn % 3 == 0)  //在此处设定出装规则
	{
		/*玩家1*/
		if (player1data.occupied_slot < 12)
		{
			int a = rand() % 10;     //生成随机数
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
		/*玩家2*/
		
	}
}

/*show equipment within packagge*/
void Package::ShowEquipment()
{
	for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
	{
		switch (((Equipment*)player1data.UnequipedEquipment->arr[i])->type)
		{
			case GUN:
				((Gun*)(player1data.UnequipedEquipment->arr[i]))->setPosition(player1data.slotPoint[i]);
				break;
			case KNIFE:
				((Knife*)(player1data.UnequipedEquipment->arr[i]))->setPosition(player1data.slotPoint[i]);
				break;
		}
	}
}

/*hide equipment*/
void Package::HideEquipment()
{
	for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
	{
		switch (((Equipment*)player1data.UnequipedEquipment->arr[i])->type)
		{
			case GUN:
				((Gun*)(player1data.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);
				break;
			case KNIFE:
				((Knife*)(player1data.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);
				break;
		}
	}
}
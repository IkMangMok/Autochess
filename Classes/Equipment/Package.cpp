#include "Package.h"
#define CCRANDOM_0_1() ((float)rand()/RAND_MAX)

Package* Package::createPackage()
{
	return Package::create();
	//temp->initWithFile(filename);
	//package->autorelease();0
}

bool Package::init()
{
	if (!Layer::create())
	{
		return false;
	}


	/*------------------Slot's Position init-----------------*/
	SlotPositionInit();

	/*------------------Sprite package_image-----------------*/
	package_image = Sprite::create("Package.png");
	this->addChild(package_image);
	package_image->setPosition(10000, 10000);


	/*----------------------Button OpenPackage----------------*/
	OpenPackage->setPosition(800, 500);
	auto open_package = Menu::create(OpenPackage, NULL);  //返回按钮
	open_package->setPosition(Vec2::ZERO);
	this->addChild(open_package, 1);

	/*--------------------Button ClosePackage----------------*/
	ClosePackage->setPosition(10000, 10000);
	auto close_package = Menu::create(ClosePackage, NULL);  //返回按钮
	close_package->setPosition(Vec2::ZERO);
	this->addChild(close_package, 2);
	

	/*-------------------Array of equipments---------------*/
	for (int i = 0; i < player_data1.UnequipedEquipment->num; i++)
	{
		switch (((Equipment*)player_data1.UnequipedEquipment->arr[i])->type)
		{
			case GUN:
				this->addChild((Gun*)(player_data1.UnequipedEquipment->arr[i]));
				if (player_data1.package_is_opened == 1)
					((Gun*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(player_data1.slotPoint[i]);
				else
					((Gun*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);
				break;

			case KNIFE:
				this->addChild((Knife*)(player_data1.UnequipedEquipment->arr[i]));
				if (player_data1.package_is_opened == 1)
					((Knife*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(player_data1.slotPoint[i]);
				else
					((Knife*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);
				break;

		}
		
	}

	/*-----------------------init end---------------------------*/

	return true;
}

/*初始化插槽坐标*/
void Package::SlotPositionInit()
{
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
		{
			player_data1.packageSlot[i][j].x = 1300 + j * 50;  //先瞎设，到时候再找具体位置
			player_data1.packageSlot[i][j].y = 610 - i * 70;
			player_data1.packageSlot[i][j].is_occupied = 0;  //初始化为未占用状态
			player_data1.packageSlot[i][j].is_equiped = -1;		   //初始化为-1
			player_data1.slotPoint[k].set(player_data1.packageSlot[i][j].x, player_data1.packageSlot[i][j].y); //设置Point坐标系对应位置
			k++;
		}
}

/*打开装备背包*/
void Package::openPackage(cocos2d::Ref* pSender)
{
	//AudioEngine::stop(audioID);
	(this->package_image)->setPosition(1298, 397);   //显示背包框架
	(this->OpenPackage)->setPosition(10000, 10000);
	(this->ClosePackage)->setPosition(800, 500);

	ShowEquipment();                                 //显示背包中的装备

	(player_data1.package_is_opened) = 1;
}
/*关闭装备背包*/
void Package::closePackage(cocos2d::Ref* pSender)
{
	//AudioEngine::stop(audioID);
	(this->package_image)->setPosition(10000, 10000);   //移除背包框架
	(this->OpenPackage)->setPosition(800, 500);
	(this->ClosePackage)->setPosition(10000, 10000);

	HideEquipment();                                 //显示背包中的装备

	(player_data1.package_is_opened) = 0;
}

/*获取装备（到背包）*/
void Package::ObtainEquipment(int game_turn)
{
	if (game_turn % 2 == 0)
	{
		int a = rand() % 10;
		if (a <= 7)                         //按一定比例设置
		{
			Gun* tmp = Gun::createGun();
			ccArrayAppendObject(player_data1.UnequipedEquipment, tmp);
			tmp->setPosition(10000, 10000);
			
		}
		else
		{
			Knife* tmp = Knife::createKnife();
			ccArrayAppendObject(player_data1.UnequipedEquipment, tmp);
			tmp->setPosition(10000, 10000);

		}
		//this->addChild(tmp);
		//this->addChild(tmp);
		//tmp->initWithFile("Gun.png");
		player_data1.occupied_slot++;
	}
}

/*显示背包中的装备*/
void Package::ShowEquipment()
{
	for (int i = 0; i < player_data1.UnequipedEquipment->num; i++)
	{
		//if(!once_shown)
			//this->addChild((Gun*)(player_data1.UnequipedEquipment->arr[i]));
		//auto tmp = Gun::create();
		//tmp = (Gun*)player_data1.UnequipedEquipment->arr[i];
		//this->addChild((Gun*)tmp);
		//((Gun*)tmp)->setPosition(player_data1.slotPoint[i]);
		switch (((Equipment*)player_data1.UnequipedEquipment->arr[i])->type)
		{
			case GUN:
				((Gun*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(player_data1.slotPoint[i]);//this->slotPoint[i]
				break;
			case KNIFE:
				((Knife*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(player_data1.slotPoint[i]);//this->slotPoint[i]
				break;
		}
	}
}
/*隐藏背包里的装备*/
void Package::HideEquipment()
{
	for (int i = 0; i < player_data1.UnequipedEquipment->num; i++)
	{
		//this->removeChild((Gun*)(player_data1.UnequipedEquipment->arr[i]));
		//auto tmp = Gun::create();
		//tmp = (Gun*)player_data1.UnequipedEquipment->arr[i];
		//this->addChild((Gun*)tmp);
		//((Gun*)tmp)->setPosition(player_data1.slotPoint[i]);
		switch (((Equipment*)player_data1.UnequipedEquipment->arr[i])->type)
		{
			case GUN:
				((Gun*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);//this->slotPoint[i]
				break;
			case KNIFE:
				((Knife*)(player_data1.UnequipedEquipment->arr[i]))->setPosition(10000, 10000);//this->slotPoint[i]
				break;
		}
		
	}
}


/*------------------松开鼠标时执行，自动加入到附近的棋子上--------------------
void Package::EquipMove(Equipment* equip)
{
	Point a(0, 0);
	Point chessPosition = equip->getPosition();
	float distance = 9999999;
	if (equip->OwnerChess == NULL || equip->OwnerChess->Die())    //如果已经有攻击目标则不搜寻
	{
		for (int i = 0; i < pArray->num; i++)
		{
			auto temp = pArray->arr[i];
			Point atemp = ((Chess*)temp)->getPosition();
			float distanceTemp = sqrt((atemp.x - chessPosition.x) * (atemp.x - chessPosition.x) +
				(atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //求距离
			if (distanceTemp < distance && distanceTemp>0) //确定攻击目标
			{
				distance = distanceTemp;
				a = atemp;
				equip->OwnerChess = (Chess*)temp;
			}
		}
	}
	else
	{
		distance = sqrt((equip->OwnerChess->getPosition().x - chessPosition.x)
			* (equip->OwnerChess->getPosition().x - chessPosition.x) +
			(equip->OwnerChess->getPosition().y - chessPosition.y)
			* (equip->OwnerChess->getPosition().y - chessPosition.y));
	}
	/*移动，以1e-2为单位移动
	
	if (equip->OwnerChess == NULL)  //无攻击目标则结束
	{
		return;
	}
	if (distance >= equip->SearchDistance && !equip->OwnerChess->Die())    //距离大于射程且目标没死则移动
	{
		chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * (float)1e-2);
		chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * (float)1e-2);  //将新位置传入类中
		//除以模长乘上固定参数即可改进
	}
}*/
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
	auto open_package = Menu::create(OpenPackage, NULL);  //���ذ�ť
	open_package->setPosition(Vec2::ZERO);
	this->addChild(open_package, 1);

	/*--------------------Button ClosePackage----------------*/
	ClosePackage->setPosition(10000, 10000);
	auto close_package = Menu::create(ClosePackage, NULL);  //���ذ�ť
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

/*��ʼ���������*/
void Package::SlotPositionInit()
{
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
		{
			player_data1.packageSlot[i][j].x = 1300 + j * 50;  //��Ϲ�裬��ʱ�����Ҿ���λ��
			player_data1.packageSlot[i][j].y = 610 - i * 70;
			player_data1.packageSlot[i][j].is_occupied = 0;  //��ʼ��Ϊδռ��״̬
			player_data1.packageSlot[i][j].is_equiped = -1;		   //��ʼ��Ϊ-1
			player_data1.slotPoint[k].set(player_data1.packageSlot[i][j].x, player_data1.packageSlot[i][j].y); //����Point����ϵ��Ӧλ��
			k++;
		}
}

/*��װ������*/
void Package::openPackage(cocos2d::Ref* pSender)
{
	//AudioEngine::stop(audioID);
	(this->package_image)->setPosition(1298, 397);   //��ʾ�������
	(this->OpenPackage)->setPosition(10000, 10000);
	(this->ClosePackage)->setPosition(800, 500);

	ShowEquipment();                                 //��ʾ�����е�װ��

	(player_data1.package_is_opened) = 1;
}
/*�ر�װ������*/
void Package::closePackage(cocos2d::Ref* pSender)
{
	//AudioEngine::stop(audioID);
	(this->package_image)->setPosition(10000, 10000);   //�Ƴ��������
	(this->OpenPackage)->setPosition(800, 500);
	(this->ClosePackage)->setPosition(10000, 10000);

	HideEquipment();                                 //��ʾ�����е�װ��

	(player_data1.package_is_opened) = 0;
}

/*��ȡװ������������*/
void Package::ObtainEquipment(int game_turn)
{
	if (game_turn % 2 == 0)
	{
		int a = rand() % 10;
		if (a <= 7)                         //��һ����������
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

/*��ʾ�����е�װ��*/
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
/*���ر������װ��*/
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


/*------------------�ɿ����ʱִ�У��Զ����뵽������������--------------------
void Package::EquipMove(Equipment* equip)
{
	Point a(0, 0);
	Point chessPosition = equip->getPosition();
	float distance = 9999999;
	if (equip->OwnerChess == NULL || equip->OwnerChess->Die())    //����Ѿ��й���Ŀ������Ѱ
	{
		for (int i = 0; i < pArray->num; i++)
		{
			auto temp = pArray->arr[i];
			Point atemp = ((Chess*)temp)->getPosition();
			float distanceTemp = sqrt((atemp.x - chessPosition.x) * (atemp.x - chessPosition.x) +
				(atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //�����
			if (distanceTemp < distance && distanceTemp>0) //ȷ������Ŀ��
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
	/*�ƶ�����1e-2Ϊ��λ�ƶ�
	
	if (equip->OwnerChess == NULL)  //�޹���Ŀ�������
	{
		return;
	}
	if (distance >= equip->SearchDistance && !equip->OwnerChess->Die())    //������������Ŀ��û�����ƶ�
	{
		chess->setPosition(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * (float)1e-2);
		chess->set(chess->getPosition() + (chess->AttackTarget->getPosition() - chess->getPosition()) * (float)1e-2);  //����λ�ô�������
		//����ģ�����Ϲ̶��������ɸĽ�
	}
}*/
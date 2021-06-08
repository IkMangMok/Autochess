#pragma once
#include "cocos2d.h"
#include "Equipment/Gun.h"
#include "Equipment/Knife.h"


USING_NS_CC;

struct PackageSlot {
	int x;
	int y;
	bool is_occupied;   // 0 -- not occupied; 1 -- occupied
	int is_equiped;   // -1 -- not occupied yet; 0 -- not equipped ; 1 -- equipped
};

class PlayerData
{
public:
	//PlayerData();
	//~PlayerData();
private:
	ccArray* UnequipedEquipment = ccArrayNew(1200);       //未装备数组
	int occupied_slot = 0;
	bool package_is_opened = 0;

	PackageSlot packageSlot[3][4] = {};                   //二维数组存放12个插槽的int坐标 
	Point slotPoint[12] = {};                       //储存12个插槽的Point类坐标

	friend class Package;
	friend class scene1;
};

extern PlayerData player_data1;

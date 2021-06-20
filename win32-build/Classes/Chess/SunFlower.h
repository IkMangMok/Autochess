#pragma once
#include"Chess.h"
#include"Data/GameData.h"
#include"Data/PlayerData.h"
class SunFlower :public Chess {
public:
	SunFlower();
	static SunFlower* createChess();
	CREATE_FUNC(SunFlower);
	void Skill();
	
};

class upgrade_SunFlower :public SunFlower {
public:
	upgrade_SunFlower();
	static upgrade_SunFlower* createChess();
	CREATE_FUNC(upgrade_SunFlower);
};

class _3star_SunFlower :public SunFlower {
public:
	_3star_SunFlower();
	static _3star_SunFlower* createChess();
	CREATE_FUNC(_3star_SunFlower);
};
#pragma once
#include"Chess.h"

class WalNut :public Chess {
public:
	WalNut();
	static WalNut* createChess();
	void Skill();
	void update(float dt);
	RoundTimer* SkillTime = RoundTimer::create(5);
	CREATE_FUNC(WalNut);
	bool flag = 0;
};

class upgrade_WalNut :public WalNut {
public:
	upgrade_WalNut();
	static upgrade_WalNut* createChess();
	CREATE_FUNC(upgrade_WalNut);
};
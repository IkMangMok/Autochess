#pragma once
#include"Chess.h"

class WalNut :public Chess {
public:
	WalNut();
	static WalNut* createChess();
	void Skill();
	void update(float dt);
	
	CREATE_FUNC(WalNut);
};

class upgrade_WalNut :public WalNut {
public:
	upgrade_WalNut();
	static upgrade_WalNut* createChess();
	CREATE_FUNC(upgrade_WalNut);
};

class _3star_WalNut :public WalNut {
public:
	_3star_WalNut();
	static _3star_WalNut* createChess();
	CREATE_FUNC(_3star_WalNut);
};
#pragma once
#include"Chess.h"

class WalNut :public Chess {
public:
	WalNut();
	static WalNut* createChess();
	CREATE_FUNC(WalNut);
};

class upgrade_WalNut :public WalNut {
public:
	upgrade_WalNut();
	static upgrade_WalNut* createChess();
	CREATE_FUNC(upgrade_WalNut);
};
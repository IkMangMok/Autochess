#pragma once
#include"Chess.h"

class WalNut :public Chess {
public:
	WalNut();
	static WalNut* createChess();
	CREATE_FUNC(WalNut);
};
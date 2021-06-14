#pragma once
#include"Chess.h"

class CornShooter :public Chess {
public:
	CornShooter();
	static CornShooter* createChess();
	CREATE_FUNC(CornShooter);
};

class upgrade_CornShooter :public CornShooter {
public:
	upgrade_CornShooter();
	static upgrade_CornShooter* createChess();
	CREATE_FUNC(upgrade_CornShooter);
};
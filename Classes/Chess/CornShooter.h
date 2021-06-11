#pragma once
#include"Chess.h"

class CornShooter :public Chess {
public:
	CornShooter();
	static CornShooter* createChess();
	CREATE_FUNC(CornShooter);
};
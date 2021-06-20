#pragma once
#include"Chess.h"

class CornShooter :public Chess {
public:
	CornShooter();
	static CornShooter* createChess();
	CREATE_FUNC(CornShooter);
<<<<<<< HEAD
	void update(float dt);
	void Skill();
=======
>>>>>>> lx
};

class upgrade_CornShooter :public CornShooter {
public:
	upgrade_CornShooter();
	static upgrade_CornShooter* createChess();
	CREATE_FUNC(upgrade_CornShooter);
};
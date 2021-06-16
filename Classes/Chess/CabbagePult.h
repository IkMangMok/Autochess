#pragma once
#include"Chess.h"

class CabbagePult :public Chess {
public:
	CabbagePult();
	static CabbagePult* createChess();
	void Skill();
	CREATE_FUNC(CabbagePult);
	void update(float dt);
};

class upgrade_CabbagePult :public CabbagePult {
public:
	upgrade_CabbagePult();
	static upgrade_CabbagePult* createChess();
	CREATE_FUNC(upgrade_CabbagePult);
};
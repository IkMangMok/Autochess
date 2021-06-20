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
<<<<<<< HEAD
=======
};

class _3star_CabbagePult :public CabbagePult {
public:
	_3star_CabbagePult();
	static _3star_CabbagePult* createChess();
	CREATE_FUNC(_3star_CabbagePult);
>>>>>>> lx
};
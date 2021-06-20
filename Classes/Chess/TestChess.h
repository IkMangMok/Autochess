#pragma once
#include"Chess1.h"

class TestChess :public Chess {

	
public:
	TestChess();
	static TestChess* createChess(string picture_name, float x, float y);
};
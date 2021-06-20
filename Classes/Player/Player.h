#pragma once
#include "cocos2d.h"
#include "string"
#include"Data/PlayerData.h"

using namespace cocos2d;
using namespace std;

class Player : public Layer {
private:
	
public:
	static Player* createPlayer(string& name);
	virtual bool init();
	void update(float dt);
	void BuyExp(cocos2d::Ref* pSender);
	Label* Coins = Label::createWithTTF("Coins:" + to_string(player1data.Gold), "fonts/Marker Felt.ttf", 24);  //临时记录
	Label* Grades = Label::createWithTTF("Grades: " + to_string(player1data.Grade), "fonts/Marker Felt.ttf", 24);  //临时记录
	Label* Exp = Label::createWithTTF("Exp->Grade++" + to_string(player1data.ToNextGrade), "fonts/Marker Felt.ttf", 24);
	Label* Hyut = Label::createWithTTF("Hp : " + to_string(player1data.HealthValue), "fonts/Marker Felt.ttf", 24);

	Label* p2Coins = Label::createWithTTF("Coins:" + to_string(player1data.Gold), "fonts/Marker Felt.ttf", 24);  //临时记录
	Label* p2Grades = Label::createWithTTF("Grades: " + to_string(player1data.Grade), "fonts/Marker Felt.ttf", 24);  //临时记录
	Label* p2Exp = Label::createWithTTF("Exp->Grade++" + to_string(player1data.ToNextGrade), "fonts/Marker Felt.ttf", 24);
	Label* p2Hyut = Label::createWithTTF("Hp : " + to_string(player1data.HealthValue), "fonts/Marker Felt.ttf", 24);
	CREATE_FUNC(Player);
};

#pragma once
#include "cocos2d.h"
#include "string"
#include"Data/PlayerData.h"

using namespace cocos2d;
using namespace std;
<<<<<<< HEAD

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
=======

class Player : public Layer {
private:
	
public:
	static Player* createPlayer(string& name);
	virtual bool init();
	void update(float dt);
	void BuyExp(cocos2d::Ref* pSender);
	Label* Coins = Label::createWithTTF("Coins: "+to_string(player1data.Gold), "fonts/Marker Felt.ttf", 22);  //临时记录
	Label* Grades = Label::createWithTTF("Lv. " + to_string(player1data.Grade), "fonts/Marker Felt.ttf", 22);  //临时记录
	Label* Hyut = Label::createWithTTF(to_string(player1data.HealthValue), "fonts/Marker Felt.ttf", 24);
	ProgressTimer* player1Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	Sprite* player1BloodFrame = Sprite::create("BloodFrame.jpg");

	ProgressTimer* player1Experience = ProgressTimer::create(Sprite::create("greenblood.png"));
	Sprite* player1expFrame = Sprite::create("BloodFrame.jpg");

	Label* Coins2 = Label::createWithTTF("Coins: " + to_string(player2data.Gold), "fonts/Marker Felt.ttf", 22);  //临时记录
	Label* Grades2 = Label::createWithTTF("Lv. " + to_string(player2data.Grade), "fonts/Marker Felt.ttf", 22);  //临时记录
	Label* Hyut2 = Label::createWithTTF(to_string(player2data.HealthValue), "fonts/Marker Felt.ttf", 24);
	ProgressTimer* player2Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	Sprite* player2BloodFrame = Sprite::create("BloodFrame.jpg");

	ProgressTimer* player2Experience = ProgressTimer::create(Sprite::create("greenblood.png"));
	Sprite* player2expFrame = Sprite::create("BloodFrame.jpg");

>>>>>>> lx
	CREATE_FUNC(Player);
};

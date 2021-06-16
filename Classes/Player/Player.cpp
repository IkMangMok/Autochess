#include"player.h"

Player* Player::createPlayer()
{
	auto player = Player::create();
	player->retain();
	player->Coins->retain();
	player->Grades->retain();
	player->autorelease();
	return player;
}

bool Player::init()
{
	this->setPosition(0, 0);
	MenuItemImage* BuyExp = MenuItemImage::create("BuyExp.png", "BuyExp.png",
		CC_CALLBACK_1(Player::BuyExp, this));
	Menu* buyexp = Menu::create(BuyExp, NULL);
	buyexp->setPosition(-590, -250);
	buyexp->setScale(0.2);
	this->addChild(buyexp, 1);
	Coins->setPosition(50, 300);
	Grades->setPosition(60, 250);
	Exp->setPosition(60, 200);
	Hyut->setPosition(60, 350);
	this->addChild(Coins);
	this->addChild(Grades);
	this->addChild(Exp);
	this->addChild(Hyut);
	return true;
}

void Player::BuyExp(cocos2d::Ref* pSender)
{
	if (player1data.Gold >= 4)
	{
		player1data.Gold -= 4;
		player1data.ExperienceValue += 4;
		player1data.CountExperience();
	}
	else
	{
		auto label = Label::createWithTTF("Not enough money!", "fonts/Marker Felt.ttf", 36);
		this->addChild(label);
		label->setTextColor(Color4B::WHITE);
		label->setPosition(800, 400);
		auto move = FadeOut::create(2.0f);
		label->runAction(move);
	}
}

void Player::update(float dt)
{
	Coins->setString("Coins:" + to_string(player1data.Gold));  //ÁÙÊ±¼ÇÂ¼
	Grades->setString("Grades: " + to_string(player1data.Grade));
	Exp->setString("ExpForGrade++: " + to_string(player1data.ToNextGrade));
	Hyut->setString("Hp : " + to_string(player1data.HealthValue));
}
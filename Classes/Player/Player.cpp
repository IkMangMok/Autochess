#include"player.h"

const Point myBloodPos = Point(250, 510);
const Point myExpPos = Point(250, 490);

const Point enemyBloodPos = Point(250, 710);
const Point enemyExpPos = Point(250, 690);

Player* Player::createPlayer(string& name)
{
	auto player = Player::create();	

	/*-----------------------玩家1头像（静态，不需要update）-----------------------*/
	string picture1 = "head1.jpg";
	auto icon1 = Sprite::create(picture1);
	icon1->setPosition(Point(50, 500));
	player->addChild(icon1);

	/*-----------------------玩家1昵称（静态，不需要update）-----------------------*/
	auto nameLabel1 = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 24);
	nameLabel1->setPosition(Point(80 + nameLabel1->getContentSize().width, 540));
	player->addChild(nameLabel1, 1);

	/*-----------------------玩家2头像（静态，不需要update）-----------------------*/
	string picture2 = "head2.png";
	auto icon2 = Sprite::create(picture2);
	icon2->setPosition(Point(50, 700));
	player->addChild(icon2);

	/*-----------------------玩家2昵称（静态，不需要update）-----------------------*/
	auto nameLabel2 = Label::createWithTTF("Computer", "fonts/Marker Felt.ttf", 24);
	nameLabel2->setPosition(Point(60 + nameLabel2->getContentSize().width, 740));
	player->addChild(nameLabel2, 1);

	player->retain();
	player->Coins->retain();
	player->Grades->retain();
	player->autorelease();
	return player;
}

bool Player::init()
{
	/*------------------------买经验------------------*/
	MenuItemImage* BuyExp = MenuItemImage::create("BuyExp.png", "BuyExp.png",
		CC_CALLBACK_1(Player::BuyExp, this));
	Menu* buyexp = Menu::create(BuyExp, nullptr);
	buyexp->setPosition(-590, -250);
	buyexp->setScale(0.2);
	this->addChild(buyexp, 1);

	/*------------------------Player1(己方)------------------------*/
	/*------------------------血条------------------*/
	this->setPosition(0, 0);
	player1BloodFrame->setPosition(myBloodPos);
	this->addChild(player1BloodFrame);

	player1Blood->setBarChangeRate(Point(1, 0));
	player1Blood->setType(ProgressTimer::Type::BAR);
	player1Blood->setMidpoint(Point(0, 1));
	player1Blood->setPosition(myBloodPos);
	player1Blood->setPercentage(player1data.HealthValue);
	this->addChild(player1Blood);

	Hyut->setPosition(myBloodPos.x + 180, myBloodPos.y);
	this->addChild(Hyut);

	/*------------------------等级------------------*/
	player1expFrame->setPosition(myExpPos);
	this->addChild(player1expFrame);

	player1Experience->setBarChangeRate(Point(1, 0));
	player1Experience->setType(ProgressTimer::Type::BAR);
	player1Experience->setMidpoint(Point(0, 1));
	player1Experience->setPosition(myExpPos);
	player1Experience->setPercentage(player1data.ExperienceValue * 100 / player1data.NextNeedExp);
	this->addChild(player1Experience);

	Grades->setPosition(myExpPos.x + 190, myExpPos.y);
	this->addChild(Grades);

	/*------------------------金钱------------------*/
	Coins->setPosition(75, 450);
	this->addChild(Coins);

	
	/*------------------------Player2(对方)------------------------*/
	/*------------------------血条------------------*/
	this->setPosition(0, 0);
	player2BloodFrame->setPosition(enemyBloodPos);
	this->addChild(player2BloodFrame);

	player2Blood->setBarChangeRate(Point(1, 0));
	player2Blood->setType(ProgressTimer::Type::BAR);
	player2Blood->setMidpoint(Point(0, 1));
	player2Blood->setPosition(enemyBloodPos);
	player2Blood->setPercentage(player2data.HealthValue);
	this->addChild(player2Blood);

	Hyut2->setPosition(enemyBloodPos.x + 180, enemyBloodPos.y);
	this->addChild(Hyut2);

	/*------------------------等级------------------*/
	player2expFrame->setPosition(enemyExpPos);
	this->addChild(player2expFrame);

	player2Experience->setBarChangeRate(Point(1, 0));
	player2Experience->setType(ProgressTimer::Type::BAR);
	player2Experience->setMidpoint(Point(0, 1));
	player2Experience->setPosition(enemyExpPos);
	player2Experience->setPercentage(player2data.ExperienceValue * 100 / player2data.NextNeedExp);
	this->addChild(player2Experience);

	Grades2->setPosition(enemyExpPos.x + 190, enemyExpPos.y);
	this->addChild(Grades2);

	/*------------------------金钱------------------*/
	Coins2->setPosition(75, 650);
	this->addChild(Coins2);

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
	/*------------------------Player1(己方)------------------------*/
	
	/*------------------------血条------------------*/
	player1Blood->setPercentage(player1data.HealthValue);
	player1Blood->setTag(player1data.HealthValue);
	Hyut->setString(to_string(player1data.HealthValue));

	/*------------------------金钱------------------*/
	Coins->setString("Coins: " + to_string(player1data.Gold)); //临时记录

	player1Experience->setPercentage(player1data.ExperienceValue * 100 / player1data.NextNeedExp);
	Grades->setString("Lv. " + to_string(player1data.Grade));

	
	/*------------------------Player1(对方)------------------------*/

	/*------------------------血条------------------*/
	player2Blood->setPercentage(player2data.HealthValue);
	player2Blood->setTag(player2data.HealthValue);
	Hyut2->setString(to_string(player2data.HealthValue));

	/*------------------------金钱------------------*/
	Coins2->setString("Coins: " + to_string(player2data.Gold)); //临时记录

	player2Experience->setPercentage(player2data.ExperienceValue * 100 / player2data.NextNeedExp);
	Grades2->setString("Lv. " + to_string(player2data.Grade));
	
}


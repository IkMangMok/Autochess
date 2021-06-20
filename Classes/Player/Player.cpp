#include"player.h"



Player* Player::createPlayer(string& name)
{
	auto player = Player::create();	

	/*-----------------------玩家头像（静态，不需要update）-----------------------*/
	string picture = "duck.jpg";
	auto icon = Sprite::create(picture);
	icon->setPosition(Point(50, 400));
	player->addChild(icon);

	/*-----------------------玩家昵称（静态，不需要update）-----------------------*/
	auto nameLabel = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 24);
	nameLabel->setPosition(Point(80 + nameLabel->getContentSize().width, 425));
	player->addChild(nameLabel, 1);

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
	Menu* buyexp = Menu::create(BuyExp, nullptr);
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
	

	p2Coins->setPosition(50, 600);
	p2Grades->setPosition(60, 550);
	p2Exp->setPosition(60, 500);
	p2Hyut->setPosition(60, 650);
	

	this->addChild(p2Coins);
	this->addChild(p2Grades);
	this->addChild(p2Exp);
	this->addChild(p2Hyut);
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
	Coins->setString("Coins:" + to_string(player1data.Gold));  //临时记录
	Grades->setString("Grades: " + to_string(player1data.Grade));
	Exp->setString("ExpForGrade++: " + to_string(player1data.ToNextGrade));
	showBlood(Point(250, 400), this, player2data.HealthValue);


	//Hyut->setString("Hp : " + to_string(player1data.HealthValue));

	p2Coins->setString("Coins:" + to_string(player2data.Gold));  //临时记录
	p2Grades->setString("Grades: " + to_string(player2data.Grade));
	p2Exp->setString("ExpForGrade++: " + to_string(player2data.ToNextGrade));
	p2Hyut->setString("Hp : " + to_string(player2data.HealthValue));
}





/*-----------------------玩家血条-----------------------*/
void Player::showBlood(Point setPos, Player* player, int health)
{
	auto bloodFrame = Sprite::create("BloodFrame.jpg");
	bloodFrame->setPosition(setPos);
	ProgressTimer* Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	Blood->setBarChangeRate(Point(1, 0));
	Blood->setType(ProgressTimer::Type::BAR);
	Blood->setMidpoint(Point(0, 1));
	Blood->setPosition(setPos);
	Blood->setPercentage(health);
	this->addChild(Blood);
	auto lifeLabel = Label::createWithTTF("100", "fonts/Marker Felt.ttf", 20);

	lifeLabel->setPosition(Point(setPos.x, setPos.y - 25));
	this->addChild(lifeLabel, 1);
}
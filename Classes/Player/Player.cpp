#include"player.h"

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in AutoChessScene.cpp\n");
}

Player* Player::createPlayer(string& name)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	/*-----------------------玩家头像-----------------------*/
	auto player = Player::create();
	string picture = "duck.jpg";
	auto icon = Sprite::create(picture);
	icon->setPosition(Point(icon->getContentSize().width - 20, origin.y + visibleSize.height - icon->getContentSize().height));
	player->addChild(icon);

	/*-----------------------玩家昵称-----------------------*/
	auto nameLabel = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 24);
	if (nameLabel == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		nameLabel->setPosition(Vec2(origin.x + nameLabel->getContentSize().width + 40, origin.y + visibleSize.height - nameLabel->getContentSize().height));
		nameLabel->setPosition(Vec2(origin.x + nameLabel->getContentSize().width + 40, origin.y + visibleSize.height - nameLabel->getContentSize().height));
		player->addChild(nameLabel, 1);
	}

	/*-----------------------玩家血条-----------------------*/
	auto bloodFrame = Sprite::create("BloodFrame.jpg");
	bloodFrame->setPosition(Point(230, visibleSize.height - 60));
	player->addChild(bloodFrame);
	ProgressTimer* Blood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	Blood->setBarChangeRate(Point(1, 0));
	Blood->setType(ProgressTimer::Type::BAR);
	Blood->setMidpoint(Point(0, 1));
	Blood->setPosition(Point(230, visibleSize.height - 60));
	Blood->setPercentage(100);
	player->addChild(Blood);
	auto lifeLabel = Label::createWithTTF("100", "fonts/Marker Felt.ttf", 20);
	if (lifeLabel == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		lifeLabel->setPosition(Point(230, visibleSize.height - 85));
		player->addChild(lifeLabel, 1);
	}

	player->retain();
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
	Hyut->setString("Hp : " + to_string(player1data.HealthValue));

	p2Coins->setString("Coins:" + to_string(player2data.Gold));  //临时记录
	p2Grades->setString("Grades: " + to_string(player2data.Grade));
	p2Exp->setString("ExpForGrade++: " + to_string(player2data.ToNextGrade));
	p2Hyut->setString("Hp : " + to_string(player2data.HealthValue));
}
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

	/*-----------------------Íæ¼ÒÍ·Ïñ-----------------------*/
	auto player = Player::create();
	string picture = "duck.jpg";
	auto icon = Sprite::create(picture);   
	icon->setPosition(Point(icon->getContentSize().width - 20, origin.y + visibleSize.height - icon->getContentSize().height));
	player->addChild(icon);

	/*-----------------------Íæ¼ÒêÇ³Æ-----------------------*/
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

	/*-----------------------Íæ¼ÒÑªÌõ-----------------------*/
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
	return player;
}

bool Player::init()
{
	return true;
}


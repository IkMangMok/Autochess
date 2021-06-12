#include"player.h"

Player* Player::createPlayer()
{
	auto player = Player::create();
	player->retain();
	return player;
}

bool Player::init()
{
	if (!Layer::create())
		return false;

	ShowData();

	return true;
}

/*show player's Name,Blood,Level,Exp,Coin*/
void Player::ShowData()
{
	/*Names*/
	auto Name1 = Label::createWithTTF("Player1", "fonts/Marker Felt.ttf", 24);
	Name1->setPosition(100, 100);
	this->addChild(Name1);

	auto Name2 = Label::createWithTTF("Player2", "fonts/Marker Felt.ttf", 24);
	Name1->setPosition(100, 200);
	this->addChild(Name2);

	/*Level*/
	auto Level1 = Label::createWithTTF("Level", "fonts/Marker Felt.ttf", 24);
	Level1->setPosition(100, 100);
	this->addChild(Level1);
	char* c_level1 = new char[3];
	sprintf(c_level1, "%d", player1data.Level);
	Level1->setString(c_level1);

	auto Level2 = Label::createWithTTF("Level", "fonts/Marker Felt.ttf", 24);
	Level2->setPosition(100, 200);
	this->addChild(Level2);
	char* c_level2 = new char[3];
	sprintf(c_level2, "%d", player2data.Level);
	Level2->setString(c_level2);

	/*Exp*/
	auto Exp1 = Label::createWithTTF("Exp", "fonts/Marker Felt.ttf", 24);
	Exp1->setPosition(100, 100);
	this->addChild(Exp1);
	char* c_exp1 = new char[7];
	sprintf(c_exp1, "%d/%d", player1data.ExpInLevel,player1data.ExpInLevelMax);
	Exp1->setString(c_exp1);

	auto Exp2 = Label::createWithTTF("Exp", "fonts/Marker Felt.ttf", 24);
	Exp2->setPosition(100, 100);
	this->addChild(Exp2);
	char* c_exp2 = new char[7];
	sprintf(c_exp2, "%d/%d", player2data.ExpInLevel, player2data.ExpInLevelMax);
	Exp2->setString(c_exp2);

	/*Gold*/
	auto Gold1 = Label::createWithTTF("Gold", "fonts/Marker Felt.ttf", 24);
	Gold1->setPosition(100, 100);
	this->addChild(Gold1);
	char* c_gold1 = new char[3];
	sprintf(c_gold1, "%d", player1data.Gold);
	Gold1->setString(c_gold1);

	auto Gold2 = Label::createWithTTF("Gold", "fonts/Marker Felt.ttf", 24);
	Gold2->setPosition(100, 100);
	this->addChild(Gold2);
	char* c_gold2 = new char[3];
	sprintf(c_gold2, "%d", player2data.Gold);
	Gold2->setString(c_gold2);

	/*Blood*/
	auto Blood1 = Label::createWithTTF("Blood", "fonts/Marker Felt.ttf", 24);
	Blood1->setPosition(100, 100);
	this->addChild(Blood1);
	char* c_blood1 = new char[3];
	sprintf(c_blood1, "%d", player1data.HealthValue);
	Blood1->setString(c_blood1);

	auto Blood2 = Label::createWithTTF("Blood", "fonts/Marker Felt.ttf", 24);
	Blood2->setPosition(100, 100);
	this->addChild(Blood2);
	char* c_blood2 = new char[3];
	sprintf(c_blood2, "%d", player1data.HealthValue);
	Blood2->setString(c_blood2);
}
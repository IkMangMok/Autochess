#include"player.h"

Player* Player::createPlayer()
{
	auto player = Player::create();
	player->retain();
	return player;
}

bool Player::init()
{
	return true;
}
#include "GameData.h"

/*定义全局变量 global_data*/
GameData global_data;
ccArray* pArray = ccArrayNew(1000);
Player* player1;




void GameData::GameStartInit()
{
	/*player_coin = 0;
	player_level = 1;
	player_exe = 0;
	player_blood = 100;*/
	game_turn = 0;

}

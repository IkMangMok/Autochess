#include "GameData.h"

/*定义全局变量 global_data*/
GameData* global_data = GameData::createGameData();


GameData* GameData::createGameData()
{
	return GameData::create();
}

bool GameData::init()
{
	if (!Scene::init())
		return false;
	return true;
}

void GameData::GameStartInit()
{
	/*player_coin = 0;
	player_level = 1;
	player_exe = 0;
	player_blood = 100;*/
	game_turn = 0;
}


ccArray* FightArray = ccArrayNew(100);    //打斗中的棋子数组
ccArray* ComputerArray = ccArrayNew(100); //电脑棋子数组
int chesspile[ChessNumber];          //牌堆
const int PB[9][5] = { {100,0,0,0,0},{80,20,0,0,0},{75,20,5,0,0},{60,25,15,0,0},{50,30,20,0,0},
					  {40,35,25,0,0},{30,40,30,0,0},{20,35,45,0,0},{10,40,50,0,0} };         //商店概率

const chessInfo chess_store[OriginalChess] =
{ {walnut,"walnut.png",1} ,{pealauncher,"pealauncher.png",2},{mushroom,"mushroom.png",2}
	,{sunflower,"sunflower.png",1},{cactus,"cactus.png",3 },{cherrybomb,"cherrybomb.png",3},
	{cornshooter,"cornshooter.png",2},{cabbagepult,"cabbagepult.png",2} };      //初步的棋子商店，后续可加上卡池功能

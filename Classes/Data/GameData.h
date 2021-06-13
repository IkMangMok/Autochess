#pragma once
#include "cocos2d.h"
#include "Map/MapLayer.h"
USING_NS_CC;


//地图：64*36
#define ChessNumber 20
#define OriginalChess 8
class GameData: Scene
{
public:
	static GameData* createGameData();
	CREATE_FUNC(GameData);
	virtual bool init();
	/* 获取当前游戏数据的函数 */
	/* functions to obtain the game data */
	/*int GetPlayerCoin() { return player_coin; }
	int GetPlayerLevel() { return player_level; }
	int GetPlayerExe() { return player_exe; }
	int GetPlayerBlood() { return player_blood; }*/
	int GetGameTurn() { return game_turn; }

    //记录棋子的数组
//private:

	/* 初始化所有基本信息 */
	void GameStartInit();

	/* 当前局内全局信息 */
	/* global data */

	
	/*int player_coin;
	int player_level;
	int player_exe;
	int player_blood;*/
	int game_turn = 0;

	/* 修改当前游戏数据的函数 */
	/*void ChangePlayerCoin(int benefit) { player_coin += benefit; }
	void ChangePlayerExe(int benefit) { player_exe += benefit; }   //后续可以把level的改变逻辑放进这个函数
	void ChangePlayerBlood(int hurt) { player_blood -= hurt; }  */   //注意伤害是正数
	void ChangeGameTurn() { game_turn++; }

};

struct chessInfo
{
	int address = 0;
	std::string picture_name = "";
	int money = 0;
	bool buy = false;
};
/*外部声明全局变量 global_data*/
extern GameData* global_data;



extern ccArray* ComputerArray; //电脑棋子数组
extern int chesspile[ChessNumber];
extern const int PB[9][5];
extern chessInfo Used[5];
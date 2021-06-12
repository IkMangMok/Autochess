#include "AI_Player.h"

void AI_Player::aiAction()
{

}

/*to spend money*/
/* 逻辑全靠编 */
int AI_Player::aiJudgeToUseMoney()
{
	/*step 1: 检查棋子是否可以升星*/

	//买得起，买

	/*step 2: 检查FightArray棋子是否达到上限（若否，买）*/

	//买得起，买

	/*step 3: 检查与敌方Level差值是否过大*/

	/*step 4: 检查Gold是否靠近利息点*/
	/* 以平均费率2来考虑 */
	/* 利息点：10（2）、24（5）、44（10） */

	/*step 5: 买高费棋子*/


	if (player2data.Gold > 10)	//也可以按照回合与当前经济状况，判断是否递归
		aiJudgeToUseMoney();//递归一波
	return 0;
}


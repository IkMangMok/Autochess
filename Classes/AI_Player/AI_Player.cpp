#include "AI_Player.h"

void AI_Player::aiAction()
{

}

/*to spend money*/
/* �߼�ȫ���� */
int AI_Player::aiJudgeToUseMoney()
{
	/*step 1: ��������Ƿ��������*/

	//�������

	/*step 2: ���FightArray�����Ƿ�ﵽ���ޣ�������*/

	//�������

	/*step 3: �����з�Level��ֵ�Ƿ����*/

	/*step 4: ���Gold�Ƿ񿿽���Ϣ��*/
	/* ��ƽ������2������ */
	/* ��Ϣ�㣺10��2����24��5����44��10�� */

	/*step 5: ��߷�����*/


	if (player2data.Gold > 10)	//Ҳ���԰��ջغ��뵱ǰ����״�����ж��Ƿ�ݹ�
		aiJudgeToUseMoney();//�ݹ�һ��
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	int player, opponent;// 1 Rock 2 Scissors 3 Paper
	int result;// 0 loose 1 draw 2 win
	int resultArr[3] = { 0, };
	char* RockScissorsPaper[3] = { "����", "����", "��" };
	char* LooseDrawWin[3] = { "����� �����ϴ�!", "�����ϴ�!", "����� �̰���ϴ�!" };

	srand(time(NULL));

	while (1)
	{
		printf("������ 1, ������ 2, ���� 3: ");
		scanf("%d", &player);

		opponent = (rand() % 3) + 1;

		if (player == 1)
		{
			if (opponent == 2)
			{
				result = 2;
			}
			else if (opponent == 1)
			{
				result = 1;
			}
			else
			{
				result = 0;

				break;
			}
		}
		else if (player == 2)
		{
			if (opponent == 3)
			{
				result = 2;
			}
			else if (opponent == 2)
			{
				result = 1;
			}
			else
			{
				result = 0;

				break;
			}
		}
		else if (player == 3)
		{
			if (opponent == 1)
			{
				result = 2;
			}
			else if (opponent == 3)
			{
				result = 1;
			}
			else
			{
				result = 0;

				break;
			}
		}
		else
		{
			continue;
		}

		resultArr[result]++;

		printf("����� %s ����, ��ǻ�ʹ� %s ����, %s \n", RockScissorsPaper[player - 1], RockScissorsPaper[opponent - 1], LooseDrawWin[result]);
	}

	printf("����� %s ����, ��ǻ�ʹ� %s ����, %s \n\n", RockScissorsPaper[player - 1], RockScissorsPaper[opponent - 1], LooseDrawWin[result]);

	printf("������ ���: %d��, %d�� \n", resultArr[2], resultArr[1]);
}
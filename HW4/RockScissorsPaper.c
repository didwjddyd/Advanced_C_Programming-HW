#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	int player, opponent;// 1 Rock 2 Scissors 3 Paper
	int result;// 0 loose 1 draw 2 win
	int resultArr[3] = { 0, };
	char* RockScissorsPaper[3] = { "바위", "가위", "보" };
	char* LooseDrawWin[3] = { "당신이 졌습니다!", "비겼습니다!", "당신이 이겼습니다!" };

	srand(time(NULL));

	while (1)
	{
		printf("바위는 1, 가위는 2, 보는 3: ");
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

		printf("당신은 %s 선택, 컴퓨터는 %s 선택, %s \n", RockScissorsPaper[player - 1], RockScissorsPaper[opponent - 1], LooseDrawWin[result]);
	}

	printf("당신은 %s 선택, 컴퓨터는 %s 선택, %s \n\n", RockScissorsPaper[player - 1], RockScissorsPaper[opponent - 1], LooseDrawWin[result]);

	printf("게임의 결과: %d승, %d무 \n", resultArr[2], resultArr[1]);
}
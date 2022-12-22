#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	int pArr[3] = { 0, };
	int oArr[3] = { 0, };
	int i, j;
	int strike = 0, ball = 0, count = 0;

	printf("Start Game! \n");

	srand(time(NULL));

	for (i = 0; i < 3; i++)
	{
		oArr[i] = rand() % 10;
	}

	printf("%d %d %d \n\n", oArr[0], oArr[1], oArr[2]);

	while (1)
	{
		strike = 0;
		ball = 0;

		count++;

		printf("3개의 숫자 선택: ");
		scanf("%d %d %d", &pArr[0], &pArr[1], &pArr[2]);

		for (i = 0; i < 3; i++)
		{
			if (oArr[i] == pArr[i])
			{
				strike++;
			}
			else
			{
				if (i == 0)
				{
					if (oArr[i] == pArr[1])
					{
						ball++;
					}

					if (oArr[i] == pArr[2])
					{
						ball++;
					}
				}
				else if (i == 1)
				{
					if (oArr[i] == pArr[0])
					{
						ball++;
					}

					if (oArr[i] == pArr[2])
					{
						ball++;
					}
				}
				else
				{
					if (oArr[i] == pArr[0])
					{
						ball++;
					}

					if (oArr[i] == pArr[1])
					{
						ball++;
					}
				}
			}
		}

		if (strike == 3)
		{
			break;
		}

		printf("%d번째 도전 결과: %d strike, %d ball!! \n", count, strike, ball);
	}

	printf("%d번째 도전 결과: %d strike, %d ball!! \n\n", count, strike, ball);

	printf("Game Over!");
}
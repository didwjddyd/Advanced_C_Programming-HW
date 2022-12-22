#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void SnailArr(int snail[][10], int len)
{
	int i, count = 0;
	int x = -1, y = 0, dir = 1;

	while (1)
	{
		for (i = 0; i < len; i++)
		{
			x += dir;

			snail[y][x] = ++count;
		}

		if (--len < 0)
		{
			break;
		}

		for (i = 0; i < len; i++)
		{
			y += dir;

			snail[y][x] = ++count;
		}

		if (dir == 1)
		{
			dir = -1;
		}
		else
		{
			dir = 1;
		}
	}
}

int main()
{
	int snail[10][10] = { 0, };
	int i, j, num;

	printf("숫자 입력: ");
	scanf("%d", &num);

	SnailArr(snail, num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%2d ", snail[i][j]);
		}

		printf("\n");
	}

	return 0;
}
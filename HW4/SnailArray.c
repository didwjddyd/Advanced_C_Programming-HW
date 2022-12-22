#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void SnailArray(int arr[][10], int len)
{
	int column = 0, row = -1;
	int i, dir = 1, count = 0;

	while (1)
	{
		for (i = 0; i < len; i++)
		{
			row += dir;

			count++;

			arr[column][row] = count;
		}

		len--;

		if (len < 0)
		{
			break;
		}

		for (i = 0; i < len; i++)
		{
			column += dir;

			count++;

			arr[column][row] = count;
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
	int arr[10][10] = { 0, };
	int num, i, j;

	printf("숫자를 입력하시오: ");
	scanf("%d", &num);

	SnailArray(arr, num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%2d ", arr[i][j]);
		}

		printf("\n");
	}

	return 0;
}
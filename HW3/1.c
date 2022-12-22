#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int arr[4][4][4] = { 0, };
	int i, j, r, count = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr[0][i][j] = ++count;
		}
	}

	for (r = 1; r < 4; r++)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				arr[r][i][j] = arr[r - 1][3 - j][i];
			}
		}
	}

	for (r = 0; r < 4; r++)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				printf("%2d ", arr[r][i][j]);
			}

			printf("\n");
		}

		printf("\n");
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[3][9] = { 0, };
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 9; j++)
		{
			arr[i][j] = (i + 5) * (j + 1);
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%d*%d=%2d ", i + 5, j + 1, arr[i][j]);
		}

		printf("\n");
	}

	return 0;
}
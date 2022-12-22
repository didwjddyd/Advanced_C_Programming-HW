#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arrA[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arrB[5][2] = { 0, };

	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			arrB[j][i] = arrA[i][j];
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%2d ", arrB[i][j]);
		}

		printf("\n");
	}

	return 0;

}
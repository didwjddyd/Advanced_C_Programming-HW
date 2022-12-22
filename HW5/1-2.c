#include <stdio.h>

int main()
{
	int arrA[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arrB[2][5] = { 0, };
	int i, j, indexEven = -1, indexOdd = -1;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (arrA[i][j] % 2 == 1)
			{
				indexOdd++;

				arrB[0][indexOdd] = arrA[i][j];
			}
			else
			{
				indexEven++;

				arrB[1][indexEven] = arrA[i][j];
			}
		}
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%2d ", arrB[i][j]);
		}

		printf("\n");
	}

	return 0;
}
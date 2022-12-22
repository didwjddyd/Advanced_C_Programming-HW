#include <stdio.h>

int main()
{
	int arr[3][27] = { 0, };
	int i, j, dan = 7, count;

	for (i = 0; i < 3; i++)
	{
		count = 1;

		for (j = 0; j < 27; j += 3)
		{
			arr[i][j] = dan;
			arr[i][j + 1] = count;
			arr[i][j + 2] = dan * count;

			count++;
		}

		dan++;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 27; j += 3)
		{
			printf("%d*%d=%2d  ", arr[i][j], arr[i][j + 1], arr[i][j + 2]);
		}

		printf("\n");
	}

	return 0;
}
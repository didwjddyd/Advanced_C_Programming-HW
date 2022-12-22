#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;

	int arr[2][3] =
	{
	{ 10, 20, 30 },
	{ 40, 50, 60 }
	};

	int* Parr1[3] = { &num1, &num2, &num3 };
	int(*Parr2)[3] = arr;

	int i, j;

	printf("포인터 배열 \n");

	for (i = 0; i < 3; i++)
	{
		printf("%p \n", Parr1[i]);
	}

	SwapFunc(Parr1);

	printf("포인터 연산 후 \n");

	for (i = 0; i < 3; i++)
	{
		printf("%p \n", Parr1[i] + 4);
	}

	printf("\n\n");

	printf("배열 포인터 \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%p \n", Parr2[i][j]);
		}
	}

	printf("포인터 연산 후 \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%p \n", Parr2[i][j] + 4);
		}
	}

	return 0;
}
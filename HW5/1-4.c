#include <stdio.h>

int main()
{

	int arrA[4][4];
	int(*parrA)[4];
	int i, j;

	double arrB[4][4] = { 0, };
	double(*parrB)[sizeof(double)];

	parrA = arrA;

	printf("float \n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%p \n", parrA[i] + j);
		}

		printf("\n");
	}

	printf("\n\n");
	printf("double \n");

	parrB = arrB;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%p ", parrB[i] + j);
		}

		printf("\n");
	}

	return 0;
}
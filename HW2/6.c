#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void BubbleSort(int ary[], int len)
{
	int i, j;
	int temp;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < (len - i) - 1; j++)
		{
			if (ary[j] < ary[j + 1])
			{
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[7] = { 3, 2, 1, 4, 7, 5, 6 };
	int i, len = sizeof(arr) / sizeof(int);

	BubbleSort(arr, len);
	for (i = 0; i < 7; i++)
	{
		printf("%d", arr[i]);
	}

	printf("\n");

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = &arr[4];
	int i, total = 0;

	for (i = 0; i < 5; i++)
	{
		total += *(ptr--);
	}

	printf("%d", total);

	return 0;
}
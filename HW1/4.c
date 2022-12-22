#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	int* fptr = arr;
	int* bptr = &arr[5];
	int i, temp;

	for (i = 0; i < 3; i++)
	{
		temp = *fptr;
		*fptr = *bptr;
		*bptr = temp;

		fptr++;
		bptr--;
	}

	for (i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
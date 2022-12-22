#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[10] = { 0, };
	int* fptr = &arr[0];
	int* bptr = &arr[9];
	int i;

	for (i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			*(bptr--) = i;
		}
		else
		{
			*(fptr++) = i;
		}
	}

	fptr = &arr[0];
	bptr = &arr[9];

	printf("È¦¼ö Ãâ·Â: ");

	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(fptr++));
	}

	printf("\n");
	printf("Â¦¼ö Ãâ·Â: ");

	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(bptr--));
	}

	printf("\n");

	return 0;
}
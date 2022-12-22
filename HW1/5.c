#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[5] = { 45, 77, 89, 38, 93 };
	int* ptr;
	int i = 0, sum = 0, size;

	ptr = &arr[0];

	size = sizeof(arr) / sizeof(int);

	while (i < size)
	{
		sum += *(ptr + i);

		i++;
	}

	printf("sum = %d \n", sum);
	printf("average = %g \n", (double)sum / size);

	return 0;
}
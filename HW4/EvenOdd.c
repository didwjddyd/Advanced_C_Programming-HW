#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int arr[10] = { 0, };
	int i;

	printf("�� 10���� ���� �Է� \n");

	for (i = 0; i < 10; i++)
	{
		printf("�Է�: ");
		scanf("%d", &arr[i]);
	}

	printf("Ȧ�� ���: ");

	for (i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 1)
		{
			printf("%d ", arr[i]);
		}
	}

	printf("\n");

	printf("¦�� ���: ");

	for (i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}
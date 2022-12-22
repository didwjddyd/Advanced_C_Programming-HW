#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

SwapFunc(int* p1, int* p2, int* p3)
{
	int temp;

	temp = *p1;

	*p1 = *p2;

	*p2 = *p3;

	*p3 = temp;
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;

	int* pnum1 = &num1;
	int* pnum2 = &num2;
	int* pnum3 = &num3;

	printf("-SwapFunc 사용 전 \n");
	printf("num1 %d, num2 %d, num3 %d \n", num1, num2, num3);
	printf("*pnum1 %d, *pnum2 %d, *pnum3 %d \n\n", *pnum1, *pnum2, *pnum3);

	SwapFunc(pnum1, pnum2, pnum3);

	printf("-SwapFunc 사용 후 \n");
	printf("num1 %d, num2 %d, num3 %d \n", num1, num2, num3);
	printf("*pnum1 %d, *pnum2 %d, *pnum3 %d \n", *pnum1, *pnum2, *pnum3);
}
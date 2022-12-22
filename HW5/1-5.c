#include <stdio.h>

void Swap(int* p1, int* p2)
{
	int temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	int n1 = 100, n2 = 200, n3 = 300;

	printf("- Swap 사용 전 \n");
	printf("n1 %d, n2 %d, n3 %d \n\n", n1, n2, n3);

	Swap(&n1, &n3);
	Swap(&n1, &n2);

	printf("- Swap 사용 후 \n");
	printf("n1 %d, n2 %d, n3 %d \n", n1, n2, n3);

	return 0;
}
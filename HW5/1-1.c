#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_DATA 10

void get_data(int* p);
void print_data(int* p);
void print_SumAvg(int* p);
int get_Min(int *p);
int get_Max(int* p);


int main()
{
	int data[10];
	srand((unsigned)time(NULL));
	get_data(data);
	print_data(data);
	print_SumAvg(data);
	printf("최고 점수 : %d \n", get_Max(data));
	printf("최저 점수 : %d \n", get_Min(data));

	return 0;
}

void get_data(int* p)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		*(p + i) = (rand() % 100) + 1;
	}
}

void print_data(int* p)
{
	int i;

	printf("( ");

	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}

	printf(") \n");
}

void print_SumAvg(int* p)
{
	int i, sum = 0;
	float avg;

	for (i = 0; i < 10; i++)
	{
		sum += *(p + i);
	}

	avg = (float)sum / N_DATA;

	printf("총점 : %d점, 평균 : %f점 \n", sum, avg);
}

int get_Min(int *p)
{
	int i, min;

	min = *(p + 0);

	for (i = 1; i < 10; i++)
	{
		if (min > *(p + i))
		{
			min = *(p + i);
		}
	}

	return min;
}

int get_Max(int* p)
{
	int i, max;

	max = *(p + 0);

	for (i = 1; i < 10; i++)
	{
		if (max < *(p + i))
		{
			max = *(p + i);
		}
	}

	return max;
}
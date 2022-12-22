#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N_DATA 10

void get_data(int* p);
void print_data(int* p);
double get_mean(int* p);
double get_std_dev(int* p, double mean);

int main()
{
	int data[10];
	double mean;
	srand((unsigned)time(NULL));
	get_data(data);
	print_data(data);
	mean = get_mean(data);
	printf("평균값은  %.2lf\n", mean);
	printf("표준편차값은 %.2lf\n", get_std_dev(data, mean));
	return 0;
}

void get_data(int* p)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		p[i] = rand(100) + 1;
	}
}

void print_data(int* p)
{
	int i;

	printf("(");

	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}

	printf(") \n");
}

double get_mean(int* p)
{
	int i;

	double sum = 0;

	for (i = 0; i < 10; i++)
	{
		sum += p[i];
	}

	sum /= (double)10;

	return sum;
}

double get_std_dev(int* p, double mean)
{
	int i;

	double sum = 0;

	for (i = 0; i < 10; i++)
	{
		sum += (p[i] - mean) * (p[i] - mean);
	}

	return sqrt(sum / N_DATA);
}
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int u_choice, c_choice, result;
	int record[3] = { 0, };
	char* choice_str[3] = { "����", "����", "��" };
	char* result_str[3] = { "��", "��", "��" };

	while (1)
	{
		printf("���� 1, ���� 2, �� 3 : ");
		scanf("%d", &u_choice);

		srand(time(NULL));

		c_choice = (rand() % 3) + 1;

		if (u_choice == 1)
		{
			if (c_choice == 2)
			{
				result = 2;
			}
			else if (c_choice == 1)
			{
				result = 1;
			}
			else
			{
				result = 0;
				break;
			}
		}
		else if (u_choice == 2)
		{
			if (c_choice == 3)
			{
				result = 2;
			}
			else if (c_choice == 2)
			{
				result = 1;
			}
			else
			{
				result = 0;
				break;
			}
		}
		else if (u_choice == 3)
		{
			if (c_choice == 1)
			{
				result = 2;
			}
			else if (c_choice == 3)
			{
				result = 1;
			}
			else
			{
				result = 0;
				break;
			}
		}
		else
		{
			continue;
		}

		record[result]++;

		printf("��� : %s, ��ǻ�� : %s, ��� : %s \n\n", choice_str[u_choice - 1], choice_str[c_choice - 1], result_str[result]);
	}

	record[result]++;

	printf("��� : %s, ��ǻ�� : %s, ��� : %s \n\n", choice_str[u_choice - 1], choice_str[c_choice - 1], result_str[result]);

	printf("��� : %d�� %d�� %d�� \n", record[2], record[1], record[0]);

	return 0;
}
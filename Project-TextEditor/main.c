#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <windows.h>
#include <conio.h>
#include "linkedlist.h"

#define GETKBD 224
#define UP 72
#define DOWN 80

//전역변수
static char* dir = "\directory";
char sentence[10000];
char realFileName[10000];

COORD Pos;

//함수
void Menu();
void Search();
void Edit(char fileName[], char dir[]);
void PrintLine(LL* lineList);
void CursorMove(int x, int y);
void KBDMove(int x, int y);
void Write(LL* lineList, int lineNum);
void ClearReadBuffer();
void Save(LL* lineList);

int main()
{
	Menu();

	return 0;
}

void Menu()
{
	char command[1000] = { 0, };
	char fileName[1000];
	char mode; //p(particular) 이름만 같은 특정 파일  a(all) 이름이 포함된 파일 전부  e(exactly) 확장자까지 정확하게

	int count = 0;

	printf("************************************ \n");
	printf("\n\n\n\n\n");
	printf("TEXT EDITOR\n");
	printf("\n\n\n\n\n");
	printf("************************************ \n");
	printf("\n\n");
	printf("Please Enter a Keyword >>");
	scanf("%s", command);

	if (!strcmp(command, "search"))
	{
		ClearReadBuffer();

		printf("Please Enter Filname and Mode >>");
		scanf("%s %c", fileName, &mode);

		ClearReadBuffer();

		system("cls");

		Search(fileName, dir, mode);

		system("cls");

		Menu();
	}
	else if (!strcmp(command, "edit"))
	{
		ClearReadBuffer();

		printf("Please Enter a Filename >>");
		scanf("%s", fileName);

		ClearReadBuffer();

		system("cls");

		Edit(fileName, dir);

		system("cls");

		Menu();
	}
	else if (!strcmp(command, "exit"))
	{
		return;
	}
	else
	{
		printf("\n");
		printf("Error: Wrong Command \n\n");

		printf("PRESS ENTER...");

		getchar();

		ClearReadBuffer();

		system("cls");

		Menu();
	}
}

void Search(char fileName[], char dir[], char mode)
{
	struct _finddata_t fd;

	long handle;

	int result = 1;

	if (mode == 'e')
	{
		sprintf(realFileName, "%s/%s", dir, fileName);
	}
	else if (mode == 'p')
	{
		sprintf(realFileName, "%s/%s.*", dir, fileName);
	}
	else if (mode == 'a')
	{
		sprintf(realFileName, "%s/*%s*", dir, fileName);
	}
	else
	{
		printf("************************************ \n");
		printf("\n\n\n\n\n");
		printf("Wrong Mode \n");
		printf("\n\n\n\n\n");
		printf("************************************ \n");
		printf("\n\n");

		printf("PRESS ENTER...");

		getchar();

		return;
	}

	handle = _findfirst(realFileName, &fd);

	if (handle == -1)
	{
		printf("************************************ \n");
		printf("\n\n\n\n\n");
		printf("No Result \n");
		printf("\n\n\n\n\n");
		printf("************************************ \n");
		printf("\n\n");

		printf("PRESS ENTER...");

		getchar();

		return;
	}

	printf("************************************ \n");

	while (result != -1)
	{
		printf("\n");
		printf("%s \n", fd.name);

		result = _findnext(handle, &fd);
	}

	printf("\n");
	printf("************************************ \n");
	printf("\n\n");

	printf("PRESS ENTER...");

	getchar();

	return;
}

void Edit(char fileName[], char dir[])
{
	LL* lineList = CreateList();

	FILE* file;

	NODE line;

	int count = 0;
	
	sprintf(realFileName, "%s/%s", dir, fileName);

	file = fopen(realFileName, "rt");

	if (file == NULL)
	{
		printf("************************************ \n");
		printf("\n\n\n\n\n");
		printf("Please Put Correct Filename \n");
		printf("\n\n\n\n\n");
		printf("************************************ \n");
		printf("\n\n");

		printf("PRESS ENTER...");

		getchar();

		return;
	}

	while (fgets(line.str, sizeof(sentence), file) != EOF)
	{
		if (feof(file) != 0)
		{
			break;
		}

		AddElement(lineList, count, line);

		count++;
	}

	fclose(file);

	PrintLine(lineList);

	CursorMove(4, 0);

	while (1)
	{
		int keyboardInput = _getch();

		if (keyboardInput == GETKBD)
		{
			keyboardInput = _getch();

			switch (keyboardInput)
			{
			case UP:
				
				if (Pos.Y > 0)
				{
					KBDMove(0, 1);
				}

				break;

			case DOWN:

				if (Pos.Y < lineList->entireLine - 1)
				{
					KBDMove(0, -1);
				}

				break;
			}
		}
		else if (keyboardInput == ':')
		{
			char* command;

			command = (char*)malloc(sizeof(char) * 10);

			CursorMove(0, lineList->entireLine + 2);

			for (int i = 0; i < strlen("Wrong Command"); i++)
			{
				printf(" ");
			}

			CursorMove(0, lineList->entireLine + 2);
			
			printf(":");
			scanf("%s", command);

			if (!strncmp(command, "write", sizeof("write")))
			{
				int lineNum;

				printf("LINE: ");
				scanf("%d", &lineNum);

				if (lineNum < 1)
				{
					CursorMove(0, lineList->entireLine + 3);

					for (int i = 0; i < strlen("LINE: ") + 1; i++)
					{
						printf(" ");
					}

					CursorMove(0, lineList->entireLine + 2);

					printf("Wrong Command");

					CursorMove(4, 0);
				}
				else
				{
					ClearReadBuffer();

					system("cls");

					Write(lineList, lineNum);

					system("cls");

					PrintLine(lineList);

					CursorMove(4, 0);
				}
			}
			else if (!strncmp(command, "save", sizeof("save")))
			{
				Save(lineList);

				break;
			}
			else if (!strncmp(command, "exit", sizeof("exit")))
			{
				char YorN;

				ClearReadBuffer();

				printf("\n\n");

				for (int i = 0; i < strlen("Are you eixt without saving? (y/n)"); i++)
				{
					printf(" ");
				}

				CursorMove(0, lineList->entireLine + 4);

				printf("Are you eixt without saving? (y/n)");

				scanf("%c", &YorN);

				if (YorN == 'y')
				{
					DeleteLL(lineList);

					break;
				}
				else if(YorN == 'n')
				{
					CursorMove(0, lineList->entireLine + 4);

					for (int i = 0; i < strlen("Are you eixt without saving? (y/n)") + 1; i++)
					{
						printf(" ");
					}

					CursorMove(4, 0);
				}
				else
				{
					printf("\n");

					printf("Wrong Command\n");
					printf("Go to Edit Page\n");

					CursorMove(0, lineList->entireLine + 4);

					for (int i = 0; i < strlen("Are you eixt without saving? (y/n)") + 1; i++)
					{
						printf(" ");
					}

					CursorMove(4, 0);
				}

			}
			else
			{
				CursorMove(0, lineList->entireLine + 2);

				printf("Wrong Command");

				CursorMove(4, 0);
			}
		}
	}
}

void PrintLine(LL* lineList)
{
	for (int i = 0; i < lineList->entireLine; i++)
	{
		printf("%3d  %s", i + 1, GetNode(lineList, i)->str);
	}
}

void Write(LL* lineList, int lineNum)
{
	NODE newLine;

	printf(">> %s", GetNode(lineList, lineNum - 1)->str);
	printf("\n\n");
	printf(">> ");
	fgets(newLine.str, sizeof(sentence), stdin);

	if (lineNum > 1)
	{
		AddElement(lineList, lineNum, newLine);

		RemoveElement(lineList, lineNum - 1);
	}
	else
	{
		NODE* pNode = &(lineList->header);

		pNode = pNode->next;

		strcpy(pNode->str, newLine.str);
	}
}

void KBDMove(int x, int y)
{
	Pos.X += x;
	Pos.Y -= y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorMove(int x, int y)
{
	Pos.X = x;
	Pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void ClearReadBuffer()
{
	while (getchar() != '\n');
}

void Save(LL* lineList)
{
	FILE* file = fopen(realFileName, "wt");

	for (int i = 0; i < lineList->entireLine; i++)
	{
		fputs(GetNode(lineList, i)->str, file);
	}

	DeleteLL(lineList);

	fclose(file);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LL* CreateList()
{
	LL* list = NULL;

	list = (LL*)malloc(sizeof(LL));

	if (list != NULL)
	{
		memset(list, 0, sizeof(LL));
	}

	return list;
}

void AddElement(LL* pList, int position, NODE element)
{
	NODE* preNode = NULL;
	NODE* newNode = NULL;

	newNode = (NODE*)malloc(sizeof(NODE));

	if (newNode != NULL)
	{
		if (position >= 0 && position <= pList->entireLine)
		{
			*newNode = element;

			newNode->next = NULL;

			preNode = &(pList->header);

			for (int i = 0; i < position; i++)
			{
				preNode = preNode->next;
			}

			newNode->next = preNode->next;
			preNode->next = newNode;

			pList->entireLine++;
		}
	}
}

void RemoveElement(LL* pList, int position)
{
	NODE* pNode = NULL;
	NODE* pDelNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position < GetLength(pList))
		{
			pNode = &(pList->header);

			for (int i = 0; i < position; i++)
			{
				pNode = pNode->next;
			}

			pDelNode = pNode->next;
			pNode->next = pDelNode->next;

			free(pDelNode);

			pList->entireLine--;
		}
	}
}

NODE* GetNode(LL* pList, int position)
{
	NODE* pReturn = NULL;
	NODE* pNode = NULL;

	pNode = &(pList->header);

	for (int i = 0; i <= position; i++)
	{
		pNode = pNode->next;
	}

	pReturn = pNode;

	return pReturn;
}

int GetLength(LL* pList)
{
	int ret = 0;

	if (pList != NULL)
	{
		ret = pList->entireLine;
	}

	return ret;
}

void DeleteLL(LL* pList)
{
	if (pList != NULL)
	{
		ClearLL(pList);

		free(pList);
	}
}

void ClearLL(LL* pList)
{
	if (pList != NULL)
	{
		if (pList->entireLine > 0)
		{
			RemoveElement(pList, 0);
		}
	}
}
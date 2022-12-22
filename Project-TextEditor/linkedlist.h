#pragma once

#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#endif


typedef struct LinkedListTypte
{
	int entireLine;

	struct ListNodes* header;
}LL;

typedef struct ListNodes
{
	char str[100000];

	struct ListNodes* next;
}NODE;

LL* CreateList();
void AddElement(LL* pList, int position, NODE element);
void RemoveElement(LL* pList, int position);
NODE* GetNode(LL* pList, int position);

int GetLength(LL* pList);
void DeleteLL(LL* pList);
void ClearLL(LL* pList);

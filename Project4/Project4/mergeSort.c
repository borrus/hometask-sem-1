#include "list.h"
#include "utilities.h"

#include <stdlib.h>
#include <string.h>

List* mergeLists(List const* list1, List const* list2, char const* method)
{
	List* mergedList = listInitialize();

	Node* temp1 = list1->root;
	Node* temp2 = list2->root;

	while (temp1 != NULL && temp2 != NULL)
	{
		bool condition = false;

		if (!strcmp("name", method))
		{
			condition = firstBiggerThanSecond(temp1->name, temp2->name);
		}
		else
		{
			condition = firstBiggerThanSecond(temp1->number, temp2->number);
		}

		if (condition)
		{
			listPushBack(mergedList, temp2->name, temp2->number);
			temp2 = temp2->next;
		}
		else
		{
			listPushBack(mergedList, temp1->name, temp1->number);
			temp1 = temp1->next;
		}
	}

	while (temp1 != NULL)
	{
		listPushBack(mergedList, temp1->name, temp1->number);
		temp1 = temp1->next;
	}

	while (temp2 != NULL)
	{
		listPushBack(mergedList, temp2->name, temp2->number);
		temp2 = temp2->next;
	}

	return mergedList;
}

void mergeSort(List* list, char const* method)
{
	if (list->size > 2)
	{
		List* list1 = listInitialize();
		list1->root = list->root;
		list1->size = list->size / 2;

		List* list2 = listInitialize();
		list2->size = list->size - list1->size;
		Node* temp = list->root;
		for (int i = 0; i < list1->size - 1; ++i)
		{
			temp = temp->next;
		}
		list2->root = temp->next;
		temp->next = NULL;

		mergeSort(list1, method);
		mergeSort(list2, method);

		List* mergedList = mergeLists(list1, list2, method);
		listFree(list1);
		listFree(list2);

		list->root = mergedList->root;

		return;
	}

	if (list->size == 2)
	{
		bool condition = false;

		if (!strcmp("name", method))
		{
			condition = firstBiggerThanSecond(list->root->name, list->root->next->name);
		}
		else
		{
			condition = firstBiggerThanSecond(list->root->number, list->root->next->number);
		}

		if (condition)
		{
			Node* n1 = list->root;
			Node* n2 = list->root->next;
			list->root = n2;
			list->root->next = n1;
			list->root->next->next = NULL;
		}

		return;
	}
}
#include "list.h"
#include "utilities.h"
#include <stdlib.h>
#include <string.h>

List* mergeLists(List const* list1, List const* list2, char const* method)
{
	List* mergedList = listInitialize();

	Node* temp1 = getListRoot(list1);
	Node* temp2 = getListRoot(list2);

	while (temp1 != NULL && temp2 != NULL)
	{
		bool condition = false;

		if (!strcmp("name", method))
		{
			condition = firstBiggerThanSecond(getNodeName(temp1), getNodeName(temp2));
		}
		else
		{
			condition = firstBiggerThanSecond(getNodeNumber(temp1), getNodeNumber(temp2));
		}

		if (condition)
		{
			listPushBack(mergedList, getNodeName(temp2), getNodeNumber(temp2));
			temp2 = getNextNode(temp2);
		}
		else
		{
			listPushBack(mergedList, getNodeName(temp1), getNodeNumber(temp1));
			temp1 = getNextNode(temp1);
		}
	}

	while (temp1 != NULL)
	{
		listPushBack(mergedList, getNodeName(temp1), getNodeNumber(temp1));
		temp1 =  getNextNode(temp1);
	}

	while (temp2 != NULL)
	{
		listPushBack(mergedList, getNodeName(temp2),  getNodeNumber(temp2));
		temp2 =  getNodeName(temp2);
	}

	return mergedList;
}

void mergeSort(List* list, char const* method)
{
	if (getListSize(list) > 2)
	{
		List* list1 = listInitialize();
		setListRoot(list1, getListRoot(list));
		setSize(list1, getListSize(list) / 2);

		List* list2 = listInitialize();
		setSize(list2, getListSize(list) - getListSize(list1));
		Node* temp = getListRoot(list);

		for (int i = 0; i < getListSize(list1) - 1; ++i)
		{
			temp = getNextNode(temp);
		}

		setListRoot(list2, getNextNode(temp));
		setNextNode(temp, NULL);
		mergeSort(list1, method);
		mergeSort(list2, method);

		List* mergedList = mergeLists(list1, list2, method);
		listFree(list1);
		listFree(list2);

		setListRoot(list, getListRoot(mergedList));

		return;
	}

	if (getListSize(list) == 2)
	{
		bool condition = false;

		if (!strcmp("name", method))
		{
			condition = firstBiggerThanSecond(getNodeName(getListRoot(list)), getNodeName(getNextNode(getListRoot(list))));
		}
		else
		{
			condition = firstBiggerThanSecond(getNodeNumber(getListRoot(list)), getNodeNumber(getNextNode(getListRoot(list))));
		}

		if (condition)
		{
			Node* n1 = getListRoot(list);
			Node* n2 = getNextNode(getListRoot(list));
			setListRoot(list, n2);
			setNextNode(getListRoot(list), n1);
			setNextNode(getNextNode(getListRoot(list)), NULL);
		}

		return;
	}
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* next;
	int value;
	int size;
} Node;

typedef struct List
{
	Node* root;
	int size;
} List;

bool valueExist(struct List const* list, int const value);

Node* getNodeByValue(List const* list, int const value);

Node* initNode(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->value = value;
	newNode->size = 1;

	return newNode;
}

List* initializeList()
{
	List* newList = (List*)malloc(sizeof(List));
	newList->root = NULL;
	newList->size = 0;

	return newList;
}

Node* getLast(Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	while (head->next != NULL)
	{
		head = head->next;
	}

	return head;
}

void push(List* list, int value)
{

	if (list->root == NULL)
	{
		list->root = initNode(value);
		++list->size;

		return;
	}

	if (valueExist(list, value))
	{
		++getNodeByValue(list, value)->size;
		return;
	}


	++list->size;
	Node* last = getLast(list->root);
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->next = NULL;
	last->next = temp;
	temp->size = 1;
}

bool valueExistNode(struct Node const* node, int const value)
{
	if (node == NULL)
	{
		return false;
	}

	if (node->value == value)
	{
		return true;
	}

	return valueExistNode(node->next, value);
}

bool valueExist(struct List const* list, int const value)
{
	if (list == NULL)
	{
		return false;
	}

	return valueExistNode(list->root, value);
}

Node* getNodeByValueNode(Node const* node, int const value)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (node->value == value)
	{
		return node;
	}

	return getNodeByValueNode(node->next, value);
}

Node* getNodeByValue(List const* list, int const value)
{
	if (list->root == NULL)
	{
		return NULL;
	}

	return getNodeByValueNode(list->root, value);
}

Node* getNodePreviousByValueNode(Node const* node, int const value)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (node->next->value == value && node->next != NULL)
	{
		return node;
	}

	return getNodeByValueNode(node->next, value);
}

Node* getNodePreviousByValue(List const* list, int const value)
{
	if (list == NULL)
	{
		return NULL;
	}

	return getNodePreviousByValueNode(list->root, value);
}

void deleteNodeByValue(struct List* list, int const value)
{
	if (list->root == NULL)
	{
		return;
	}

	if (!valueExist(list, value))
	{
		printf("value does not exist");
		return;
	}

	if (list->root->value == value)
	{
		if (list->root->next != NULL)
		{
			Node* newRoot = list->root->next;
			free(list->root);
			list->root = newRoot;

			return;
		}

		free(list->root);
		return;
	}

	if (getNodeByValue(list, value)->next != NULL)
	{
		Node* n1 = getNodePreviousByValue(list, value);
		Node* n2 = getNodeByValue(list, value)->next;

		free(getNodeByValue(list, value));
		n1->next = n2;

		return;
	}

	free(getNodeByValue(list, value));

}

int listLen(List* list)
{
	List* newList = list;
	int counter;

	while (newList->root != 0)
	{
		++counter;
		newList->root = newList->root->next;
	}

	return counter;
}

Node* sortList(Node* head)
{
	Node* tempNode = NULL;
	Node* tempHead = head;
	Node* tempNext = head->next;

	while (tempNext != NULL) {

		if (tempHead->value > tempNext->value) {
			tempNode = tempHead;
			tempHead = tempNext;
			tempNode->next = tempNode->next->next;
			tempHead->next = tempNode;
			tempNext = tempHead->next;

		}
		else {
			tempHead = tempHead->next;
			tempNext = tempNext->next;

		}
	}
	return head;
}

int main()
{
	int value = 0;
	List* list = initializeList();
	printf("input number: ");
	scanf("%d", &value);

	if (value != 0)
	{
		push(list, value);
	}

	while (value != 0)
	{
		printf("input number: ");
		scanf("%d", &value);
		push(list, value);
	}

	if (list->root == NULL)
	{
		printf("0");
		return;
	}

	Node* newNode = sortList(list->root);

	while (newNode != NULL)
	{
		printf("number: %d     size: %d\n", newNode->value, newNode->size);
		newNode = newNode->next;
	}
}
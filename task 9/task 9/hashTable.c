#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"

typedef struct Node
{
	struct Node* next;
	char* value;
} Node;

typedef struct List
{
	Node* root;
	int size;
} List;

Node* initializeNode(char* value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		return NULL;
	}

	newNode->next = NULL;
	newNode->value = value;

	return newNode;
}

List* initializeList()
{
	List* newList = (List*)malloc(sizeof(List));

	if (newList == NULL)
	{
		return NULL;
	}

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

char* copyStr(char const* from)
{
	char* result = (char*)malloc((strlen(from) + 1) * sizeof(char));

	if (result == NULL)
	{
		return NULL;
	}

	strcpy(result, from);

	return result;
}

void addFront(List* list, char* value)
{
	++list->size;

	if (list->root == NULL)
	{
		list->root = initializeNode(value);

		return;
	}

	Node* last = getLast(list->root);
	Node* temp = (Node*)malloc(sizeof(Node));

	if (temp == NULL)
	{
		return NULL;
	}

	temp->value = copyStr(value);
	temp->next = NULL;
	last->next = temp;
}

void printList(List* list)
{
	if (list->root == NULL)
	{
		printf("List is empty\n");
	}

	Node* temp = list->root;

	if (temp == NULL)
	{
		return NULL;
	}

	while (temp->next != NULL)
	{
		printf("%s ", temp->value);
		temp = temp->next;
	}

	printf("%s\n", temp->value);
}

typedef struct Table
{
	struct List** array;
	int size;
	int maxSize;
} Table;

int hash(char* value, int hashSize)
{
	int result = 0;

	for (int i = 0; value[i] != '\0'; ++i)
	{
		result = (result + value[i]) % hashSize;
	}

	return result;
}

Table* initTable()
{
	Table* table = (Table*)malloc(sizeof(Table));

	if (table == NULL)
	{
		return NULL;
	}

	table->maxSize = 100;
	table->size = 0;
	table->array = (struct List**)malloc(sizeof(struct List*) * table->maxSize);

	if (table->array == NULL)
	{
		return NULL;
	}
	
	for (int i = 0; i < table->maxSize; ++i)
	{
		table->array[i] = initializeList();
	}

	return table;
}

void resize(Table* table)
{
	struct List** array = (struct List**)malloc(sizeof(struct List*) * 2 * table->maxSize);

	if (array == NULL)
	{
		return NULL;
	}

	for (int i = table->maxSize; i < table->maxSize * 2; ++i)
	{
		table->array[i] = NULL;
	}

	for (int i = 0; i < table->maxSize * 2; ++i)
	{
		array[i] = table->array[i];
	}

	table->maxSize *= 2;
	table->array = array;

	free(array);
}

void addElementToTable(char* element, Table* table)
{
	if (table->size == table->maxSize)
	{
		resize(table);
	}

	++table->size;

	int currentHash = hash(element, table->maxSize);
	addFront(table->array[currentHash], element);
}

void printTable(Table* table)
{
	for (int i = 0; i < table->maxSize; ++i)
	{
		if (table->array[i]->root != NULL)
		{
			printf("hash = %d\n", i);
			printList(table->array[i]);
		}
	}
	printf("max size of the list is: ");
	printf("%d\n", table->size);
}

void printFrequencies(Table* table)
{
	for (int i = 0; i < table->maxSize; ++i)
	{
		if (table->array[i]->root != NULL)
		{
			printf("word = %s; frequency = %d\n", table->array[i]->root->value, table->array[i]->size);
		}
	}
}

int fillFactor(Table* table)
{
	if (table == NULL)
	{
		return;
	}

	int fillF = (table->size * 100 / table->maxSize);
	printf("fill factor: ");
	printf("%d ", fillF);
	printf("procents \n");

	return fillF;
}

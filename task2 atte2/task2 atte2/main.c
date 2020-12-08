#include <stdio.h>
#include <stdlib.h>

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
	newNode->next = NULL;
	newNode->value = value;

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

void push(List* list, char* value)
{
	if (list->root == NULL)
	{
		list->root = initializeNode(value);

		return;
	}

	Node* last = getLast(list->root);
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->next = NULL;
	last->next = temp;
}


void readFromFile(const char* fileName, List* list)
{
	FILE* file = fopen(fileName, "r");

	if (file == NULL)
	{
		printf("file is not found");
		return;
	}

	int current = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &current);

		if (fgetc(file) == ' ')
		{
			push(list, current);
			current = 0;
		}
	}

	fclose(file);
}

int main()
{
	List* list = initializeList();
	readFromFile("text.txt", list);

	List* newList = initializeList();

	while (list->root->next != NULL)
	{
		char* temp = list->root->value;

		while (temp != list->root->next->value)
		{
			list->root->next = list->root->next->next;
		}

		if (list->root->value != temp)
		{
			push(newList, temp);
		}
	}

	return newList;
}
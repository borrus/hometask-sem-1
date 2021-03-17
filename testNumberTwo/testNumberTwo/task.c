#include "task.h"
#include <stdio.h>

typedef struct Node
{
	struct Node* next;
	int value;
} Node;

Node* init()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	return node;
}

void push(Node* node, int const value)
{
	if (node == NULL)
	{
		node = (struct Node*)malloc(sizeof(struct Node));
		node->value = value;
		node->next = NULL;
		return;
	}

	struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
	newHead->value = value;
	newHead->next = node;
	node = newHead;
}

void reverseHelp(Node* node, Node* newNode)
{
	if (node == NULL)
	{
		return;
	}

	Node* temp = init();

	while (node->next != NULL)
	{
		temp = node;
		node = node->next;
	}

	push(&newNode, node->value);
	free(node);
	reverseHelp(&temp, &newNode);
}

void reverse(Node* node)
{
	Node* newNode = init();

	if (node == NULL)
	{
		return;
	}

	reverseHelp(&node, &newNode);
}

void pushToNode()
{
	Node* node = init();
	FILE* file = fopen("text.txt", "r");

	if (file == NULL)
	{
		printf("couldnt get file");
		return;
	}
	
	int temp = 0;

	while (temp = fgetc(file) != EOF)
	{
		push(node, temp);
	}

	fclose(file);
	reverse(&node);
}


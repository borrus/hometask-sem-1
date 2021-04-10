#include <iostream>

using namespace std;

struct Node
{
	Node* next;
	int data;

	Node(int const data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

struct List
{
	Node* head;

	List()
	{
		this->head = nullptr;
	}

	void pushBack(int const data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = new Node(data);
	}

	void print()
	{
		if (head == nullptr)
		{
			cout << "list is empty" << endl;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
};

int main()
{
	List list;

	for (int i = 0; i < 10; ++i)
	{
		list.pushBack(i);
	}

	list.print();

	return 0;
}

//
//typedef struct Node {
//	int value;
//	struct Node* next;
//} Node;
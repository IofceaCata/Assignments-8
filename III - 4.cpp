#include<iostream>
#include<malloc.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}

	cout << "nullptr\n";
}

void push(struct Node** headRef, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

struct Node* ShuffleMerge(struct Node* a, struct Node* b)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = nullptr;

	while (1)
	{
		if (a == nullptr)
		{
            tail->next = b;
            break;
        }

        else if (b == nullptr)
		{
            tail->next = a;
            break;
        }

		else
		{
            tail->next = a;
            tail = a;
            a = a->next;

            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    return dummy.next;
}


int main()
{
	int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *a = nullptr, *b = nullptr;
	for (int i = n - 1; i >= 0; i = i - 2)
		push(&a, keys[i]);

    for (int i = n - 2; i >= 0; i = i - 2)
		push(&b, keys[i]);

	printList(a);

	printList(b);

	struct Node* head = ShuffleMerge(a, b);

	printList(head);

	return 0;
}

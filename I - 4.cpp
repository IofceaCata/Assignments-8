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

    cout << "nullptr";
}

void push(struct Node** headRef, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

int pop(struct Node* &headRef)
{
    if (headRef == nullptr)
        return -1;

    struct Node* head = headRef;
    int result = headRef->data;
    headRef = headRef->next;
    free(head);
    return result;
}
int main()
{
	int keys[] = {1, 2, 3, 4};
	int n = sizeof(keys)/sizeof(keys[0]);
	struct Node* head = nullptr;
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);
    cout << "Popped node " << pop(head) << endl;
    printList(head);

    return 0;
}

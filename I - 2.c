#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int x,int y,struct Node*pr,struct Node*ul)
{
    int i;
    struct Node* newElement=NULL;
    pr->data=1;
    pr->next=NULL;
    ul=pr;
    if(x>1)
        for(i=0; i<x-1; i++)
        {
            newElement=(struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&y);
            newElement->data=y;
            ul->next=newElement;
            newElement->next=NULL;
            ul=newElement;
        }
}

void PrintList(struct Node *node)
{
    if (!node) printf ("\n Empty list!");
    else
    {
        while(node)
        {
            printf("%d ", node->data);
            node = node->next;
        }
    }
}

int GetNth(int index,struct Node*p)
{
    struct Node*current=p;
    int count=0;

    while(current)
    {
        if(count==index) return current->data;
        count++;
        current=current->next;
    }
}

int main()
{
    struct Node* p=NULL;
    struct Node* u=NULL;
    p=(struct Node*)malloc(sizeof(struct Node));
    u=(struct Node *)malloc(sizeof(struct Node));

    int n;///the number of elements from the list
    int m;///elements from the list

    printf("Enter the number of elements from the list: ");
    scanf("%d",&n);

    printf("Enter the elements from the list: ");

    createList(n,m,p,u);
    PrintList(p);
    printf("\n");

    int i;
    printf("Enter the index position: ");
    scanf("%d",&i);

    printf("The data value stored in the position %d is: %d",i,GetNth(i,p));

    return 0;
}


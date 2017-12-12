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
    pr->data=y;
    pr->next=NULL;
    ul=pr;
    if(x>1)
        for(i=1; i<=x-1; i++)
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

int Count(int number,struct Node *pri)
{
    int count=0;
    while(pri)
    {
        if(pri->data==number) count++;

        pri=pri->next;
    }

    return count;
}

int main()
{
    struct Node* p=NULL;
    struct Node* u=NULL;
    p=(struct Node*)malloc(sizeof(struct Node));
    u=(struct Node *)malloc(sizeof(struct Node));

    int n;///the number of elements from the list
    int i;
    int m;///elements from the list

    printf("Enter the number of elements from the list: ");
    scanf("%d",&n);
    printf("Enter the first element: ");
    scanf("%d",&m);
    printf("Enter the elements from the list: ");

    createList(n,m,p,u);

    int x;///the number that has to be searched
    printf("Enter the number you want to count: ");
    scanf("%d",&x);

    printf("The number of times %d occurs in the list is: %d",x,Count(x,p));

    return 0;
}

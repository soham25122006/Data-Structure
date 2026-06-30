#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *first = NULL;

// x - value to be inserted
void insert(int x)
{
    struct Node *newNode=malloc(sizeof(*newNode));
    newNode->info=x;
    newNode->link=first;
    
    first=newNode;
}

void main()
{
    insert(10);
    insert(20);
    insert(30);
    printf("%d is the first node",first->info);
}
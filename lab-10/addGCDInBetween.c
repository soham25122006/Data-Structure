// WAP to perform given operation in the linked list. There exist a Linked List.
// Add a node that contains the GCD of those two nodes between every pair adjacent node of Linked List
//input:- 18 -> 6 -> 10 ->3
//output:- 18 -> 6 -> 6 -> 2 -> 10 -> 1 ->3
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *createNewnode(int x)
{
    struct Node *newnode = malloc(sizeof *newnode);
    newnode->info = x;
    newnode->link = NULL;

    return newnode;
}
void insert(struct Node **first, int x)
{
    struct Node *node = createNewnode(x);
    node->link = *first;
    *first = node;
}
int gcd(int n1, int n2)
{
    int num = (n1 > n2) ? n1 : n2;
    for (int i = num; i >= 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            return i;
        }
    }
}
void gcdinbetween(struct Node *save)
{
    if (save == NULL)
    {
        printf("underflow!!");
        return;
    }
    else if (save->link == NULL)
    {
        printf("only One node can't insert GCD!!");
        return;
    }
    while (save->link != NULL)
    {
        struct Node *node = createNewnode(gcd(save->info, save->link->info));
        node->link = save->link;
        save->link = node;
        save = save->link->link;
    }
}
void displayNodes(struct Node *save)
{
    if (save == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (save != NULL)
        {
            printf(" %d ", save->info);
            save = save->link;
        }
    }
    printf("\n");
}
void main()
{
    struct Node *list1 = NULL;

    insert(&list1, 3);
    insert(&list1, 10);
    insert(&list1, 6);
    insert(&list1, 18);

    gcdinbetween(list1);
    displayNodes(list1);
}
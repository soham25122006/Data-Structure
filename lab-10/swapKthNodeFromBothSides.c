// WAP to swap Kth node from beginning with Kth node from end in a singly linked list.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};

struct Node *createNode(int x)
{
    struct Node *newnode = malloc(sizeof *newnode);
    newnode->info = x;
    newnode->link = NULL;

    return newnode;
}

int insert(struct Node **first, int x)
{
    // to check many times user inserted a value(to determine length of list)
    static int insertcount = 0;
    struct Node *node = createNode(x);
    node->link = *first;
    *first = node;
    insertcount++;
    return insertcount;
}

void swapnodes(struct Node **first, int length, int k)
{
    struct Node *node1 = *first;
    struct Node *node2 = *first;
    struct Node *temp1 = NULL;
    struct Node *temp2 = NULL;
    int i;

    if (*first == NULL || 2 * k - 1 == length)
    {
        return;
    }

    for (i = 1; i < length - k + 1; i++)
    {
        if (i < k)
        {
            temp1 = node1;
            node1 = node1->link;
        }
        temp2 = node2;
        node2 = node2->link;
    }

    if (node1 == node2)
    {
        return;
    }

    if (temp1 != NULL)
    {
        temp1->link = node2;
    }
    else
    {
        *first = node2;
    }

    if (temp2 != NULL)
    {
        temp2->link = node1;
    }
    else
    {
        *first = node1;
    }

    struct Node *temp = node1->link;
    node1->link = node2->link;
    node2->link = temp;
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
    struct Node *list = NULL;

    insert(&list, 8);
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 7);
    insert(&list, 6);

    int lengthoflist = insert(&list, 10);

    int k = 2;

    swapnodes(&list, lengthoflist, k);

    displayNodes(list);
}
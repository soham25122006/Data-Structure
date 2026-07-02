// Write a program to sort elements of a linked list.

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

void insert(struct Node **first, int x)
{
    struct Node *node = createNode(x);
    node->link = *first;
    *first = node;
}

void sort(struct Node *save)
{
    struct Node *temp1 = NULL;
    struct Node *temp2 = NULL;
    while (save->link != NULL)
    {
        temp2 = save->link;
        while (temp2 != NULL)
        {
            if (save->info > save->link->info)
            {
                temp1->info = save->info;
                save->info = save->link->info;
                save->link->info = temp1->info;
            }
            temp2=temp2->link;
        }
        save=save->link;
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
    struct Node *list = NULL;
    insert(&list, 10);
    insert(&list, 7);
    insert(&list, 6);
    insert(&list, 1);

    sort(list);
    displayNodes(list);
}
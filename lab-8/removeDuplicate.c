#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *first = NULL;
void insert(int x)
{
    struct Node *newnode = malloc(sizeof *newnode);

    newnode->info = x;
    newnode->link = first;
    first = newnode;
}
void removecopy()
{
    struct Node *save;

    if (first == NULL)
    {
        printf("underflow!! can't delete Duplicate");
        return;
    }
    save = first;
    while (save!=NULL)
    {
        struct Node *temp = save->link;
        if (save->info == temp->info)
        {
            save->link = temp->link;
            free(temp);
        }
        save=save->link;
    }
}

void print()
{
    struct Node *save = first;
    while (save != NULL)
    {
        printf("%d  ", save->info);
        save = save->link;
    }
}
void main()
{
    insert(1);
    insert(1);
    insert(2);
    insert(2);
    insert(3);
    insert(4);
    insert(4);
    insert(5);
    insert(6);

    removecopy();

    print();
}
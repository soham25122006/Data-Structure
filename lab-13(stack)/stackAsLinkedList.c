// Write a program to implement stack using singly linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int info;
    struct stack *link;
} stack;

stack *createNode(int x)
{
    stack *newNode = malloc(sizeof *newNode);

    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}
void push(stack **top, int x)
{
    stack *node = createNode(x);
    node->link = *top;
    *top = node;
}

void displaystack(stack *save)
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
    free(save);
}

int pop(stack **top)
{
    if (*top == NULL)
    {
        printf("underFlow");
        return -1;
    }
    else
    {
        stack *temp = *top;
        *top = (*top)->link;
        int ele = temp->info;
        free(temp);
        return ele;
    }
}
void change(stack *save, int pos, int x)
{
    for (int i = 1; i < pos && save != NULL; i++)
    {
        save = save->link;
    }
    if (save == NULL)
    {
        printf("\nposition not available\n");
    }
    else
    {
        save->info = x;
    }
}

void peep(stack *save, int n)
{
    for (int i = 1; i < n; i++)
    {
        save = save->link;
    }
    printf("%d \n", save->info);
}

void main()
{
    stack *stack1 = NULL;
    push(&stack1, 1);
    push(&stack1, 3);
    push(&stack1, 2);
    push(&stack1, 4);
    push(&stack1, 5);

    displaystack(stack1);

    printf("\n after removing top element = %d\n", pop(&stack1));
    displaystack(stack1);

    // change()
    change(stack1, 2, 10);
    displaystack(stack1);

    // peep()
    peep(stack1, 2);
    displaystack(stack1);
}
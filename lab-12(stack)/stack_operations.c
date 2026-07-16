// Write a menu driven program to implement following operations on the Stack using an Array
//  PUSH, POP, DISPLAY
//  PEEP, CHANGE
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top;
    int size;
    int *array;
} stack;

void createstack(stack *s)
{
    int n = 10;
    (*s).top = -1;
    (*s).size = n;
    (*s).array = malloc(n * sizeof(int));
}

void push(stack *s, int x)
{
    if (s->top >= s->size - 1)
    {
        printf("overflow");
        return;
    }
    s->top++;
    s->array[s->top] = x;
}

void input(stack *s)
{
    int elements;
    int value;
    printf("enter how many elements you want to enter :=");
    scanf("%d", &elements);
    while ((s->top) + elements > s->size)
    {
        printf("enter a valid number of elements this value is out of stack size :=");
        scanf("%d", &elements);
    }
    if ((s->top) + elements < s->size)
    {
        for (int i = 1; i <= elements; i++)
        {
            printf("enter a value that you want to push in stack :=");
            scanf("%d", &value);
            push(s, value);
        }
    }
    else
    {
    }
}

void printstack(stack s)
{
    if (s.top < 0)
    {
        printf("stack is empty\n");
        return;
    }
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d ", s.array[i]);
    }
    printf("\n");
}

int pop(stack *s)
{
    if (s->top < 0)
    {
        printf("underflow!");
        return -1;
    }
    s->top--;
    return s->array[s->top + 1];
}

int peep(stack s, int i)
{
    if (s.top - i + 1 <= -1)
    {
        printf("ele not available");
        return -1;
    }
    return s.array[s.top - i + 1];
}

void ele_at_specific_point(stack *s, int position, int value)
{
    int i;
    if (position > s->top)
    {
        printf("the position is out of stack's top!");
        return;
    }
    if (s->top >= s->size - 1)
    {
        printf("%d can't be inserted stack is already full", value);
        return;
    }
    s->top++;
    for (i = s->top; i > s->top - position + 1; i--)
    {
        s->array[i] = s->array[i-1];
    }
    s->array[i] = value;
}

void change(stack s, int position, int value)
{
    int i;
    if (s.top - position + 1)
    {
        printf("element Not available");
        return;
    }
    s.array[s.top - position + 1] = value;
}

void main()
{
    stack s1;
    createstack(&s1);

    push(&s1, 132);
    push(&s1, 13);
    push(&s1, 21);
    push(&s1, 212);

    input(&s1);
    printstack(s1);

    printf("popped element is %d\n", pop(&s1));
    printstack(s1);

    ele_at_specific_point(&s1, 3, 12);
    printstack(s1);
    printf("peep :== %d", peep(s1, 3));
}
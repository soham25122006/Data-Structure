#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int top;
    int size;
    char *array;
} stack;

void initialize(stack *s)
{
    int n = 50;
    s->top = -1;
    s->size = n;
    s->array = malloc(n * sizeof(char));
}

void push(stack *s, char x)
{
    if (s->top >= s->size - 1)
    {
        printf("\noverflow!!\n");
        return;
    }
    s->top++;
    s->array[s->top] = x;
}
char pop(stack *s)
{
    if (s->top < 0)
    {
        printf("\nunderflow!!\n");
        return -1;
    }
    return s->array[--s->top + 1];
}

void input(char ip[])
{
    printf("enter a string :=");
    fgets(ip,50,stdin);
    ip[strlen(ip)]=' ';
}
char *resultentstring(stack *s,char str[])
{
    for(int i=0;str[i]!=' ';)
    {
        if (str[i] == '*')
        {
            pop(s);
        }
        else
        {
            push(s,str[i]);
        }
        i++;
    }
    return s->array;
}

void main()
{
    stack s;
    initialize(&s);

    char ip[50];
    input(ip);
    printf("output := %s",resultentstring(&s,ip));
}
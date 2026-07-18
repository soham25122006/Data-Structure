// Write a program to determine if an input character string is of the form aibi where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct
{
    int top;
    int size;
    char *array;
}stack;

stack initialize(stack *s)
{
    int n=10;
    s->top=-1;
    s->size=n;
    s->array=malloc(n*sizeof(char));
}
void push(stack *s,char x)
{
    if(s->top >=s->size-1)
    {
        printf("\noverflow!\n");
        return;
    }
    s->array[++s->top]=x;
}
char pop(stack *s)
{
    if(s->top <0)
    {
        printf("\nunderflow!\n");
        return -1;
    }
    s->top--;
    return s->array[s->top + 1];
}
bool isaibi(stack *s,char p[])
{
    int i = 0;
    while (p[i] != 'b')
    {
        push(s, p[i]);
        i++;
    }
    s->top++;
    while (s->top != -1 && p[i] != ' ')
    {
        if (pop(s) != 'a' && p[i] != 'b')
        {
            return false;
        }
        i++;
    }
    if (s->top == -1 && p[i] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void main()
{
    char str[50];
    stack s;
    initialize(&s);
    printf("enter the pattern :=");
    fgets(str,50,stdin);

    str[strlen(str)]=' ';

    if (isaibi(&s, str))
    {
        printf("pattern is correct");
        
    }
    else
    {
        printf("pattern is not correct");
    }
}
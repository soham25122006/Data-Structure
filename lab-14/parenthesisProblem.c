// Valid Parenthesis Problem
// Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.
// Now Chef wants to know if the given string is balanced or not.
// If is balanced then print 1, otherwise print 0.
// A balanced parenthesis string is defined as follows:
// - The empty string is balanced
// - If P is balanced then (P), {P}, [P] is also balanced
// - if P and Q are balanced PQ is also balanced
// - "([])", "({})[()]" are balanced parenthesis strings
// - "([{]})", "())" are not balanced.
// Input Format:
//
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows. The first and only line of each test case contains a single string
//
// Output Format:
// For each test case, print a single line containing the answer.
//
// Sample Example:
// Input:           Output:
// 4 -//(total number of inputs)
// ()               1
// ([)]             0
// ([{}()])[{}]     1
// [{{}]            0

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
        printf("\noverflow!\n");
        return;
    }
    s->top++;
    s->array[s->top] = x;
}
char pop(stack *s)
{
    if (s->top < 0)
    {
        printf("\nunderflow!\n");
        return -1;
    }
    s->top--;
    return s->array[s->top + 1];
}
int santulit_chhe(stack *s, char str[])
{
    s->top = -1;
    for (int i = 0; str[i] != ' '; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(s, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (s->top == -1)
            {
                return 0;
            }
            char ele = pop(s);
            if (ele == '{' && str[i] == '}' || ele == '(' && str[i] == ')' || ele == '[' && str[i] == ']')
            {
            }
            else
            {
                return 0;
            }
        }
    }
    return (s->top == -1) ? (1) : (0);
}

void input(char str[])
{
    printf("enter pattern:=");
    fgets(str, 50, stdin);

    str[strlen(str)] = ' ';
}

void main()
{
    stack s;
    initialize(&s);

    int n;
    printf("enter number of string :=");
    scanf("%d", &n);
    getchar();

    char str[n][50];

    for (int i = 0; i < n; i++)
    {
        input(str[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", santulit_chhe(&s, str[i]));
    }
    free(s.array);
}
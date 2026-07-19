// Merge Intervals Problem
// Given a set of time intervals in any order, our task is to merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals.
// Sample Example-1:
// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
// Output: {{1, 4}, {6, 8}, {9, 10}}
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], [9,10]
// Sample Example-2:
// Input: Intervals = {{6,8},{1,9},{2,4},{4,7}}
// Output: {{1, 9}}
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int pelo;
    int bijo;
} interval;
typedef struct
{
    int top;
    int size;
    interval *arr;
} stack;
void initialize(stack *s,int n)
{
    s->top = -1;
    s->size = n;
    s->arr = malloc(n * sizeof(interval));
}
void push(stack *s, interval intrvl)
{
    if (s->top >= s->size - 1)
    {
        printf("\noverflow!\n");
        return;
    }
    s->top++;
    s->arr[s->top].pelo = intrvl.pelo;
    s->arr[s->top].bijo = intrvl.bijo;
}
interval pop(stack *s)
{
    if (s->top < 0)
    {
        printf("\nunderflow!\n");
        interval i = {-1, -1};
        return i;
    }
    s->top--;
    return s->arr[s->top + 1];
}

void input(interval intrvl[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("enter start and end values for interval no.%d (separeted by space):=", i + 1);
        scanf("%d %d", &intrvl[i].pelo, &intrvl[i].bijo);
    }
}
void sortinterval(interval intrvl[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (intrvl[i].pelo > intrvl[j].pelo)
            {
                interval temp = intrvl[i];
                intrvl[i] = intrvl[j];
                intrvl[j] = temp;
            }
        }
    }
}
void mergeintervals(stack *s, interval intrvl[], int size)
{
    push(s, intrvl[0]);
    for (int i = 1; i < size; i++)
    {
        interval topele = pop(s);
        if (topele.bijo >= intrvl[i].pelo)
        {
            topele.pelo = (intrvl[i].pelo <= topele.pelo) ? (intrvl[i].pelo) : (topele.pelo);

            topele.bijo = (intrvl[i].bijo >= topele.bijo) ? (intrvl[i].bijo) : (topele.bijo);

            push(s, topele);
        }
        else
        {
            push(s, topele);
            push(s, intrvl[i]);
        }
    }
}

void print_final_interval(stack s)
{
    if(s.top==-1)
    {
        printf("\nthere are no intervals given\n");
    }
    int i;
    for (i = 0; i < s.top; i++)
    {
        printf("{%d,%d},", s.arr[i].pelo, s.arr[i].bijo);
    }
    printf("{%d,%d}", s.arr[i].pelo, s.arr[i].bijo);
}
void main()
{
    int n;
    printf("enter numbers of intervals :=");
    scanf("%d", &n);
    interval intrvl[n];
    stack s;
    initialize(&s,n);
    int size = sizeof(intrvl) / sizeof(intrvl[0]);
    input(intrvl, size);
    sortinterval(intrvl, size);
    mergeintervals(&s, intrvl, size);
    print_final_interval(s);
    free(s.arr);
}
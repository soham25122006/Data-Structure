// Vowel Anxiety Problem
// Utkarsh has recently started taking English-language classes to improve his reading and writing skills. However, he is still struggling to learn English. His teacher gave him the following problem to improve his vowel-identification skills:
// There is a string S of length N consisting of lowercase English letters only.
// Utkarsh has to start from the first letter of the string. Each time he encounters a vowel; he has to reverse the entire substring that came before the vowel.
// Utkarsh needs help verifying his answer. Can you print the final string after performing all the operations for him?
// Input Format:
//  First line will contain T, number of test cases. Then T test cases follow.
//  The first line of each test case contains N, the length of the string.
//  The second line contains S, the string itself.
// Output Format:
// For each test case, output in a single line the final string after traversing S from left to right and performing the necessary reversals.
// Sample Example:
// Input:           Output:
// 2                hgfeabcdij
// 10               gacbade
// abcdefghij
// 7
// bcadage
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int top;
    int size;
    char *array;
} Stack;

void initialize(Stack *s, int n)
{
    s->top = -1;
    s->size = n;
    s->array = (char *)malloc(n * sizeof(char));
}

void push(Stack *s, char ch)
{
    if (s->top == s->size - 1)
        return;

    s->array[++s->top] = ch;
}

char pop(Stack *s)
{
    if (s->top == -1)
        return '\0';

    return s->array[s->top--];
}
void processString(char str[], int n)
{
    Stack s;
    initialize(&s, n);

    char temp[n + 1];

    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            s.top = -1;
            int k = 0;
            for (int j = 0; j < i; j++)
            {
                push(&s, str[j]);
            }
            while (s.top >= 0)
            {
                temp[k++] = pop(&s);
            }
            for (int j = i; j < n; j++)
            {
                temp[k++] = str[j];
            }

            temp[k] = '\0';
            strcpy(str, temp);
        }
    }
    printf("%s\n", str);
    free(s.array);
}
int main()
{
    int num;
    printf("enter nuber of testcase:=");
    scanf("%d", &num);
    while (num != 0)
    {
        int n;
        printf("enter the size of string:=");
        scanf(" %d", &n);
        getchar();

        char str[n + 1];
        printf("enter the string to reverse it :=");
        scanf("%s", str);
        num--;

        processString(str, n);
    }
    return 0;
}
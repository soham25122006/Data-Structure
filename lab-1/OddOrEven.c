// WAP to find whether a number is odd or even.
#include <stdio.h>
void main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("even\n");
    else
        printf("odd\n");
}
// Write a program to calculate avg of first n numbers.
#include <stdio.h>
void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("The avg of the first %d numbers is: %.2f\n", n, (float)sum / n);
}
// Write a program to calculate sum of numbers from m to n.
#include <stdio.h>
void main()
{
    int m, n;
    printf("Enter the value of m and n (m <= n): ");
    scanf("%d %d", &m, &n);

    int sum = 0;
    for (int i = m; i <= n; i++)
    {
        sum += i;
    }

    printf("The sum of numbers from %d to %d is: %d\n", m, n, sum);
}
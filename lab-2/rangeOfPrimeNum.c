// WAP to print prime numbers between given interval.
#include <stdio.h>
void main()
{
    int lower, upper;

    printf("Enter the lower and upper limits: ");
    scanf("%d%d", &lower, &upper);

    for (int i = lower; i <= upper; i++)
    {
        int isPrime = 1;
        if (i <= 1)
            continue;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d ", i);
    }
    printf("\n");
}
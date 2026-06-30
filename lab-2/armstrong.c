// WAP to print Armstrong number from 1 to 1000.
#include <stdio.h>
void main()
{
    printf("Armstrong numbers between 1 and 1000 are:\n");
    
    for (int i = 1; i <= 1000; i++)
    {
        int sum = 0, temp = i;
        while (temp != 0)
        {
            int digit = temp % 10;
            sum += digit * digit * digit;
            temp /= 10;
        }
        if (sum == i)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
// WAP to find the largest among the given three numbers by user.
#include <stdio.h>
void main()
{
    int num1, num2, num3;

    printf("Enter three numbers:");
    scanf("%d %d %d", &num1, &num2, &num3);

    int largest = (num1 > num2) ? ((num1 > num3) ? num1 : num3)
                                : ((num2 > num3) ? num2 : num3);
    printf("The largest number is: %d\n", largest);
}
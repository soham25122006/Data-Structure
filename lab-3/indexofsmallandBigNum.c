// Write a program to find position of the smallest number & the largest number
// from given n numbers.
#include <stdio.h>
void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = 0, max = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }

    printf("The position of the smallest number is: %d\n", min + 1);
    printf("The position of the largest number is: %d\n", max + 1);
}
// Read n numbers in an array then read two different numbers, replace 1st
// number with 2nd number in an array and print its index and final array.
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

    int num1, num2;
    printf("Enter two diff numbers: ");
    scanf("%d %d", num1, num2);

    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num1)
        {
            arr[i] = num2;
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        printf("The index of the replaced number is: %d\n", index);
    }
    else
    {
        printf("The number %d was not found in the array.\n", num1);
    }

    printf("Final array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Write a program to delete duplicate numbers from an array.
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

    // Remove duplicates
    int newArr[n];
    int newSize = 0;

    for (int i = 0; i < n; i++)
    {
        int isDuplicate = 0;
        for (int j = 0; j < newSize; j++)
        {
            if (arr[i] == newArr[j])
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate)
        {
            newArr[newSize++] = arr[i];
        }
    }

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", newArr[i]);
    }
    printf("\n");
}
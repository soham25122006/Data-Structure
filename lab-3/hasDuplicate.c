// Write a program to find whether the array contains a duplicate number or not.
#include <stdio.h>
#include<stdbool.h>
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

    int hasDup = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                hasDup = true;
                break;
            }
        }
        if (hasDup)
        {
            break;
        }
    }

    if (hasDup)
    {
        printf("The array contains a duplicate number.\n");
    }
    else
    {
        printf("The array does not contain any duplicate numbers.\n");
    }
}
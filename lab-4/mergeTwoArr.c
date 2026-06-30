// Write a program to merge two unsorted arrays.
#include <stdio.h>
void main()
{
    int n1, n2;
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);

    int arr1[n1], arr2[n2], mergedArr[n1 + n2];

    printf("Enter %d numbers for the first array:\n", n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter %d numbers for the second array:\n", n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    // Merge the two arrays
    for (int i = 0; i < n1; i++)
    {
        mergedArr[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        mergedArr[n1 + i] = arr2[i];
    }

    printf("Merged array:\n");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");
}
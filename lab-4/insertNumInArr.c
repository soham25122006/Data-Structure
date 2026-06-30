// 24. Write a program to insert a number at a given location in an array(Zero-based index).
#include <stdio.h>
void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n + 1];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num, pos;
    printf("Enter the number to insert and the position (zero-based index): ");
    scanf("%d %d", &num, &pos);

    if (pos < 0 || pos > n)
    {
        printf("Invalid position. Please enter a position between 0 and %d.\n", n - 1);
        return;
    }

    // Shift right
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    
    // Insert specified position
    arr[pos] = num;

    printf("Array after insertion:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
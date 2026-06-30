// Write a program to delete a number from a given location in an array(Zero-based index).
#include <stdio.h>
void main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pos;
    printf("Enter the position to delete (0-based index): ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n)
    {
        printf("Invalid position. Please enter a position between 0 and %d.\n", n - 1);
        return;
    }

    // Shift left
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    printf("Array after deletion:\n");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
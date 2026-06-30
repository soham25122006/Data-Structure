// Read two 2x2 matrices and perform addition of matrices into third matrix and print it
#include <stdio.h>
void main()
{
    int n;
    printf("enter size of matrix\n");
    scanf("%d", &n);

    int a[n][n], b[n][n], c[n][n];
    printf("enter elements of first matrix\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("enter elements of second matrix\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("sum of matrices is:\n");
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
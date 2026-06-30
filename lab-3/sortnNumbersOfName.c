// WAP to sort the N names in an alphabetical order.
#include <stdio.h>
#include <string.h>
void main()
{
    int n;
    printf("Enter the number of names: ");
    scanf("%d", &n);

    char names[n][100];
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", names[i]);
    }

    // Sort the names in alphabetical order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char temp[100];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }
}
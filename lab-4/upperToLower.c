// WAP to replace lowercase characters by uppercase & vice-versa in a user
// specified string.
#include <stdio.h>
void main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A'); // Convert to uppercase
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A'); // Convert to lowercase
        }
    }

    printf("String after case conversion: %s\n", str);
}
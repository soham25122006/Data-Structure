// 33. Design anagram game using array.
//  Allow a user to enter N words and store it in an array.
//  Generate a random number between 0 to N-1.
//  Based on the random number generated display the word stored at that
// index of an array and allow user to enter its anagram.
//  Check whether the word entered by the user is an anagram of displayed
// number or not and display an appropriate message.
//  Given a word A and word B. B is said to be an anagram of A if and only if the
// characters present in B is same as characters present in A, irrespective of
// their sequence. For ex: “LISTEN” == “SILENT”
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void sortString(char str[])
{
    int i, j;
    char temp;

    int len = strlen(str);

    for(i = 0; i < len - 1; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i, index;

    char words[100][50];
    char selectedWord[50];
    char userWord[50];

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("\nEnter %d words:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", words[i]);
    }

    srand(time(NULL));

    index = rand() % n;

    strcpy(selectedWord, words[index]);

    printf("\nWord Selected: %s", selectedWord);

    printf("\nEnter its anagram: ");
    scanf("%s", userWord);

    if(strlen(selectedWord) != strlen(userWord))
    {
        printf("\nNot An Anagram");
        return 0;
    }

    sortString(selectedWord);
    sortString(userWord);

    if(strcmp(selectedWord, userWord) == 0)
    {
        printf("\nCorrect! It is an Anagram.");
    }
    else
    {
        
        printf("\nWrong! It is Not an Anagram.");
    }

    return 0;
}
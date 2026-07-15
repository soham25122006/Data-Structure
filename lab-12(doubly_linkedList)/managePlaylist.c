// Write a program to simulate music player application using suitable data structure. There is no estimation about number of music files to be managed by the music player. Your program should support all the basic music player operations to play and manage the playlist.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
    char str[50];
    struct Node *r;
    struct Node *l;
} playlist;

struct Node *createNode(char s[])
{
    playlist *newnode = malloc(sizeof(playlist));
    strcpy(newnode->str, s);
    newnode->r = NULL;
    newnode->l = NULL;
    return newnode;
}

void insertSong(playlist **list, char s[])
{
    playlist *song = createNode(s);
    if (list)
}

void enterChoice(playlist **list)
{
    char s[50];
    int ch;
    struct Node *song;
    printf("to add a song enter-1");
    printf("\nto remove a song enter-2");
    printf("\nto view playlist enter-3");
    printf("\nto play next song enter-4");
    printf("\nto play previous song enter-5");
    printf("\nto search a song enter-6");
    printf("\nto shuffle songs enter-7");
    printf("\nto repeat songs enter-8");
    printf("\n\nenter the number := ");
    while (true)
    {
        scanf("%d", &ch);
        switch (ch)
        {
        // add song
        case 1:
            printf("enter the song :=");
            fgets(s, 50, stdin);
            insertSong(list, s);
            printf("song added at the start");
            break;
        // remove song
        case 2:
            printlist(*list);
            printf("enter the position of song");
            scanf("%d", &ch);
            deleteNode(list, ch);
            break;
        // view playlist
        case 3:
            printlist(*list);
            break;
        // play next song
        case 4:
            song = play_next(*list);
            printf("playing next song %s", song);
            break;
        // plat previous song
        case 5:
            song = play_previous(*list);
            printf("playing previous song %s", song);
            break;
        // search a song
        case 6:

            break;
        // shuffle list
        case 7:

            break;
        // repeat song
        case 8:

            break;

        default:
            printf("enter approprite option!!");
            ch = -1;
            break;
        }
        if (ch == -1)
        {
            break;
        }
    }
}
void insendSong()
{
    playlist *list1 = NULL;
}
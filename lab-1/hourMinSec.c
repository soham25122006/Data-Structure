// WAP to convert seconds into h, m & seconds and print in HH:MM:SS
// [e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)].
#include <stdio.h>
void main()
{
    int tsec, h, m, s;

    printf("Enter the total number of s: ");
    scanf("%d", &tsec);

    h = tsec / 3600;
    m = (tsec % 3600) / 60;
    s = tsec % 60;

    printf("Time in HH:MM:SS format: %d:%d:%d\n", h, m, s);
}
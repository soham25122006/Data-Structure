// WAP to convert number of days into year, week & days [e.g. 375 days mean 1
// year, 1 week and 3 days].
#include <stdio.h>
void main()
{
    int tdays, years, weeks, days;

    printf("Enter the total number of days: ");
    scanf("%d", &tdays);

    years = tdays / 365;
    weeks = (tdays - (years * 365)) / 7;
    days = tdays - (years * 365) - (weeks * 7);

    printf("Time in years, weeks and days format: %d year, %d week, %d day\n", years, weeks, days);
}
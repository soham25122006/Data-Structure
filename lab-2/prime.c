#include<stdio.h>
#include<stdbool.h>
void main()
{
    int n,i;
    bool isprime=true;
    printf("enter a number:=");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            isprime=false;
            break;
        }
        else{}
    }
    if(isprime)
    {
        printf("prime");
    }
    else
    {
        printf(" not prime");
    }
}
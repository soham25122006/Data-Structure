#include<stdio.h>
// powerOfNumber
void main()
{
    int i,num,pow,ans=1;
    printf("enter a number and it's power:=");
    scanf("%d %d",&num,&pow);
    for(i=1;i<=pow;i++)
    {
        ans=ans*num;
    }
    printf(" %d ",ans);
}
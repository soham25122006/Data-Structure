#include<stdio.h>
void main()
{
    int a,temp1,temp2,rev=0;
    printf("enter value:=");
    scanf("%d",&a);
    temp2=a;
    while(a!=0)
    {
        temp1=a%10;
        rev=rev*10+temp1;
        a=a/10;
    }
    printf("%d",rev);
}
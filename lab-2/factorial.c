#include<stdio.h>
int factorial(int i);
void main()
{
    int i,fact=1;
    printf("enter a number:=");
    scanf("%d",&i);
    int ans=factorial(i);
    printf("%d!=",i);
    while(i!=1)
    {
        fact=fact*i;
        printf("%d*",i);
        i--;
    }
    printf("1= %d\n",fact);
    printf("%d",ans);
}

int factorial(int i)
{
    if(i==0)
    {
        return 1;
    }
    else
    {
      return i*factorial(i-1);
    }
}
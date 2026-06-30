// WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n)
#include <stdio.h>
void main()
{
    int n, x=0, sum=0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        x += i;
        sum += x;
    }
    printf("The total sum is: %d\n", sum);
}
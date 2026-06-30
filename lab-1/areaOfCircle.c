// WAP to calculate area of a Circle (A = πr2).
#include <stdio.h>
void main()
{
    float r;

    printf("Enter the radius of the circle: ");
    scanf("%f", &r);

    printf("The area of the circle is: %.2f\n", 3.14 * r * r);
}
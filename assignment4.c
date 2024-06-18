#include <stdio.h>
#define PIE 3.14
int main(void)
{
    float radius;
    printf("Enter the radius of your circle: ");
    scanf("%f", &radius);
    printf("The area of your circle is %.2f", (PIE * (radius * radius)));
    return 0;
}
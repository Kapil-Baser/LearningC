#include <stdio.h>

struct assignment20
{
    int a;
    char ch;
    float f;
}assign;

int main(void)
{
    assign.a = 50;
    assign.ch = 'W';
    assign.f = 3.14f;

    printf("This is the int: %d, this is the char: %c, this is the float: %f\n", assign.a, assign.ch, assign.f);
    return 0;
}
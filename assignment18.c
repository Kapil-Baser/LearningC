/**
 * Since we are printing an array of char, in C a string must be terimated by the '\0' charecter. So in this case our printf keeps on printing well past the array.
*/
/**
 * When puts is used, it will add a trailing newline to the stdout.
*/
#include <stdio.h>

void hello(void)
{
    char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33, '\0'};
    //printf("%s", array);
    puts(array);
}
int main(void)
{
    hello();
    return 0;
}
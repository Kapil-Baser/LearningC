#include <stdio.h>

int main(void)
{
    int num = 42;
    int *ptr = &num;
    printf("The value of our pointer is: %p\n", ptr);
    printf("Size of our pointer is: %llu bytes\n", sizeof(ptr));
    return 0;
}
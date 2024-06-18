#include <stdio.h>
#define MAX 10

int main(void)
{
    int array[MAX];

    printf("%p", array);
    /**
     * We are getting this memory address as our output since in C array decays to a pointer.
    */
    return 0;
}
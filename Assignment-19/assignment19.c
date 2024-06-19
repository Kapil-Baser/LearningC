#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ch = malloc(sizeof(*ch));
    if (ch == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    else
    {
        printf("Memory was successfully allocated\n");
    }

    free(ch);
    return 0;
}
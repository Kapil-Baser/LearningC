#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void *my_malloc(int n);
char *dup_str(const char * str);
int *create_array(int n, int initial_value);


int main(void)
{
    char *s = dup_str("Hello, World!");
    puts(s);
    int *arr = create_array(5, 0);
    return 0;
}

void *my_malloc(int n)
{
    void *p = malloc(n * sizeof(char));
    if (p == NULL)
    {
        printf("Error: Allocation failed\n");
        exit(1);
    }
    else
    {
        return p;
    }
}

char *dup_str(const char *str)
{
    size_t len = strlen(str);
    char *s = my_malloc(len + 1);
    memccpy(s, str, '\0', len + 1);
    return s;
}

int *create_array(int n, int initial_value)
{
    int *a = my_malloc(n * sizeof(*a));
    for (int i = 0; i < n; i++)
    {
        a[i] = initial_value;
    }
    return a;
}

int p(int n)
{
    return n;
}

int sum(int (*f)(int), int start, int end)
{
    int sum = 0;
    for (start ; start <= end; start++)
    {
        sum += (*f)(start);
    }
    return sum;
}


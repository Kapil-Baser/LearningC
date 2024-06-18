#include <stdio.h>

struct st
{
    int num;
};

int main(void)
{
    struct st *ptr_st;
    struct st s;
    // init pointer to point to the struct s
    ptr_st = &s;

    // assigning a value using dot-notation to struct s
    s.num = 42;
    printf("%d\n", s.num);

    // assinging a value using do-notation for the pointer to the struct s
    (*ptr_st).num = 50;
    printf("%d\n", (*ptr_st).num);

    // assigning a value using -> indirect membership operator to the struct s
    ptr_st->num = 42;
    printf("%d\n", ptr_st->num);

    return 0;
}
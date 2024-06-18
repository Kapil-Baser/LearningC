#include <stdio.h>

int main(void)
{
    int test_cases;
    scanf("%d", &test_cases);

    int x, y;
    while (test_cases--)
    {
        scanf("%d %d", &x, &y);

        printf("%d %d\n", (x < y) ? x : y, (x < y) ? y : x);
    }
    return 0;
}
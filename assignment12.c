#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum coin_flip {HEAD, TAIL};
int main(void)
{
    srand(time(NULL));
    int flip_count;
    int heads = 0;
    int tails = 0;
    printf("How many times would you like to flip the coin? ");
    scanf(" %d", &flip_count);
    printf("After flipping the coin %d times, the results were\n", flip_count);
    while (flip_count != 0)
    {
        if (HEAD == (rand() % 2))
        {
            heads++;
        }
        else
        {
            tails++;
        }
        flip_count--;
    }
    printf("%d heads\n%d tails\n", heads, tails);
    return 0;
}
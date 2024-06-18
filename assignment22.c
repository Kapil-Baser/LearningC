#include <stdio.h>
#define NUM_PLAYERS 5

struct stats
{
    int points;
    int games;
};

/* Function prototypes */
void get_input(struct stats p[]);
void print_avg(struct stats p[]);

int main(void)
{
    struct stats player[5];
    get_input(player);
    print_avg(player);
    return 0;
}

void get_input(struct stats p[])
{
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Enter player %d's point total: ", i + 1);
        scanf("%d", &p[i].points);
        printf("Enter player %d's game total: ", i + 1);
        scanf("%d", &p[i].games);
    }
}

void print_avg(struct stats p[])
{
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Player %d's scoring average was %.2f ppg.\n", i + 1, p[i].points / (float)p[i].games);
    }
}

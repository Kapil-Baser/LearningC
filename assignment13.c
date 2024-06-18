#include <stdio.h>
#include <stdlib.h>
#define ROWS 4
#define COLS 5

struct players
{
    int scoring_totals;
    float average;
}players[5];

int main(void)
{
    int scoring_totals[ROWS][COLS];

    for (size_t i = 0; i < ROWS; i++)
    {
        printf("Game #%lld\n", i + 1);
        for (size_t j = 0; j < COLS; j++)
        {
            printf("Enter scoring total for player #%lld: ", j + 1);
            scanf(" %d",&scoring_totals[i][j]);
            players[j].scoring_totals += scoring_totals[i][j];
        }
    }
    size_t i = 1;
    size_t highest_player_index = 0;
    int score = players[0].scoring_totals;
    for ( ; i < COLS; i++)
    {   
        if (players[i].scoring_totals > score)
        {
            highest_player_index = i;
            score = players[i].scoring_totals;
        }
    }
    printf("Player #%lld had the highest scoring average at %.2f points per game.\n", highest_player_index + 1, players[highest_player_index].scoring_totals / (float)4);
    return 0;
}
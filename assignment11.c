#include <stdio.h>
#include <ctype.h>

#define MAX 10

float sum(int arr[], int size)
{
    float sum;
    for (size_t i = 0; i < size; i++)
    {
        sum += (float)arr[i];
    }
    return (sum / (float)size);
}
int main(void)
{
    int test_score[MAX] = {0};
    int idx = 0;
    char c = 'y';
    do
    {
        printf("Enter a test score: ");
        scanf_s(" %d", &test_score[idx], sizeof(test_score));
        idx++;
        printf("Would you like to continue? Y/N:");
        scanf(" %c", &c);

    } while (tolower(c) == 'y' && idx != 8);

    printf("%.2f is the average.\n", sum(test_score, idx));

    return 0;
}
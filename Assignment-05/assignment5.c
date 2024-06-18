#include <stdio.h>
#define HOURS 3600
#define MINUTES 60

int compute_time(int *seconds, int n);

typedef int (*fnptrOperation)(int *, int);
int compute(fnptrOperation operation, int *, int);

int main(void)
{
    unsigned int seconds;
    printf("Enter the amount of seconds: ");
    scanf("%d", &seconds);
    // computing results.
    int hours = compute(compute_time, &seconds, HOURS);
    int minutes = compute(compute_time, &seconds, MINUTES);
    printf("Entered seconds is equal to %d hours, %d minutes and %d seconds\n", hours, minutes, seconds);
    return 0;
}

int compute_time(int *seconds, int n)
{
    int hours = 0;
    while (1)
    {
        if (*seconds >= n)
        {
            *seconds -= n;
            hours++;
        }
        else
        {
            break;
        }
    }
    return hours;
}

int compute(fnptrOperation operation, int *sec, int n)
{
    return operation(sec, n);
}

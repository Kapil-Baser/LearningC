#include <stdio.h>

int sum_of_array(int arr[], int size);

int main(void)
{
    int array[] = {5, 1, 17, 10, 3, 8, 4, 7, 6, 9};

    int size = sizeof(array) / sizeof(array[0]);
    sum_of_array(array, size - 1);
    printf("The array has %d elements\n", size);
    
    return 0;
}

int sum_of_array(int arr[], int size)
{
    // base case
    if (size == 0)
    {
        return arr[0];
    }
    // recursive case
    int sum = sum_of_array(arr, size - 1);
    sum += arr[size];
    return sum;
}

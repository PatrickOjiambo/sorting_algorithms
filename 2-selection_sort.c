#include "sort.h"
#include <stdio.h>
/**
 * selection_sort - sorts an array of integers in 
 * ascending order using the Selection sort algorithm
 * @array: Array to be sorted.
 * @size: Size of the array to be sorted.
*/
void selection_sort(int *array, size_t size)
{
    size_t i, minimum, j;
    for(i = 0;i < size - 1; i++)
    {
        minimum = i;
        for (j = i+1; j < size; j++)
        {
            if(array[j] < array[minimum])
            {
                minimum = j;
            }
        }
        swap_selection(&array[i], &array[minimum]);
        print_array(array, size);
    }
}
/**
 * swap_selection - Function to swap 2 integers
 * @x: First integer to be swapped
 * @y: Second integer to be swapped
*/
void swap_selection(int* x, int* y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}
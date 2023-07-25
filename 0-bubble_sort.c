#include <stdio.h>
#include <stdbool.h>
#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in 
 * ascending order using the Bubble sort algorithm
 * 
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
*/
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    bool swapped;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = true;
                print_array(array, size);
            }
            
        }
        if (swapped == false)
        {
            break;
        }
    }



}

/**
 * swap - Function to swap 2 integers
 * @x: First integer to be swapped
 * @y: Second integer to be swapped
*/
void swap(int* x, int* y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}
#include "sort.h"
/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array:The array to be sorted.
 * @size:The size of the array to be sorted
 *
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
/**
 * quick_sort_recursive - Recursively calls the partition
 * function on the array.
 * @array: The array to be sorted.
 * @high: The pivot. Rightmost index.
 * @low: The lower index of the array.
 */
void quick_sort_recursive(int array[], int low, int high, size_t size)
{
	if (low < high)
	{
		int pi;
		pi = partition(array, low, high, size);
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}
/**
 * partition - Partitions the array
 * @array:Array to be sorted.
 * @high:Pivot of the array.
 * @low:Lower index of the array
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = (low - 1);
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_quick(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_quick(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}
/**
 * swap_quick - Swap two values x and y.
 * @x:The first value to be swapped.
 * @y:The other value to be swapped.
 */
void swap_quick(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
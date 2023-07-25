#include <stdio.h>

// Function to swap two elements in the array
void swap_quick(int *x, int *y);
void swap_quick(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to print the array
void print_array(int *array, size_t size);
void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function prototypes
int partition(int array[], int low, int high);
void quick_sort_recursive(int array[], int low, int high);
void quick_sort(int *array, size_t size);

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted
 */
void quick_sort(int *array, size_t size) {
    quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - Recursively calls the partition
 * function on the array.
 * @array: The array to be sorted.
 * @low: The lower index of the array.
 * @high: The pivot. Rightmost index.
 */
void quick_sort_recursive(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort_recursive(array, low, pi - 1);
        quick_sort_recursive(array, pi + 1, high);
    }
}

/**
 * partition - Partitions the array
 * @array: Array to be sorted.
 * @low: Lower index of the array.
 * @high: Pivot of the array.
 * Return: The index of the partition.
 */
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap_quick(&array[i], &array[j]);
        }
    }
    swap_quick(&array[i + 1], &array[high]);
    print_array(array, high - low + 1);
    return (i + 1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, size);

    quick_sort(arr, size);

    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}

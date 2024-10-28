#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of @array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_function(array, size, array, size);
}

/**
 * sort_function - Performs sorting of arrays
 *
 * @array: The array to be sorted
 * @size: The size of @array
 * @o_array: Original array
 * @o_size: Original number of elements of @o_array
 */

void sort_function(int *array, size_t size, int *o_array, size_t o_size)
{
	int pivot;
	size_t i, j;

	if (size < 2)
		return;
	pivot = array[size - 1];
	i = 0;
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(o_array, o_size);
			}
			i++;
		}
	}
	if (i != size - 1)
	{
		swap(&array[i], &array[size - 1]);
		print_array(o_array, o_size);
	}
	sort_function(array, i, o_array, o_size);
	sort_function(array + i + 1, size - i - 1, o_array, o_size);
}

/**
 * swap - Swaps two values
 *
 * @a: Pointer to first value to swap
 * @b: Pointer to second value to swap
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

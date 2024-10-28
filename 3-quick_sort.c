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
	int pivot;
	size_t i, j;
	static int *o_array;
	static size_t o_size;

	if (array == NULL || size < 2)
		return;
	if (o_array == NULL)
	{
		o_array = array;
		o_size = size;
	}
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
	quick_sort(array, i);
	quick_sort(array + i + 1, size - i - 1);
	if (array == o_array && size == o_size)
	{
		o_array = NULL;
		o_size = 0;
	}
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

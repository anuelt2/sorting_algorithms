#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: The array to be sorted
 * @size: The number of elements in @array
 */

void shell_sort(int *array, size_t size)
{
	size_t interval;
	int i;
	size_t j;

	interval = 1;
	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}

	for (interval = interval; interval >= 1; interval /= 3)
	{
		for (j = interval; j < size; j++)
		{
			for (i = j - interval; i >= 0 && array[i + interval]
					< array[i]; i -= interval)
			{
				swap(&array[i + interval], &array[i]);
			}
		}
		print_array(array, size);
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

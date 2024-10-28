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
	size_t i;
	size_t j;
	int temp;

	if (array == NULL || size < 2)
		return;
	interval = 1;
	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}

	for (; interval > 0; interval /= 3)
	{
		for (j = interval; j < size; j++)
		{
			temp = array[j];
			for (i = j; i >= interval && array[i - interval]
					> temp; i -= interval)
			{
				swap(&array[i], &array[i - interval]);
			}
			array[i] = temp;
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

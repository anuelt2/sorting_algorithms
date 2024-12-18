#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void counting_sort(int *array, size_t size)
{
	size_t i, k;
	int *count, *sorted;

	if (array == NULL || size < 2)
		return;
	k = 0;
	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > k)
			k = array[i];
	}
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		count[array[i]] += 1;
	}
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}
	for (i = size; i > 0; i--)
	{
		sorted[--count[array[i - 1]]] = array[i - 1];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sorted[i];
	}

	free(count);
	free(sorted);
}

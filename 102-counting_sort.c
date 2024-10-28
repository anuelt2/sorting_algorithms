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
	int i, k, *count, *sorted;

	k = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]]++;
	}
	print_array(count, k + 1);
	for (i = 1; i <= k; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		sorted[--count[array[i]]] = array[i];
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = sorted[i];
	}

	free(count);
	free(sorted);
}

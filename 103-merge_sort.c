#include "sort.h"

/**
 * merge_array - Merges sorted subarrays
 *
 * @array: The array to be sorted
 * @l_bound: Lower bound of array being sorted
 * @u_bound: Upper bound of array being sorted
 * @mid: Mid-point of array being sorted
 */

void merge_array(int *array, size_t l_bound, size_t u_bound, size_t mid)
{
	size_t i, j, k;
	int *sorted;

	i = l_bound;
	j = mid;
	k = l_bound;

	sorted = malloc(sizeof(int) * (u_bound - l_bound + 1));
	if (sorted == NULL)
		return;
	printf("Merging...\n[left]: ");
	print_array(array + l_bound, mid - l_bound);
	printf("[right]: ");
	print_array(array + mid, u_bound - mid + 1);
	while (i < mid && j <= u_bound)
	{
		if (array[i] <= array[j])
			sorted[k++ - l_bound] = array[i++];
		else
			sorted[k++ - l_bound] = array[j++];
	}
	if (i >= mid)
	{
		while (j <= u_bound)
			sorted[k++ - l_bound] = array[j++];
	}
	else
	{
		while (i < mid)
			sorted[k++ - l_bound] = array[i++];
	}
	printf("[Done]: ");
	print_array(sorted, u_bound - l_bound + 1);
	for (i = l_bound; i <= u_bound; i++)
	{
		array[i] = sorted[i - l_bound];
	}
	free(sorted);
}

/**
 * merge_recursive - Sorts an array of integers in ascending order using
 * the Merge sort algorithm recursively
 *
 * @array: The array to be sorted
 * @l_bound: Lower bound of array being sorted
 * @u_bound: Upper bound of array being sorted
 */

void merge_recursive(int *array, size_t l_bound, size_t u_bound)
{
	size_t mid;

	if (l_bound < u_bound)
	{
		mid = l_bound + (u_bound - l_bound + 1) / 2;
		merge_recursive(array, l_bound, mid - 1);
		merge_recursive(array, mid, u_bound);
		merge_array(array, l_bound, u_bound, mid);
	}
}

/**
 * merge_sort - Merges an array of integers in ascending order using
 * the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge_recursive(array, 0, size - 1);
}

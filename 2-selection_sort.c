#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: The number of elements in @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int smallest;
	size_t s_idx;

	for (i = 0; i < size; i++)
	{
		s_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[s_idx])
			{
				s_idx = j;
			}
		}
		if (s_idx != i)
		{
			smallest = array[i];
			array[i] = array[s_idx];
			array[s_idx] = smallest;
			print_array(array, size);
		}
	}
}

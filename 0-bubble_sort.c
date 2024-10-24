#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int s_flag;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		s_flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
				s_flag = 1;
			}
		}
		if (!s_flag)
		{
			break;
		}
	}
}

#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: The number of elements in @array
 */

void heap_sort(int *array, size_t size)
{
	size_t i;
	size_t l_node_end;

	if (array == NULL || size < 2)
		return;
	l_node_end = (size / 2) - 1;
	for (i = l_node_end; i < size; i--)
	{
		heapify(array, size, size, i);
	}
	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}

/**
 * heapify - Heapifies an array of integers
 *
 * @array: The array to be sorted
 * @size: The number of elements in @array
 * @index: Last index of array
 * @root: Root of heap binary tree
 */

void heapify(int *array, size_t size, size_t index, size_t root)
{
	size_t parent;
	size_t l_child;
	size_t r_child;

	parent = root;
	l_child = 2 * root + 1;
	r_child = 2 * root + 2;

	if (l_child < index && array[l_child] > array[parent])
	{
		parent = l_child;
	}
	if (r_child < index && array[r_child] > array[parent])
	{
		parent = r_child;
	}
	if (parent != root)
	{
		swap(array + root, array + parent);
		print_array(array, size);
		heapify(array, size, index, parent);
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

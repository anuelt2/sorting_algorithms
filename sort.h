#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void sort_function(int *array, size_t size, int *o_array, size_t o_size);
void swap_array(int *array, int x, int y);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void list_node_swap(listint_t **head, listint_t *f_temp, listint_t *b_temp);
void counting_sort(int *array, size_t size);
void merge_array(int *array, size_t l_bound, size_t u_bound, size_t mid);
void merge_recursive(int *array, size_t l_bound, size_t u_bound);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t index, size_t root);

#endif

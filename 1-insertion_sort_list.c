#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	listint_t *tmp;
	listint_t *order;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	node = (*list)->next;
	while (node != NULL)
	{
		tmp = node->next;
		order = node->prev;
		while (order != NULL && order->n > node->n)
		{
			if (order->prev != NULL)
			{
				order->prev->next = node;
			}
			else
			{
				*list  = node;
			}
			if (node->next != NULL)
			{
				node->next->prev = order;
			}
			order->next = node->next;
			node->prev = order->prev;
			node->next = order;
			order->prev = node;
			print_list(*list);
			order = node->prev;
		}
		node = tmp;
	}
}

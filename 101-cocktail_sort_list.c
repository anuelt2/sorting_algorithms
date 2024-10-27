#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: The list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *f_temp;
	listint_t *b_temp;
	int s_flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	s_flag = 1;
	while (s_flag)
	{
		s_flag = 0;
		f_temp = *list;
		while (f_temp->next != NULL)
		{
			if (f_temp->n > f_temp->next->n)
			{
				list_node_swap(list, f_temp, f_temp->next);
				print_list(*list);
				s_flag = 1;
			}
			else
				f_temp = f_temp->next;
		}
		if (!s_flag)
		{
			break;
		}
		s_flag = 0;
		b_temp = f_temp->prev;
		while (b_temp != NULL && b_temp->prev != NULL)
		{
			if (b_temp->n < b_temp->prev->n)
			{
				list_node_swap(list, b_temp->prev, b_temp);
				print_list(*list);
				s_flag = 1;
			}
			else
				b_temp = b_temp->prev;
		}
	}
}

/**
 * list_node_swap - Swaps two nodes in a doubly linked list
 *
 * @head: Pointer to the pointer to the head of the linked list
 * @f_temp: Pointer to first node to swap
 * @b_temp: Pointer to second node to swap
 */

void list_node_swap(listint_t **head, listint_t *f_temp, listint_t *b_temp)
{
	if (f_temp->prev != NULL)
	{
		f_temp->prev->next = b_temp;
	}
	else
	{
		*head = b_temp;
	}
	if (b_temp->next != NULL)
	{
		b_temp->next->prev = f_temp;
	}
	f_temp->next = b_temp->next;
	b_temp->prev = f_temp->prev;
	b_temp->next = f_temp;
	f_temp->prev = b_temp;
}

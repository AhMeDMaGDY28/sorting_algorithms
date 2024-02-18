#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 *
 * This function sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm.
 * It iterates through the list, comparing each element with
 * the elements before it, and inserting it in the correct
 * position. It updates the head of the list if necessary.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		prev = curr->prev;
		while (prev != NULL && prev->n > curr->n)
		{
			tmp = curr->next;
			if (tmp != NULL)
				tmp->prev = prev;
			if (prev->prev != NULL)
				prev->prev->next = curr;
			else
				*list = curr;
			curr->next = prev;
			curr->prev = prev->prev;
			prev->next = tmp;
			prev->prev = curr;
			prev = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}

#include "sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list and prints the list.
 * @list: A pointer to a pointer to the head of the list.
 * @left: The left node to be swapped.
 * @right: The right node to be swapped.
 *
 * This function swaps two nodes in a
 * doubly linked list and prints the list after the swap.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *tmp_node = right->next;

	left = right->prev;
	right->prev = left->prev;
	right->next = left;
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	left->prev = right;
	left->next = tmp_node;
	if (tmp_node)
		tmp_node->prev = left;
	print_list(*list);
}
/**
 * cocktail_sort_list_core - Performs the core
 * logic of cocktail sort on a doubly linked list.
 * @list: A pointer to a pointer to the head of the list.
 * @head: The head of the list.
 * @cur_node: The current node being examined.
 * @tail: The tail of the list.
 *
 * This function performs the core
 * logic of cocktail sort on a doubly linked list.
 * It iterates over the list from both ends,
 *  swapping adjacent elements if they are in the wrong order,
 * until the list is sorted.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void cocktail_sort_list_core(listint_t **list, listint_t *head,
					    listint_t *cur_node, listint_t *tail)
{
	int notSorted = 1;

	while (notSorted)
	{
		notSorted = 0, cur_node = head;
		while (cur_node != tail)
		{
			if (cur_node->n > cur_node->next->n)
			{
				if (cur_node->next == tail)
					tail = cur_node;
				if (cur_node == head)
					head = cur_node->next;
				swap_nodes(list, cur_node, cur_node->next), notSorted = 1;
				continue;
			}
			cur_node = cur_node->next;
		}
		while (cur_node != head)
		{
			if (cur_node->prev->n > cur_node->n)
			{
				if (cur_node->prev == head)
					head = cur_node;
				if (cur_node == tail)
					tail = cur_node->prev;
				swap_nodes(list, cur_node->prev, cur_node), notSorted = 1;
				continue;
			}
			cur_node = cur_node->prev;
		}
		if (head->next == tail)
			break;
		tail = tail->prev, head = head->next;
	}
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the cocktail sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 *
 * This function sorts a doubly linked list of integers in ascending order
 *  using the cocktail sort algorithm.
 * It calls the cocktail_sort_list_core function to perform the sorting.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = NULL, *cur_node = NULL, *tail = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	head = cur_node = *list;
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	cocktail_sort_list_core(list, head, cur_node, tail);
}

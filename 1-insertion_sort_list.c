#include "sort.h"

/**
 * swap - function that swaps two doubly linked list
 * @list: list to be sorted
 * @left: left list
 * @right: right list
 * Return: void
 */
void swap(listint_t **list, listint_t *left, listint_t *right)
{
	left->next = right->next;
	if (right->next != NULL)
		right->next->prev = left;
	right->prev = left->prev;
	right->next = left;
	if (left->prev != NULL)
		left->prev->next = right;
	else
		*list = right;
	left->prev = right;
	left = right->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *next;


	node = malloc(sizeof(listint_t));
	next = malloc(sizeof(listint_t));
	if (list == NULL || node == NULL || next == NULL)
		return;
	node = *list;
	node = node->next;
	while (node)
	{
		next = node->prev;
		if (next->n > node->n)
		{
			swap(list, next, node);
			print_list(*list);
			node = (*list)->next;
		}
		else
			node = node->next;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_next - swaps
 *
 * @list: pointer to head
 * @node: swap
 */

void swap_next(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * listint_len - length of linked list
 *
 * @h: head node
 *
 * Return: size of list
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}

/**
 * cocktail_sort_list - sorts list
 *
 * @list: the dll to sort
 */

void cocktail_sort_list(listint_t **list)
{
	int s = 1, low = 0, hih, i = 0;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next || listint_len(*list) < 2)
		return;
	temp = *list;
	hih = (listint_len(*list) - 1);
	while (s)
	{
		s = 0;
		for (; i < hih; i++)
		{
			if (temp->next->n < temp->n)
			{
				swap_next(list, temp);
				s = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (!s)
			break;
		s = 0;
		for (; i > low; i--)
		{
			if (temp->prev->n > temp->n)
			{
				swap_next(list, temp->prev);
				s = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
		hih -= 1;
		low += 1;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a LL
 *
 * @list: head of a list address
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list == NULL || *list == NULL)
		return;

	i = (*list)->next;

	while (i != NULL)
	{
		j = i->next;
		while (i->prev != NULL && i->prev->n > i->n)
		{
			i->prev->next = i->next;

			if (i->next)
				i->next->prev = i->prev;

			i->next = i->prev;
			i->prev = i->next->prev;
			i->next->prev = i;

			if (!i->prev)
				*list = i;
			else
				i->prev->next = i;
			print_list(*list);
		}
		i = j;
	}
}

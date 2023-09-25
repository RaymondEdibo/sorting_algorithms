#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "deck.h"

/**
 * swap_next - swap
 *
 * @deck: address
 * @node: swap
 */

void swap_next(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*deck = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * deck_len - card deck
 *
 * @h: head node
 *
 * Return: size of the deck
 */

size_t deck_len(const deck_node_t *h)
{
	size_t ct = 0;

	while (h != NULL)
	{
		ct++;
		h = h->next;
	}

	return (ct);
}

/**
 * card_to_int - card
 *
 * @node: card node
 *
 * Return: card id
 */

int card_to_int(deck_node_t *node)
{
	int j;
	char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (j = 0; j < 13; j++)
	{
		if (!strcmp(node->card->value, values[j]))
			return (j + (13 * node->card->kind));
	}

	printf("Uh-oh. Card is out of range. I'm gonna crash now.");
	exit(EXIT_FAILURE);
}

/**
 * sort_deck - sorts
 *
 * @deck: card deck
 */

void sort_deck(deck_node_t **deck)
{
	int s = 1, a, b;
	size_t low = 0, hih = (deck_len(*deck) - 1), i = 0;
	deck_node_t *temp = *deck;

	if (!deck || !(*deck) || !((*deck)->next))
		return;
	while (s)
	{
		s = 0;
		for (; i < hih; i++)
		{
			a = card_to_int(temp);
			b = card_to_int(temp->next);
			if (b < a)
			{
				swap_next(deck, temp);
				s = 1;
			}
			else
				temp = temp->next;
		}
		if (!s)
			break;
		s = 0;
		for (; i > low; i--)
		{
			a = card_to_int(temp);
			b = card_to_int(temp->prev);
			if (b > a)
			{
				swap_next(deck, temp->prev);
				s = 1;
			}
			else
				temp = temp->prev;
		}
		hih -= 1;
		low += 1;
	}
}

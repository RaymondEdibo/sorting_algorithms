#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * enum kind_e - enum of the 4 card colors
 *
 * @SPADE: value 0
 * @HEART: value 1
 * @CLUB: value 2
 * @DIAMOND: value 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: card Value
 * From "Ace" to "King"
 * @kind: Kind
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck
 *
 * @card: card of node
 * @prev: previous node
 * @next: next node
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void print_deck(const deck_node_t *deck);
void sort_deck(deck_node_t **deck);

#endif

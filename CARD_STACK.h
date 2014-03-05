#ifndef CSET
#define CSET

#include "Card.h"

#define NONE NULL

/******************************************************************************\
 * Klondike Solitaire Solver
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 * CardStack handles the head and tails of a linked list that represents a stack
 * of cards.
 ******************************************************************************/

typedef struct node *link;
struct node
{
  Card card;
  link next;
  link prev;
};

typedef struct doubly_linked *CardStack;
struct doubly_linked
{
  link HEAD;
  link TAIL;
};

CardStack new_stack();
void push (CardStack, Card);
Card pop (CardStack);

#endif

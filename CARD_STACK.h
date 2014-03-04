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
 * CardStack is a handler to a linked list that represents a stack of cards.
 ******************************************************************************/

typedef struct node *link;
struct node
{
  Card card;
  link next;
};
typedef link *CardStack;

CardStack new_stack();
void push (CardStack, Card);
Card pop (CardStack);

#endif

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
 * Stack implemented as linked list to represent a set of cards and its position
 * (if it is face up or not).
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

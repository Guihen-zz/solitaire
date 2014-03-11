#ifndef CSET
#define CSET

#include <stdbool.h>
#include "CARD.h"

#define NONE NULL
#define Node link

/******************************************************************************\
 * Klondike Solitaire Solver
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 * CardStack handles the head and tails of a linked list that represents a stack
 * of cards. Node is a alias os link type for the client.
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

void push_stack (CardStack, CardStack);
CardStack pop_stack (CardStack, Node);

bool empty (CardStack);

Node get_last_node (CardStack);
Node get_first_node (CardStack);
Node previous_node (Node);
Node next_node (Node);

Card get_card (Node);

#endif

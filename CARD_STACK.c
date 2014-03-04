#include <stdlib.h>
#include "CARD_STACK.h"

CardStack new_stack()
{
  CardStack stack = malloc (sizeof (CardStack));
  link null_link = malloc (sizeof (link));
  
  null_link->card = NONE;
  null_link->next = NULL;
  *stack = null_link;

  return stack;
}

void push (CardStack stack, Card card)
{
  link new_node = malloc (sizeof (link));

  new_node->card = card;
  new_node->next = *stack;
  *stack = new_node;
}

Card pop (CardStack stack)
{
  link node_to_delete = (*stack);
  Card card = node_to_delete->card;
  *stack = node_to_delete->next;
  free (node_to_delete);
  return card;
}

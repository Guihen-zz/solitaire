#include <stdlib.h>
#include "CARD_STACK.h"

CardStack new_stack()
{
  CardStack stack = malloc (sizeof (CardStack));
  link tail_link = malloc (sizeof (link)),
    head_link = malloc (sizeof (link));
  
  tail_link->card = NONE;
  tail_link->next = NULL;
  tail_link->prev = head_link;

  head_link->card = NONE;
  head_link->next = tail_link;
  head_link->prev = NULL;

  stack->HEAD = head_link;
  stack->TAIL = tail_link;

  return stack;
}

void push (CardStack stack, Card card)
{
  link new_node = malloc (sizeof (link)),
    head_next = stack->HEAD->next;

  stack->HEAD->next = new_node;

  new_node->card = card;
  new_node->next = head_next;
  new_node->prev = stack->HEAD;
  
  head_next->prev = new_node;
}

Card pop (CardStack stack)
{
  Card card;
  link node_to_pop;
  if (stack->HEAD->next == stack->TAIL) return NONE;

  node_to_pop = stack->HEAD->next;
  card = node_to_pop->card;

  stack->HEAD->next = node_to_pop->next;
  node_to_pop->next->prev = stack->HEAD;
  free(node_to_pop);
  
  return card;
}

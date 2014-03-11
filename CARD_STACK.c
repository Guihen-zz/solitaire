#include <stdio.h>
#include <stdlib.h>
#include "CARD_STACK.h"

CardStack new_stack()
{
  CardStack stack = malloc (sizeof (*stack));
  link tail_link = malloc (sizeof (*tail_link)),
    head_link = malloc (sizeof (*head_link));
  
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
  link new_node = malloc (sizeof (*new_node)),
    head_next = stack->HEAD->next;

  stack->HEAD->next = new_node;
  new_node->card = card;

  new_node->next = head_next;
  new_node->prev = stack->HEAD;

  head_next->prev = new_node;
}

void push_stack (CardStack to, CardStack from)
{
  link head_next = to->HEAD->next;

  to->HEAD->next = from->HEAD->next;
  from->TAIL->prev->next = head_next;
  
  head_next->prev = from->TAIL->prev;
  from->HEAD->next->prev = to->HEAD;
  
  free (from);
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

CardStack pop_stack (CardStack stack, Node base)
{
  CardStack sub_stack;
  if (base == NONE) return NONE;

  sub_stack = new_stack();
  sub_stack->HEAD->next = stack->HEAD->next;
  sub_stack->TAIL->prev = base;
  
  stack->HEAD->next = base->next;
  base->next->prev = stack->HEAD;
  
  base->next = sub_stack->TAIL;
  sub_stack->HEAD->next->prev = sub_stack->HEAD;

  return sub_stack;
}


link get_last_node (CardStack stack)
{
  link node = stack->TAIL->prev;
  if (node->card == NONE) return NULL; /* It doesn't return the HEAD. */
  return node;
}

link get_first_node (CardStack stack)
{
  link node = stack->HEAD->next;
  if (node->card == NONE) return NULL; /* It doesn't return the TAIL. */
  return node;
}

link previous_node (link node)
{
  link prev = node->prev;
  if (prev->card == NONE) return NULL; /* It doesn't return the HEAD. */
  return prev;
}

link next_node (link node)
{
  link next = node->next;
  if (next->card == NONE) return NULL; /* It doesn't return the TAIL. */
  return next;
}

Card get_card (link node)
{
  return node->card;
}

bool empty (CardStack stack)
{
  return (stack->HEAD->next == stack->TAIL);
}

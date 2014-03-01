#include <stdlib.h>
#include <stdio.h>
#include "CARD_STACK.h"

CardStack new_stack()
{
  CardStack cs = malloc (sizeof(CardStack));
  link l = malloc (sizeof(link));

  l->card = NONE;
  l->next = NULL;
  cs = &l;
  return cs;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CARD.h"
#include "CARD_STACK.h"

#define DECKSIZE 48

Card *get_deck ()
{
  int deck_size = DECKSIZE;
  char *line = malloc (5);
  Card card;
  Card *deck = malloc(sizeof(Card) * DECKSIZE);

  while (deck_size) {
    card = malloc(sizeof(*card));
    fgets(line, 5, stdin); /* <Rank><space><Suit><enter>\0 */
    card->rank = line[0];
    card->suit = line[2];
    card->face_up = false;
    deck[--deck_size] = card;
  }
  return deck;
}

void show_deck (Card *deck)
{
  int i;
  for (i = 0; i < DECKSIZE; i++)
    printf ("%c %c\n", deck[i]->rank, deck[i]->suit);
}

CardStack *init_tableau_stacks()
{
  int i;
  CardStack *tableau_stacks = malloc (sizeof (CardStack) * 7);

  for (i = 0; i < 7; i++)
  {
    tableau_stacks[i] = new_stack();
  }
  return tableau_stacks;
}

CardStack* prepare_tableau_stacks (Card *deck)
{
  int i, j, deck_index = 0;
  CardStack *tableau_stacks = init_tableau_stacks ();

  for (i = 0; i < 7; i++)
    for (j = i; j < 7; j++)
    {
      push (tableau_stacks[j], deck[deck_index]);
      deck[deck_index] = NONE; /* Remove the card from deck */
      deck_index++;
    }

  for (i = 0; i < 7; i++)
    get_card (get_first_node (tableau_stacks[i]))->face_up = true;

  return tableau_stacks;
}

void print_tableau_stacks (CardStack *tableau_stacks)
{
  int i, j;
  Node node[7];
  Card card;
  bool exit_condition;

  for (i = 0; i < 7; i++)
    node[i] = get_last_node (tableau_stacks[i]);

  i = 0, exit_condition = false;
  while (!exit_condition)
  {
    if (i == 0) printf ("| ");

    if (node[i] != NULL)
    {
      card = get_card (node[i]);

      if (card->face_up)
        printf("  [%c%c]  ", card->rank, card->suit);
      else printf("  [??]  ");

      node[i] = previous_node (node[i]);
    }
    else printf("        ");

    if (++i == 7)
    {
      printf ("|\n");
      i = 0;
    }

    /* Exit Condition. */
    for (j = 0; j < 7; j++)
    {
      /* INVARIANT RELATION: all the nodes with index < j are null nodes. */
      if (node[j] != NULL) break;
    }
    if (j == 7) exit_condition = true;
  }
}

CardStack prepare_stock_stack (Card *deck)
{
  int i;
  CardStack stock = new_stack();
  for (i = DECKSIZE - 1; deck[i] != NONE; i--)
  {
    push (stock, deck[i]);
    deck[i] = NONE;
  }
  free(deck);
  return stock;
}

int main (void)
{
  Card *deck = get_deck();
  CardStack *tableau_stacks = prepare_tableau_stacks (deck);
  CardStack stock = prepare_stock_stack (deck);
  
  /* This panel contains 59 chars. */
  /* 24 spaces between the title and the form. */
  printf ("+---------------------------------------------------------+\n");
  printf ("|                        Solitaire                        |\n");
  printf ("+---------------------------------------------------------+\n");
  printf ("|  (TRY) [ %2d ]           [ %2d ]  [ %2d ]  [ %2d ]  [ %2d ]  |\n", 0, 1, 2, 3, 4);
  printf ("|                                                         |\n");
  printf ("|                                                         |\n");

  print_tableau_stacks (tableau_stacks);

  printf ("|_________________________________________________________|\n");
  printf (" Move description: \n");

  return 0;
}

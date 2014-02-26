#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CARD.h"

#define DECKSIZE 48

Card *get_deck ()
{
  int deck_size = DECKSIZE;
  char *line = malloc (5);
  Card card;
  Card *deck = malloc(sizeof(Card *) * DECKSIZE);
  
  while (deck_size) {
    card = malloc(sizeof(Card));
    fgets(line, 5, stdin); /* <Rank><space><Suit><enter>\0 */
    card->rank = line[0];
    card->suit = line[2];
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

int main (void) 
{
  Card *deck = get_deck();
  show_deck (deck); 
  
  /* This panel contains 59 chars. */
  /* 24 spaces between the title and the form. */
  printf ("+---------------------------------------------------------+\n");
  printf ("|                        Solitaire                        |\n");
  printf ("+---------------------------------------------------------+\n");
  printf ("|  (%2d) [ %2d ]             [ %2d ]  [ %2d ]  [ %2d ]  [ %2d ] |\n", 23, 0, 1, 2, 3, 4);
  printf ("|                                                         |\n");
  printf ("|                                                         |\n");
  printf ("|  [ %2d ]  [ %2d ]  [ %2d ]  [ %2d ]  [ %2d ]  [ %2d ]  [ %2d ] |\n", 1, 2, 3, 4, 5, 6, 7);
  printf ("|_________________________________________________________|\n");
  printf (" Move description: \n");
  
  return 0;
}

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
  Card *deck = malloc(sizeof(Card *) * DECKSIZE);
  
  while (deck_size) {
    card = malloc(sizeof(Card));
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
    if (deck[i]->face_up)
      printf ("%c %c\n", deck[i]->rank, deck[i]->suit);
}

CardStack *init_solitaire_template()
{
  int i;
  CardStack *template = malloc (sizeof (CardStack) * 7);
  
  for (i = 0; i < 7; i++)
  {
    template[i] = new_stack();
  }
  return template;
}

CardStack* prepare_solitaire(Card *deck)
{
  int i, j, deck_index = 0;
  CardStack *template = init_solitaire_template();

  for (i = 0; i < 7; i++)
    for (j = i; j < 7; j++)
      push (template[j], deck[deck_index++]);

  /* It should set face up the last cards in the stack. */
  return template;
}

void print(CardStack *solitaire)
{
  int i, j, deck_index = 0;
  for (i = 0; i < 7; i++)
  {
    printf ("| ");
    
    for (j = 0; j < 7; j++)
    {
      if (j >= i)
      {
        printf("  [XX]  ");
      }
      else printf("        ");
    }

    printf ("|\n");
  }
}

int main (void) 
{
  Card *deck = get_deck();
  CardStack *solitaire = prepare_solitaire (deck);
  
  /* This panel contains 59 chars. */
  /* 24 spaces between the title and the form. */
  printf ("+---------------------------------------------------------+\n");
  printf ("|                        Solitaire                        |\n");
  printf ("+---------------------------------------------------------+\n");
  printf ("|   (%2d) [ %2d ]           [ %2d ]  [ %2d ]  [ %2d ]  [ %2d ]  |\n", 23, 0, 1, 2, 3, 4);
  printf ("|                                                         |\n");
  printf ("|                                                         |\n");
  
  print (solitaire);

  printf ("|_________________________________________________________|\n");
  printf (" Move description: \n");
  
  return 0;
}

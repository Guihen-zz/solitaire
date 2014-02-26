#ifndef CARD
#define CARD

/******************************************************************************\
 * Klondike Solitaire Solver
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 * This file creates a representation of a card of the deck as a struct with 2
 * fields: Suit, that is an abstraction of the Suit (see SUIT.h) and a char that 
 * stores the rank of the deck (A, 2, 3, ..., J, Q, K).
 ******************************************************************************/

#include "SUIT.h"

struct card
{
  Suit suit;
  char rank;
};
typedef struct card *Card;

#endif

#ifndef CARD
#define CARD

/******************************************************************************\
 * Klondike Solitaire Solver
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 * This file creates a representation of a card of the deck as a struct with 2
 * fields: Suit, that is an abstraction of the Suit (see SUIT.h), a char that 
 * stores the rank of the deck (A, 2, 3, ..., J, Q, K) and a boolean to store if
 * it is face up or not.
 ******************************************************************************/

#include <stdbool.h>
#include "SUIT.h"

typedef char Rank;
struct card
{
  Suit suit;
  Rank rank;
  bool face_up;
};
typedef struct card *Card;
typedef Card* Deck;

#endif

#ifndef LLIST
#define LLIST

/******************************************************************************\
 * Klondike Solitaire Solver
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 * Linked list to represent a set of cards and its position (if it is face up or
 * not).
 ******************************************************************************/

typedef struct list *link;
struct list
{
  Card card;
  boolean face_up;
  link next;
};
typedef link List;

#endif

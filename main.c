#include <stdio.h>

int main (void) 
{
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

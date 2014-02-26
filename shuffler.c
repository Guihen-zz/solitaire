#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_SIZE 24
#define SWAP_PER_INPUT 3

void shuffle (char **inputs, int number_of_inputs)
{
  char *s;
  int swaps, i = 0, j;
  srand(time(NULL));
  
  for (swaps = number_of_inputs * SWAP_PER_INPUT; swaps > 0; swaps--)
  {
    s = inputs[i];
    j = rand() % number_of_inputs;
    inputs[i] = inputs[j];
    inputs[j] = s;
    i = i < number_of_inputs - 1 ? i + 1 : 0;
  }
  
  for (i = 0; i < number_of_inputs; i++)
    printf("%s", inputs[i]);
}

int main (int argc, char *argv[])
{
  int number_of_inputs, i;
  char **inputs_to_shuffle;
  char *line;

  if (argc < 2)
  {
    fprintf(stderr, "Missing arguments");
    return 1;
  }
  
  i = number_of_inputs = atoi(argv[1]);
  inputs_to_shuffle = malloc (sizeof(char *) * number_of_inputs);
  while (i)
  {
    line = malloc(MAX_LINE_SIZE);
    fgets(line, MAX_LINE_SIZE, stdin);
    inputs_to_shuffle[--i] = line;
  }

  shuffle(inputs_to_shuffle, number_of_inputs);

  return 0;
}


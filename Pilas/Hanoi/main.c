// Local headers
#include <lib/util.h>
#include "Hanoi.h"

// Standar headers
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  srand (time (NULL));
  printf ("Hanoi tester\n");

  printf ("\nHanoi.h - Init\n");
  int size = 0;
  printf ("Insert hanoi size: ");
  scanf ("%i", &size);
  println;
  Hanoi_t *hanoi = newHanoi (size);
  printHanoi (hanoi);
  println;

  printf ("\nHanoi.h - Solving hanoi\n");
  solveHanoi (hanoi);

  printf ("\nPileArray.h - Destroy\n");
  hanoi = destroyHanoi (hanoi);
  printHanoi (hanoi);
  println;
}

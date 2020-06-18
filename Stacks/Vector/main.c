// Local headers
#include <lib/util.h>
#include <Vectors/Vector/Int/Vector.h>
#include "StackVector.h"

// Standar headers
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  srand (time (NULL));
  printf ("Stack vector tester\n");

  printf ("\nStackVector.h - Init\n");
  Vector_t *stack = newVector (randomInRange (1, 10));
  printVector (stack);
  println;

  printf ("\nStackVector.h - Push\n");
  for (size_t i = 0; i < randomInRange (1, 10); i++)
    stack = stackVectorPush (stack, randomInRange (-100, 100));
  printVector (stack);
  println;

  printf ("\nStackVector.h - Pop\n");
  for (size_t i = 0; i < randomInRange (1, 10); i++)
    printf ("[%i]", stackVectorPop (&stack));
  println;
  printVector (stack);
  println;

  printf ("\nStackVector.h - Destroy\n");
  stack = destroyVector (stack);
  printVector (stack);
  println;
}

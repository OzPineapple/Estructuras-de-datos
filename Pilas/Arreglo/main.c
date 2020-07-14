// Local headers
#include <lib/util.h>
#include "StackArray.h"

// Standar headers
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  srand (time (NULL));
  printf ("StackArray tester\n");

  printf ("\nStackArray.h - Init\n");
  StackArray_t *stack_array = 0x0;
  initStackArrayPointer (&stack_array, randomInRange (1, 5));

  printf ("\nStackArray.h - Print\n");
  printStackArray (stack_array);

  printf ("\nStackArray.h - Push\n");
  for (size_t index = 0; index < 4; index++)
    stackArrayPush (stack_array, randomInRange (-100, 100));
  printStackArray (stack_array);

  printf ("\nStackArray.h - Pop\n");
  for (size_t index = 0; index < 4; index++)
    printf ("[%i]", stackArrayPop (stack_array));
  printf ("\n");
  printStackArray (stack_array);

  printf ("\nStackArray.h - Write\n");
  for (size_t index = 0; index < 7; index++)
    writeOnStackArray (stack_array,
		       randomInRange (0, stack_array->length - 1),
		       randomInRange (-100, 100));
  printStackArray (stack_array);

  printf ("\nStackArray.h - Read\n");
  for (size_t index = 0; index < 7; index++)
    printf ("[%i]",
	    readOnStackArray (stack_array,
			      randomInRange (0, stack_array->length - 1)));
  printf ("\n");
  printStackArray (stack_array);

  printf ("\nStackArray.h - Destroy\n");
  destroyStackArray (&stack_array);
  printStackArray (stack_array);
}

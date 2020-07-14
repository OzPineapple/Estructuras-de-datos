// Local headers
#include <lib/validate.h>
#include <lib/util.h>
#include "StackList.h"

// Standar headers
#include <time.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
  srand (time (NULL));
  printf ("StackList tester\n");

  printf ("\nStackList.h - Init\n");
  StackList_t *stack_list = 0x0;
  initStackListPointer (&stack_list, randomInRange (1, 3));

  printf ("\nStackList.h - Print\n");
  printStackList (stack_list);

  printf ("\nStackList.h - Push\n");
  for (size_t index = 0; index < 4; index++)
    stackListPush (stack_list, randomInRange (-100, 100));
  printStackList (stack_list);

  printf ("\nStackList.h - Pop\n");
  for (size_t index = 0; index < 4; index++)
    printf ("[%i]", stackListPop (stack_list));
  printf ("\n");
  printStackList (stack_list);

  printf ("\nStackList.h - Write\n");
  for (size_t index = 0; index < 7; index++)
    writeOnStackList (stack_list, randomInRange (0, stack_list->length - 1),
		      randomInRange (-100, 100));
  printStackList (stack_list);

  printf ("\nStackList.h - Read\n");
  for (size_t index = 0; index < 7; index++)
    printf ("[%i]",
	    readOnStackList (stack_list,
			     randomInRange (0, stack_list->length - 1)));
  printf ("\n");
  printStackList (stack_list);

  printf ("\nStackList.h - Destroy\n");
  destroyStackList (&stack_list);
  printStackList (stack_list);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <lib/util.h>
#include <Lists/Generic/Node.h>
#include "ListCyclic.h"

int
main (int argc, char *argv[])
{

  printf ("ListCyclic.h - Init\n");

  srand (time (NULL));
  Node_t *list_cyclic = 0x0;

  initListCyclicPointer (&list_cyclic, randomInRange (1, 7));

  printListCyclic (list_cyclic);

  printf ("\nListCyclic.h - Insert\n");

  Node_t *front = 0x0;

  initNodePointer (&front, 5, 2);

  printNode (front);

  listCyclicInsert (&list_cyclic, front);

  printListCyclic (list_cyclic);

  front = 0x0;

  front = popFirstNodeOnListCyclicNlink (&list_cyclic);

  destroyNode (front);

  printListCyclic (list_cyclic);

  printf ("\nListCyclic.h - Append\n");

  Node_t *last = 0x0;

  initNodePointer (&last, 15, 2);

  printNode (last);

  listCyclicAppend (list_cyclic, last);

  printListCyclic (list_cyclic);

  last = 0x0;

  last = popLastNodeOnListCyclicNlink (list_cyclic);

  destroyNode (last);

  printListCyclic (list_cyclic);

  printf ("\nListCyclic.h - Get\n");

  printListCyclic (list_cyclic);

  printNode (getNextNodeOnListCyclic (list_cyclic));

  printNode (getNodeOnListCyclic
	     (list_cyclic,
	      randomInRange (0, lengthOfListCyclic (list_cyclic) - 1)));

  printf ("\nListCyclic.h - Write\n");

  for (size_t i = 0; i < 10; i++)
    writeOnListCyclic (list_cyclic,
		       randomInRange (0,
				      lengthOfListCyclic (list_cyclic) - 1),
		       randomInRange (-100, 100));

  printListCyclic (list_cyclic);

  printf ("\nListCyclic.h - Read\n");

  for (size_t i = 0; i < 10; i++)
    printf ("%i ",
	    readOnListCyclic (list_cyclic,
			      randomInRange (0,
					     lengthOfListCyclic (list_cyclic)
					     - 1)));
  printf ("\n");

  printf ("\nListCyclic.h - Delete\n");

  for (size_t i = 0; i < 10; i++)
    deleteOnListCyclic (list_cyclic,
			randomInRange (0,
				       lengthOfListCyclic (list_cyclic) - 1));

  printListCyclic (list_cyclic);

  printf ("\nListCyclic.h - Destroy\n");

  printListCyclic (list_cyclic);
  if (list_cyclic != 0x0)
    destroyNodeOnListCyclicNlink (&list_cyclic, 0);
  printListCyclic (list_cyclic);
  if (list_cyclic != 0x0)
    destroyNodeOnListCyclicNlink (&list_cyclic,
				  lengthOfListCyclic (list_cyclic) - 1);
  printListCyclic (list_cyclic);
  if (list_cyclic != 0x0)
    destroyNodeOnListCyclicNlink (&list_cyclic,
				  randomInRange (0,
						 lengthOfListCyclic
						 (list_cyclic) - 1));
  printListCyclic (list_cyclic);

  destroyListCyclic (list_cyclic);

  list_cyclic = 0x0;

  printListCyclic (list_cyclic);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <lib/util.h>
#include "Node.h"
#include "List.h"

int
main (void)
{
  srand (time (NULL));
  printf ("\nTest Node.h funtions\n");
  Node_t *node = 0x0;
  initNodePointer (&node, randomInRange (-100, 100), randomInRange (1, 20));
  printNode (node);
  changeNodeValue (node, randomInRange (-100, 100));
  printNode (node);
  deleteNodeValue (node);
  printNode (node);
  Node_t *node_1 = 0x0;
  initNodePointer (&node_1, randomInRange (-100, 100), randomInRange (1, 20));
  printNode (node_1);
  Node_t *node_2 = 0x0;
  initNodePointer (&node_2, randomInRange (-100, 100), randomInRange (1, 20));
  printNode (node_2);
  writeOnNodeWay (node, randomInRange (0, node->length - 1), node_1);
  printNode (node);
  writeOnNodeWay (node, randomInRange (0, node->length - 1), node_2);
  printNode (node);
  for (int i = 0; i < 3; i++)
    {
      resizeNodeWay (node, randomInRange (1, 20));
      printNode (node);
    }

  printf ("\nTest List.h funtions\n");

  linkNode (0, node_1, node_2);
  printNodes (2, node_1, node_2);

  linkNodes (0, 3, node, node_1, node_2);
  printNodes (3, node, node_1, node_2);

  printList (0, node);

  linkNode (0, node_2, node);
  printList (0, node);

  unlinkNode (0, node);
  unlinkNode (0, node_1);
  unlinkNode (0, node_2);

  printList (0, node);
  printList (0, node_1);
  printList (0, node_2);

  Node_t *list = newList (randomInRange (1, 10), randomInRange (1, 5));
  printList (0, list);

  printf ("\nList - insert append\n");
  listInsert (0, &list, node_1);
  listAppend (0, list, node_2);
  printList (0, list);

  printf ("\nList - pop\n");
  printList (0, list);
  Node_t *popped_first = popFirstNodeOnListNlink (0, &list);
  printNode (node_1);
  printNode (popped_first);

  printList (0, list);
  Node_t *popped_last = popLastNodeOnListNlink (0, list);
  printNode (node_2);
  printNode (popped_last);

  printf ("\nDestroy nodes\n");
  destroyNode (node);
  destroyNode (node_1);
  destroyNode (node_2);

  node = 0x0;
  node_1 = 0x0;
  node_2 = 0x0;
  popped_first = 0x0;
  popped_last = 0x0;

  printf ("\nList - listpp\n");
  printList (0, list);
  for (size_t index = 0; index < 3; index += 1)
    {
      if (list == 0x0)
	{
	  printf
	    (" [ N ] → [ 0x0 ]  The list arrives on 0x0, the program gona fail, don't worry just re-run\n");
	}
      listpp (0, &list);
      printList (0, list);
    }

  printf ("\nList - write ramdomly\n");
  printList (0, list);
  if (list != 0x0)
    for (size_t index = 0; index < 3; index += 1)
      {
	writeOnList (0, list, randomInRange (0, lengthOfList (0, list) - 1),
		     randomInRange (-100, 100));
      }
  printList (0, list);

  printf ("\nList - read randomly\n");
  for (size_t index = 0; index < 3; index += 1)
    {
      printf ("[%i]",
	      readOnList (0, list,
			  randomInRange (0, lengthOfList (0, list) - 1)));
    }
  printf ("\n");

  printf ("\nList.h - Cut List\n");

  printList (0, list);

  Node_t *list_1 =
    cutList (0, list, randomInRange (0, lengthOfList (0, list) - 1));

  printList (0, list);
  printList (0, list_1);

  printf ("Destroy list_1\n");
  if (list_1 != list)
    {
      printList (0, list_1);
      destroyList (0, list_1);
    }

  printf ("\nList.h - getNextNodeOnList\n");
  printList (0, list);
  Node_t *next = list;

  while (next != 0x0)
    {
      printNode (next);
      next = getNextNodeOnList (0, next);
    }

  printf ("\nList.h - Destroy node\n");

  printf ("Destroy node - first node\n");
  printList (0, list);
  if (list != 0x0)
    destroyNodeOnListNlink (0, &list, 0);
  printList (0, list);

  printf ("Destroy node - last node\n");
  printList (0, list);
  if (list != 0x0)
    destroyNodeOnListNlink (0, &list, lengthOfList (0, list) - 1);
  printList (0, list);

  printf ("Destroy node - random node\n");
  printList (0, list);
  if (list != 0x0)
    destroyNodeOnListNlink (0, &list,
			    randomInRange (0, lengthOfList (0, list) - 1));
  printList (0, list);

  printf ("\nList.h - Destroy list\n");

  printf ("Destroy list\n");
  printList (0, list);
  destroyList (0, list);


}

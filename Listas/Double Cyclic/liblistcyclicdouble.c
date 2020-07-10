/* Local proyect headers */
#include <lib/validate.h>
#include <Lists/Generic/List.h>

void
initListCyclicDoublePointer (Node_t * *list, size_t size)
{
  valSize (size);
  *list = newList (size, 2);
  valMem (*list);
  Node_t *last = getLastNodeOnList (0, *list);

  Node_t *behind = 0x0;
  Node_t *front = *list;

  while (front != 0x0)
    {
      linkNode (1, front, behind);
      behind = front;
      listpp (0, &front);
    }

  linkNode (0, last, *list);
  linkNode (1, *list, last);
}

void
destroyListCyclicDouble (Node_t * list)
{
  destroyList (0, list);
}

void
listCyclicDoublepp (Node_t * *list)
{
  listpp (0, list);
}

int
lengthOfListCyclicDouble (Node_t * list)
{
  return lengthOfList (0, list);
}

// Lookers  

void
printListCyclicDouble (Node_t * list)
{
  if (list == 0x0)
    {
      printf ("{(nil)}\n");
      return;
    }
  Node_t *last = getLastNodeOnList (0, list);
  printList (0, list);
  printList (1, last);
}

int
readOnListCyclicDouble (Node_t * list, int pos)
{
  return readOnList (0, list, pos);
}

// Modifiers

void
listCyclicDoubleInsert (Node_t * *list, Node_t * node)
{
  val2Ptr ((void **) list);
  valPtr (node);
  Node_t *last = getLastNodeOnList (0, *list);
  linkNode (1, *list, node);
  linkNode (0, last, node);
  linkNode (0, node, *list);
  linkNode (1, node, last);
  *list = node;
}

void
listCyclicDoubleAppend (Node_t * list, Node_t * node)
{
  valPtr (list);
  valPtr (node);
  Node_t *last = getLastNodeOnList (0, list);
  linkNode (1, list, node);
  linkNode (0, last, node);
  linkNode (0, node, list);
  linkNode (1, node, last);
}

void
writeOnListCyclicDouble (Node_t * list, int pos, int val)
{
  writeOnList (0, list, pos, val);
}

void
deleteOnListCyclicDouble (Node_t * list, int pos)
{
  deleteOnList (0, list, pos);
}

// Getters

Node_t *
getNextNodeOnListCyclicDouble (Node_t * list)
{
  return getNextNodeOnList (0, list);
}

Node_t *
getNodeOnListCyclicDouble (Node_t * list, int pos)
{
  return getNodeOnList (0, list, pos);
}

// Poppers

Node_t *
popFirstNodeOnListCyclicDoubleNlink (Node_t * *list)
{
  val2Ptr ((void **) list);
  Node_t *first = *list;
  Node_t *last = getLastNodeOnList (0, first);
  Node_t *next = getNextNodeOnList (0, first);
  unlinkNode (0, first);
  unlinkNode (1, first);
  linkNode (0, last, next);
  linkNode (1, next, last);
  *list = next;
  return first;
}


Node_t *
popLastNodeOnListCyclicDoubleNlink (Node_t * list)
{
  Node_t *last = getLastNodeOnList (0, list);
  Node_t *prelast = getNextNodeOnList (1, last);
  unlinkNode (0, last);
  unlinkNode (1, last);
  linkNode (0, prelast, list);
  linkNode (1, list, prelast);
  return last;
}

Node_t *
popNodeOnListCyclicDoubleNlink (Node_t * *list, size_t pos)
{
  val2Ptr ((void **) list);
  valNeg (pos);

  if (pos == 0)
    return popFirstNodeOnListCyclicDoubleNlink (list);
  if (pos == lengthOfList (0, *list) - 1)
    return popLastNodeOnListCyclicDoubleNlink (*list);
  Node_t *node = getNodeOnList (0, *list, pos);
  Node_t *front = *(node->way + 0);
  Node_t *behind = *(node->way + 1);
  unlinkNode (0, node);
  unlinkNode (1, node);
  linkNode (1, front, behind);
  linkNode (0, behind, front);
  return popNodeOnListNlink (0, list, pos);
}

// Destroy

void
destroyNodeOnListCyclicDoubleNlink (Node_t * *list, size_t pos)
{
  valPtr (list);
  if (*list == 0x0)
    return;
  valNeg (pos);
  valSizePos (lengthOfList (0, *list), pos);
  if (lengthOfList (0, *list) == 1)
    {
      destroyNode (*list);
      *list = 0x0;
      return;
    }
  destroyNode (popNodeOnListCyclicDoubleNlink (list, pos));
}

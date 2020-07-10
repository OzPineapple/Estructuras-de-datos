/* Local proyect headers */
#include "ListCyclic.h"
#include <lib/validate.h>
#include <Lists/Generic/List.h>

void
initListCyclicPointer (Node_t * *list, size_t size)
{
  valSize (size);
  *list = newList (size, 1);
  valMem (*list);
  Node_t *last = getLastNodeOnList (0, *list);
  linkNode (0, last, *list);
}

void
destroyListCyclic (Node_t * list)
{
  return destroyList (0, list);
}

void
listCyclicpp (Node_t * *list)
{
  listpp (0, list);
}

int
lengthOfListCyclic (Node_t * list)
{
  return lengthOfList (0, list);
}

// Lookers  

void
printListCyclic (Node_t * list)
{
  printList (0, list);
}

int
readOnListCyclic (Node_t * list, int pos)
{
  return readOnList (0, list, pos);
}

// Modifiers

void
listCyclicInsert (Node_t * *list, Node_t * node)
{
  val2Ptr ((void **) list);
  valPtr (node);
  Node_t *last = getLastNodeOnList (0, *list);

  listInsert (0, list, node);
  linkNode (0, last, *list);
}

void
listCyclicAppend (Node_t * list, Node_t * node)
{
  valPtr (list);
  valPtr (node);
  Node_t *prelast = getLastNodeOnList (0, list);
  listAppend (0, list, node);
  linkNode (0, prelast, node);
  linkNode (0, node, list);
}

void
writeOnListCyclic (Node_t * list, int pos, int val)
{
  writeOnList (0, list, pos, val);
}

void
deleteOnListCyclic (Node_t * list, int pos)
{
  deleteOnList (0, list, pos);
}

// Getters

Node_t *
getNextNodeOnListCyclic (Node_t * list)
{
  return getNextNodeOnList (0, list);
}

Node_t *
getNodeOnListCyclic (Node_t * list, int pos)
{
  return getNodeOnList (0, list, pos);
}

// Poppers

Node_t *
popFirstNodeOnListCyclicNlink (Node_t * *list)
{
  val2Ptr ((void **) list);
  Node_t *last = getLastNodeOnList (0, *list);
  Node_t *next = getNextNodeOnList (0, *list);
  linkNode (0, last, next);
  return popFirstNodeOnListNlink (0, list);
}

Node_t *
popNodeOnListCyclicNlink (Node_t * *list, size_t pos)
{
  val2Ptr ((void **) list);
  valNeg (pos);

  return popNodeOnListNlink (0, list, pos);
}

Node_t *
popLastNodeOnListCyclicNlink (Node_t * list)
{
  Node_t *last = getLastNodeOnList (0, list);
  Node_t *prelast = getLastNodeOnList (0, last);
  linkNode (0, prelast, list);
  unlinkNode (0, last);
  return last;
}

// Destroy

void
destroyNodeOnListCyclicNlink (Node_t * *list, size_t pos)
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

  Node_t *last = getLastNodeOnList (0, *list);

  destroyNodeOnListNlink (0, list, pos);

  if (pos == 0)
    {
      linkNode (0, last, *list);
    }

  if (last != getLastNodeOnList (0, *list))
    {
      linkNode (0, getLastNodeOnList (0, *list), *list);
    }
}

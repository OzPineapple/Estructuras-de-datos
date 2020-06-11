/* Local proyect headers */
#include <lib/validate.h>
#include "Node.h"

/* Standar headers */
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* Create  */

Node_t *
newList (size_t length, size_t ways)
{
  valSize (length);
  valSize (ways);

  Node_t *list = 0x0;
  initNodePointer (&list, 0, ways);
  Node_t *head = list;

  Node_t *node = 0x0;

  for (size_t count = 1; count < length; count += 1)
    {
      initNodePointer (&node, 0, ways);
      linkNode (0, list, node);
      list = node;
    }

  return head;
}

static void
destroyList_function_recursive (size_t way, Node_t * header, Node_t * list)
{

  valSizePos (list->length, way);

  Node_t *next = *(list->way + way);

  destroyNode (list);

  if (next == 0x0 || next == header)
    return;

  destroyList_function_recursive (way, header, next);
}

void
destroyList (size_t way, Node_t * list)
{

  if (list == 0x0)
    return;

  valNeg (way);

  destroyList_function_recursive (way, list, list);
}

void
listpp (size_t way, Node_t * *list)
{
  valNeg (way);
  val2Ptr ((void **) list);
  *(list) = *((*list)->way + way);
}

int
lengthOfList (size_t way, Node_t * list)
{
  valNeg (way);

  if (list == 0x0)
    return 0;

  valSizePos (list->length, way);

  Node_t *node = list;
  int count = 0;

  do
    {
      listpp (way, &node);
      count++;
    }
  while (node != 0x0 && node != list);

  return count;
}

/* Getters */

Node_t *
getNextNodeOnList (size_t way, Node_t * list)
{
  valNeg (way);
  valPtr (list);
  valSizePos (list->length, way);

  return *(list->way + way);
}

Node_t *
getNodeOnList (size_t way, Node_t * list, size_t pos)
{
  valNeg (way);
  valNeg (pos);
  valPtr (list);
  valSizePos (list->length, way);

  Node_t *node = list;
  for (size_t index = 0; index < pos && node != 0x0; index += 1)
    node = getNextNodeOnList (way, node);
  return node;
}

Node_t *
getLastNodeOnList (size_t way, Node_t * list)
{
  valNeg (way);
  valPtr (list);
  valSizePos (list->length, way);

  Node_t *node = list;

  while (getNextNodeOnList (way, node) != 0x0
	 && getNextNodeOnList (way, node) != list)
    {
      listpp (way, &node);
    }
  return node;
}


/* Poppers */

Node_t *
popFirstNodeOnListNlink (size_t way, Node_t * *list)
{
  valNeg (way);
  valPtr (list);
  valSizePos ((*list)->length, way);

  Node_t *popped = *list;
  listpp (way, list);
  unlinkNode (way, popped);
  return popped;
}

Node_t *
popLastNodeOnListNlink (size_t way, Node_t * list)
{
  valNeg (way);
  valPtr (list);
  valSizePos (list->length, way);
  Node_t *last = getLastNodeOnList (way, list);
  Node_t *node = list;

  while (getNextNodeOnList (way, node) != last)
    {
      listpp (way, &node);
    }

  unlinkNode (way, last);
  unlinkNode (way, node);
  return last;
}

Node_t *
popNodeOnListNlink (size_t way, Node_t * *list, size_t pos)
{
  valNeg (way);
  valNeg (pos);
  val2Ptr ((void **) list);
  valSizePos ((*list)->length, way);

  if (pos == 0)
    return popFirstNodeOnListNlink (way, list);
  Node_t *next = getNodeOnList (way, *list, pos + 1);
  if (next == 0x0 || next == *list)
    return popLastNodeOnListNlink (way, *list);

  Node_t *behind = getNodeOnList (way, *list, pos - 1);
  Node_t *middle = getNodeOnList (way, *list, pos);
  Node_t *front = getNodeOnList (way, *list, pos + 1);

  unlinkNode (way, middle);
  linkNode (way, behind, front);
  return middle;
}


/* Cutters  */

Node_t *
cutList (size_t way, Node_t * list, size_t pos)
{
  valNeg (way);
  valNeg (pos);
  valPtr (list);
  valSizePos (list->length, way);
  valSizePos (lengthOfList (way, list), pos);

  if (pos == 0)
    return list;
  if (getNextNodeOnList (way, list) == 0x0)
    return popLastNodeOnListNlink (way, list);
  Node_t *left = getNodeOnList (way, list, pos - 1);
  Node_t *rigth = getNodeOnList (way, list, pos);
  unlinkNode (way, left);
  return rigth;
}

/* Lookers  */

int
readOnList (size_t way, Node_t * list, size_t pos)
{
  valNeg (way);
  valNeg (pos);
  valPtr (list);
  valSizePos (list->length, way);
  valSizePos (lengthOfList (way, list), pos);
  Node_t *node = getNodeOnList (way, list, pos);
  return node->value;
}

void
printList (size_t way, Node_t * list)
{
  valNeg (way);
  if (list == 0x0)
    {
      printf ("{(nil)}\n");
      return;
    }
  valSizePos (list->length, way);
  Node_t *node = list;
  while (node != 0x0)
    {
      valSizePos (node->length, way);
      printf ("{ V:%i D:%p }→", node->value, node);
      node = *(node->way + way);
      if (node == list)
	{
	  printf ("{ ⥀ }\n");
	  return;
	}
    }
  printf ("{(nil)}\n");
}


/* Modifyers */

void
listInsert (size_t way, Node_t * *list, Node_t * node)
{
  valNeg (way);
  valPtr (list);
  valPtr (node);
  valSizePos ((*(list))->length, way);
  valSizePos (node->length, way);
  linkNode (way, node, *(list));
  *(list) = node;
}

void
listAppend (size_t way, Node_t * list, Node_t * node)
{
  valNeg (way);
  valPtr (list);
  valPtr (node);
  valSizePos (list->length, way);
  valSizePos (node->length, way);
  Node_t *list_last = getLastNodeOnList (way, list);
  linkNode (way, list_last, node);
}

void
writeOnList (size_t way, Node_t * list, size_t pos, int val)
{
  valNeg (way);
  valNeg (pos);
  valPtr (list);
  valSizePos (list->length, way);
  valSizePos (lengthOfList (way, list), pos);
  (getNodeOnList (way, list, pos))->value = val;
}

void
deleteOnList (size_t way, Node_t * list, size_t pos)
{
  valNeg (way);
  valNeg (pos);
  valPtr (list);
  valSizePos (list->length, way);
  valSizePos (lengthOfList (way, list), pos);
  writeOnList (way, list, pos, 0);
}

/* Destroy */

void
destroyNodeOnListNlink (size_t way, Node_t * *list, size_t pos)
{
  valNeg (way);
  valNeg (pos);
  val2Ptr ((void **) list);
  valSizePos ((*list)->length, way);
  valSizePos (lengthOfList (way, *list), pos);

  Node_t *breaked = popNodeOnListNlink (way, list, pos);
  destroyNode (breaked);
}

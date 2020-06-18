// Include local
#include <lib/validate.h>
#include <Lists/Simple/ListSimple.h>
#include <Lists/Generic/List.h>
#include "StackList.h"

// Include standar
#include <stddef.h>
#include <stdlib.h>
void
initStackList (StackList_t * stack, size_t length)
{
  valPtr (stack);
  valSize (length);
  stack->length = length;
  initListSimplePointer (&(stack->list), stack->length);
}

void
initStackListPointer (StackList_t * *stack, size_t length)
{
  valPtr (stack);
  valSize (length);
  *stack = (StackList_t *) calloc (1, sizeof (StackList_t));
  initStackList (*stack, length);
}

void
destroyStackList (StackList_t * *stack)
{
  valPtr (stack);
  if (*stack == 0x0)
    return;
  destroyListSimple ((*stack)->list);
  free (*stack);
  *stack = 0x0;
  return;
}

// Lookers

void
printStackList (StackList_t * stack)
{
  if (stack == 0x0)
    {
      printf ("{(nil)}\n");
      return;
    }
  printf ("Stack length: %i: ", (int) stack->length);
  printListSimple (stack->list);
}

int
readOnStackList (StackList_t * stack, size_t pos)
{
  valPtr (stack);
  valSizePos (stack->length, pos);
  return readOnListSimple (stack->list, pos);
}

// Modifiers

void
stackListPush (StackList_t * stack, int value)
{
  valPtr (stack);
  Node_t *node = 0x0;
  initNodePointer (&node, value, 1);
  listSimpleInsert (&(stack->list), node);
  stack->length++;
}

int
stackListPop (StackList_t * stack)
{
  valPtr (stack);
  Node_t *node = popFirstNodeOnListSimpleNlink (&(stack->list));
  int value = node->value;
  destroyNode (node);
  stack->length--;
  return value;
}

void
writeOnStackList (StackList_t * stack, size_t pos, int value)
{
  valPtr (stack);
  valSizePos (stack->length, pos);
  writeOnListSimple (stack->list, pos, value);
}

#include "StackArray.h"
#include <stdio.h>
#include <Vectors/Array/Int/Array.h>
#include <lib/validate.h>

#include <stddef.h>
#include <stdlib.h>

void
initStackArray (StackArray_t * stack, size_t length)
{
  valPtr (stack);
  valSize (length);
  stack->length = length;
  stack->array = newArray (stack->length);
}

void
initStackArrayPointer (StackArray_t * *stack, size_t length)
{
  valPtr (stack);
  valSize (length);
  *stack = (StackArray_t *) calloc (1, sizeof (StackArray_t));
  initStackArray (*stack, length);
}

void
destroyStackArray (StackArray_t * *stack)
{
  valPtr (stack);
  if (*stack == 0x0)
    return;
  (*stack)->array = destroyArray ((*stack)->array);
  free (*stack);
  *stack = 0x0;
  return;
}

// Lookers

void
printStackArray (StackArray_t * stack)
{
  if (stack == 0x0)
    {
      printf ("{(nil)}\n");
      return;
    }
  if (stack->array == 0x0)
    {
      printf ("{(nil)}\n");
      return;
    }
  int size;
  char *photo;
  seeArray (stack->array, stack->length, &photo, &size);
  printf ("Stack{ length: %i, array:%s }\n", (int) stack->length, photo);
}

int
readOnStackArray (StackArray_t * stack, size_t pos)
{
  valPtr (stack);
  valSizePos (stack->length, pos);
  int reader = readOnArray (stack->array, stack->length, pos);
  return reader;
}

// Modifiers

void
stackArrayPush (StackArray_t * stack, int value)
{
  valPtr (stack);
  stack->array = resizeArray (stack->array, stack->length, stack->length + 1);
  stack->length++;
  writeOnArray (stack->array, stack->length, stack->length - 1, value);
}

int
stackArrayPop (StackArray_t * stack)
{
  valPtr (stack);
  int value = readOnArray (stack->array, stack->length, stack->length - 1);
  stack->array = resizeArray (stack->array, stack->length, stack->length - 1);
  stack->length--;
  return value;
}

void
writeOnStackArray (StackArray_t * stack, size_t pos, int value)
{
  valPtr (stack);
  valSizePos (stack->length, pos);
  writeOnArray (stack->array, stack->length, pos, value);
}

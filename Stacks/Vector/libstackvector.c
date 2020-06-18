// Include local
#include <lib/validate.h>
#include <Vectors/Vector/Int/Vector.h>
#include "StackVector.h"

// Include standar
#include <stddef.h>
#include <stdlib.h>

Vector_t *
stackVectorPush (Vector_t * stack, int value)
{
  if (stack == 0x0)
    {
      stack = newVector (1);
      writeOnVector (stack, 0, value);
      return stack;
    }
  resizeVector (stack, stack->size + 1);
  writeOnVector (stack, stack->size - 1, value);
  return stack;
}

int
stackVectorPop (Vector_t * *stack_ptr)
{
  Vector_t *stack = *stack_ptr;
  if (stack == 0x0)
    {
      return 0;
    }
  if (stack->size == 1)
    {
      int value = readOnVector (stack, 0);
      *stack_ptr = destroyVector (stack);
      return value;
    }
  int value = readOnVector (stack, stack->size - 1);
  resizeVector (stack, stack->size - 1);
  return value;
}

#include <stddef.h>

#ifndef PILEARRAY_H
#define PILEARRAY_H

// Init & destroy

struct StackArray
{
  size_t length;
  int *array;
};

typedef struct StackArray StackArray_t;

void initStackArray (StackArray_t * stack, size_t length);

void initStackArrayPointer (StackArray_t * *stack, size_t length);

void destroyStackArray (StackArray_t * *stack);

void printStackArray (StackArray_t * stack);

int readOnStackArray (StackArray_t * stack, size_t pos);

void stackArrayPush (StackArray_t * stack, int value);

int stackArrayPop (StackArray_t * stack);

void writeOnStackArray (StackArray_t * stack, size_t pos, int value);


#endif //PILEARRAY_H

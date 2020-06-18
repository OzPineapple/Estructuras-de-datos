#include <stddef.h>
#include <Lists/Generic/Node.h>

#ifndef PILELIST_H
#define PILELIST_H

// Init & destroy

struct StackList
{
  size_t length;
  Node_t *list;
};

typedef struct StackList StackList_t;

void initStackList (StackList_t * stack, size_t length);

void initStackListPointer (StackList_t * *stack, size_t length);

void destroyStackList (StackList_t * *stack);

void printStackList (StackList_t * stack);

int readOnStackList (StackList_t * stack, size_t pos);

void stackListPush (StackList_t * stack, int value);

int stackListPop (StackList_t * stack);

void writeOnStackList (StackList_t * stack, size_t pos, int value);

#endif //PILELIST_H

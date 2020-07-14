#include <stddef.h>
#include <Stacks/Vector/StackVector.h>

#ifndef HANOI_H
#define HANOI_H

struct Hanoi
{
  size_t length;
  Vector_t *lv;
  Vector_t *mv;
  Vector_t *rv;
};

typedef struct Hanoi Hanoi_t;

// Include local
Hanoi_t *newHanoi (size_t length);

Hanoi_t *destroyHanoi (Hanoi_t * hanoi);

void printHanoi (Hanoi_t * hanoi);

void solveHanoi (Hanoi_t * hanoi);

#endif //HANOI_H

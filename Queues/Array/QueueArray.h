#include <stddef.h>

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

// Init & destroy

struct QueueArray
{
  size_t length;
  int *array;
};

typedef struct QueueArray QueueArray_t;

QueueArray_t *newQueueArray (size_t length);

QueueArray_t *destroyQueueArray (QueueArray_t * queue);

void printQueueArray (QueueArray_t * queue);

int readOnQueueArray (QueueArray_t * queue, size_t pos);

QueueArray_t *queueArrayPush (QueueArray_t * queue, int value);

int queueArrayPop (QueueArray_t * queue);

void writeOnQueueArray (QueueArray_t * queue, size_t pos, int value);

#endif //QUEUEARRAY_H

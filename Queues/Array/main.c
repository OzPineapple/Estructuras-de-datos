// Local headers
#include <lib/validate.h>
#include <lib/util.h>
#include <Vectors/Array/Int/Array.h>
#include "QueueArray.h"

// Standar headers
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  srand (time (NULL));
  printf ("QueueArray tester\n");

  printf ("\nQueueArray.h - Init\n");
  QueueArray_t *queue_array = newQueueArray (randomInRange (1, 5));

  printf ("\nQueueArray.h - Write and print\n");
  for (size_t index = 0; index < queue_array->length; index++)
    writeOnArray (queue_array->array, queue_array->length, index,
		  randomInRange (-100, 100));
  printQueueArray (queue_array);
  println;

  printf ("\nQueueArray.h - Write\n");
  for (size_t index = 0; index < randomInRange (1, 5); index++)
    writeOnQueueArray (queue_array,
		       randomInRange (0, queue_array->length - 1),
		       randomInRange (-100, 100));
  printQueueArray (queue_array);
  println;

  printf ("\nQueueArray.h - Read\n");
  for (size_t index = 0; index < randomInRange (1, 5); index++)
    printf ("[%i]",
	    readOnQueueArray (queue_array,
			      randomInRange (0, queue_array->length - 1)));
  printf ("\n");
  printQueueArray (queue_array);
  println;


  printf ("\nQueueArray.h - Push\n");
  for (size_t index = 0; index < randomInRange (1, 5); index++)
    queueArrayPush (queue_array, randomInRange (-100, 100));
  printQueueArray (queue_array);
  println;

  printf ("\nQueueArray.h - Pop\n");
  for (size_t index = 0; index < randomInRange (1, 5); index++)
    printf ("[%i]", queueArrayPop (queue_array));
  printf ("\n");
  printQueueArray (queue_array);
  println;

  printf ("\nQueueArray.h - Destroy\n");
  queue_array = destroyQueueArray (queue_array);
  printQueueArray (queue_array);
  println;
}

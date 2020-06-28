// Include local
#include "Vector.h"
#include <lib/util.h>

// Include standar
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main (int argc, char *argv[])
{
  printf ("Vector tester by Oz Pineapple\n");

  srand (time (NULL));

  printf ("Init vector\n");
  Vector_t *vector = newVector (randomInRange (1, 20));

  printf ("Print vector\n");
  printVector (vector);
  println;

  printf ("Write vector data\n");
  writeOnVector (vector, randomInRange (0, vector->size - 1),
		 randomInRange (-100, 100));
  printVector (vector);
  println;

  printf ("Write randomly on vector tweny times\n");
  for (int i = 0; i < 20; i++)
    {
      writeOnVector (vector, randomInRange (0, vector->size - 1),
		     randomInRange (-100, 100));
    }
  printVector (vector);
  println;

  printf ("Delete vector\n");
  deleteVector (vector);
  printVector (vector);
  println;

  printf ("Write randomly on vector tweny times\n");
  for (int i = 0; i < 20; i++)
    {
      writeOnVector (vector, randomInRange (0, vector->size - 1),
		     randomInRange (-100, 100));
    }
  printVector (vector);
  println;

  printf ("Resize randomly vector three times\n");
  for (int i = 0; i < 3; i += 1)
    {
      resizeVector (vector, randomInRange (1, 20));
      printVector (vector);
      println;
    }

  Vector_t *vector2 = newVector (vector->size);

  printf ("Print vector two\n");
  printVector (vector2);
  println;

  printf ("Clon vector to vector2, print vector 2\n");
  cloneVector (vector, vector2);
  printVector (vector2);
  println;

  printf ("Destroy vector\n");
  vector2 = destroyVector (vector2);
  vector = destroyVector (vector);

  printVector (vector);
  println;
  printVector (vector2);
  println;
}

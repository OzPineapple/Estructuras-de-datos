// Include local
#include "Vector.h"
#include <Vectors/Array/Int/Array.h>
#include <lib/util.h>
#include <lib/validate.h>

// Include standar
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Vector_t *
newVector (size_t size)
{
  valSize (size);

  Vector_t *vector = (Vector_t *) calloc (1, sizeof (Vector_t));
  valMem (vector);

  vector->array = newArray (size);
  vector->size = size;
  return vector;
}

Vector_t *
destroyVector (Vector_t * vector)
{
  if (vector == 0x0)
    return 0x0;

  destroyArray (vector->array);

  free (vector);

  return 0x0;
}

//Lookers
void
seeVector (Vector_t * vector, char * *vectorPhotography,
	   size_t * vectorPhotographySize)
{
  valPtr (vector);

  int vectorSizeStrSize = 0;
  char *vectorSizeStr;
  integerToString (vector->size, &vectorSizeStr, &vectorSizeStrSize);

  int arrayPhotographySize = 0;
  char *arrayPhotography = 0x0;
  seeArray (vector->array, vector->size, &arrayPhotography,
	    &arrayPhotographySize);

  *vectorPhotographySize =
    sizeof ("{ Size:, Array: }") + arrayPhotographySize + vectorSizeStrSize +
    1;
  *vectorPhotography =
    (char *) calloc (*vectorPhotographySize, sizeof (char));
  valPtr (*vectorPhotography);

  strcat (*vectorPhotography, "{ Size:");
  strcat (*vectorPhotography, vectorSizeStr);
  strcat (*vectorPhotography, ", Array:");
  strcat (*vectorPhotography, arrayPhotography);
  strcat (*vectorPhotography, " }");

  free (vectorSizeStr);
  free (arrayPhotography);
}

void
printVector (Vector_t * vector)
{
  if (vector == 0x0)
    {
      printf ("(nil)");
      return;
    }
  size_t vectorPhotographySize = 0;
  char *vectorPhotography = 0x0;
  seeVector (vector, &vectorPhotography, &vectorPhotographySize);
  printf ("%s", vectorPhotography);
  free (vectorPhotography);
}

int
readOnVector (Vector_t * vector, size_t pos)
{
  valPtr (vector);
  valNeg (pos);
  return readOnArray (vector->array, vector->size, pos);
}

//Modifyers
void
writeOnVector (Vector_t * vector, size_t pos, int data)
{
  valPtr (vector);
  valNeg (pos);
  writeOnArray (vector->array, vector->size, pos, data);
}

void
deleteOnVector (Vector_t * vector, size_t pos)
{
  valPtr (vector);
  valNeg (pos);
  writeOnVector (vector, pos, 0);
}

void
deleteVector (Vector_t * vector)
{
  for (int i = 0; i < vector->size; i++)
    {
      deleteOnVector (vector, i);
    }
}

void
resizeVector (Vector_t * vector, size_t newSize)
{
  valPtr (vector);
  valNeg (newSize);

  vector->array = resizeArray (vector->array, vector->size, newSize);
  vector->size = newSize;
}

void
cloneVector (Vector_t * original, Vector_t * clone)
{
  cloneArray (original->array, clone->array, original->size);
}

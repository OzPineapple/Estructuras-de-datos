// Include local
#include "GenericVector.h"
#include <lib/validate.h>

// Include standar
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Create & destroy
void
initGenericVector (GenericVector * generic_vector, int length, int size)
{
  valNeg (size);
  generic_vector->length = length;
  generic_vector->array = (int *) calloc (length, size);
  valPtr (generic_vector->array);
}

void
initGenericVectorPointer (GenericVector ** generic_vector, int length,
			  int size)
{
  *generic_vector = (GenericVector *) calloc (1, sizeof (GenericVector));
  initGenericVector (*generic_vector, length, size);
}

void
destroyGenericVector (GenericVector * generic_vector)
{
  free (generic_vector->array);
  free (generic_vector);
}

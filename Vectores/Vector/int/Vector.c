// Include local
#include "Vector.h"
#include <Vectores/Arreglo/int/Arreglo.h>
#include <lib/util.h>
#include <lib/validar.h>

// Include standar
#include <stdlib.h>
#include <stdio.h>

Vector *
nuevoVector (int tamanno)
{
  Vector *vector = (Vector *) malloc (sizeof (Vector));
  valMem (vector);
  valTam (tamanno);
  vector->arreglo = nuevoArreglo (tamanno);
  vector->tamanno = tamanno;
  return vector;
}

Vector *
destruirVector (Vector * vector)
{
  if (vector == NULL)
    return NULL;
  destruirArreglo (vector->arreglo);
  free (vector);
  return NULL;
}

void
mostrarVector (Vector * vector)
{
  if (vector == NULL)
    {
      printnull;
      return;
    }
  printf ("{ tamaño: %i, arrelgo: ", vector->tamanno);
  mostrarArreglo (vector->arreglo, vector->tamanno);
  printf (" }");
}

void
insertarVector (Vector * vector, int posicion, int dato)
{
  valPtr (vector);
  valTamPos (vector->tamanno, posicion);
  insertarArreglo (vector->arreglo, posicion, dato);
}

void
eliminarVector (Vector * vector, int posicion)
{
  valPtr (vector);
  valNeg (posicion);
  eliminarArreglo (vector->arreglo, posicion);
}

int
buscarVector (Vector * vector, int dato)
{
  valPtr (vector);
  return buscarArreglo (vector->arreglo, vector->tamanno, dato);
}

int
leerVector (Vector * vector, int posicion)
{
  valPtr (vector);
  valTamPos (vector->tamanno, posicion);
  return leerArreglo (vector->arreglo, posicion);
}

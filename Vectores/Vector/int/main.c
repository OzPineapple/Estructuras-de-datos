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
  Vector *vector = NULL;
  int posicion = 0;
  int numero = 0;
  srand (time (NULL));
  vector = nuevoVector (aleatorio (1, 20));
  mostrarVector (vector);
  println;
  for (posicion = 0; posicion < vector->tamanno; posicion++)
    {
      insertarVector (vector, posicion, aleatorio (-100, 100));
    }
  mostrarVector (vector);
  println;
  numero = leerVector (vector, aleatorio (0, vector->tamanno));
  printf ("%i -> %i\n", numero, buscarVector (vector, numero));
  for (posicion = 0; posicion < vector->tamanno; posicion++)
    {
      eliminarVector (vector, posicion);
    }
  mostrarVector (vector);
  println;
  vector = destruirVector (vector);
  mostrarVector (vector);
  println;
  return 0;
}

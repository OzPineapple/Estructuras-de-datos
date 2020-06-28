// Include local
#include <lib/util.h>
#include "Arreglo.h"

// Include standar
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main (void)
{
  int i = 0;
  int tamanno = 0;
  int *arreglo = NULL;
  int numero = 0;

  srand (time (NULL));
  tamanno = aleatorio (1, 20);
  arreglo = nuevoArreglo (tamanno);
  mostrarArreglo (arreglo, tamanno);
  println;

  for (i = 0; i < tamanno; i++)
    {
      insertarArreglo (arreglo, i, aleatorio (-100, 100));
    }
  mostrarArreglo (arreglo, tamanno);
  println;

  numero = leerArreglo (arreglo, aleatorio (0, tamanno));
  printf ("B[%i]:%i\n", numero, buscarArreglo (arreglo, tamanno, numero));

  for (i = 0; i < tamanno; i++)
    {
      eliminarArreglo (arreglo, i);
    }
  mostrarArreglo (arreglo, tamanno);
  println;

  arreglo = destruirArreglo (arreglo);

  return 0;
}

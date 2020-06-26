#include <lib/validar.h>
#include <lib/util.h>
#include <stdlib.h>
#include <stdio.h>

int *
nuevoArreglo (int tamanno)
{
  int *arreglo = NULL;
  int i = 0;

  arreglo = (int *) malloc (sizeof (int) * tamanno);
  valMem (arreglo);

  for (i = 0; i < tamanno; i++)
    {
      *(arreglo + i) = 0;
    }

  return arreglo;
}

int *
destruirArreglo (int *arreglo)
{
  if (arreglo == NULL)
    return NULL;
  free (arreglo);
  return NULL;
}

void
mostrarArreglo (int *arreglo, int tamanno)
{
  valPtr (arreglo);
  int i = 0;
  for (i = 0; i < tamanno; i++)
    {
      printf ("[%i]", *(arreglo + i));
    }
}

int
leerArreglo (int *arreglo, int posicion)
{
  valPtr (arreglo);
  return *(arreglo + posicion);
}

void
insertarArreglo (int *arreglo, int posicion, int dato)
{
  valPtr (arreglo);
  *(arreglo + posicion) = dato;
}

void
eliminarArreglo (int *arreglo, int posicion)
{
  valPtr (arreglo);
  insertarArreglo (arreglo, posicion, 0);
}

int *
buscarArreglo (int *arreglo, int tamanno, int dato)
{
  valPtr (arreglo);
  int i = 0;
  for (i = 0; i < tamanno; i++)
    {
      if (*(arreglo + i) == dato)
	return arreglo + i;
    }
  return NULL;
}

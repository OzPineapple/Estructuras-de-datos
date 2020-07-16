#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <lib/util.h>
#include "ListaDoble.h"

int
main (int argc, char *argv[])
{
  int tamanno = 0;
  int valor = 0;
  Lista *lista = NULL;
  srand (getpid ());
  tamanno = aleatorio (1, 5);
  lista = nuevaListaDoble (tamanno);
  mostrarListaDoble (lista);
  println;
  valor = aleatorio (-100, 100);
  printf ("VAL = %i\t", valor);
  insertarListaDoble (lista, aleatorio (0, tamanno - 1), valor);
  valor = buscarListaDoble (lista, valor);
  printf ("POS = %i\n", valor);
  mostrarListaDoble (lista);
  println;
  eliminarListaDoble (lista, aleatorio (0, tamanno - 1));
  mostrarListaDoble (lista);
  println;
  lista = destruirListaDoble (lista);
  mostrarListaDoble (lista);
  println;
}

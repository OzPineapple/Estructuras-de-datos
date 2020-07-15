#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <lib/util.h>
#include <Listas/Sencilla/ListaSencilla.h>

int
main (int argc, char *argv[])
{
  int tamanno = 0;
  int valor = 0;
  Lista *lista = NULL;
  srand (getpid ());
  tamanno = aleatorio (1, 10);
  lista = nuevaListaSencilla (tamanno);
  mostarListaSencilla (lista);
  println;
  valor = aleatorio (-100, 100);
  printf ("VAL = %i\t", valor);
  insertarListaSencilla (lista, aleatorio (0, tamanno - 1), valor);
  valor = buscarListaSencilla (lista, valor);
  printf ("POS = %i\n", valor);
  mostarListaSencilla (lista);
  println;
  eliminarListaSencilla (lista, aleatorio (0, tamanno - 1));
  mostarListaSencilla (lista);
  println;
  lista = destruirListaSencilla (lista);
  mostarListaSencilla (lista);
  println;
}

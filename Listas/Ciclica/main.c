#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <lib/util.h>
#include <unistd.h>
#include <Listas/Ciclica/ListaCiclica.h>

int
main (int argc, char *argv[])
{
  int tamanno = 0;
  int valor = 0;
  Lista *lista = NULL;
  srand (getpid ());
  tamanno = aleatorio (1, 10);
  lista = nuevaListaCiclica (tamanno);
  mostrarListaCiclica (lista);
  println;
  valor = aleatorio (-100, 100);
  printf ("VAL = %i\t", valor);
  insertarListaCiclica (lista, aleatorio (0, tamanno - 1), valor);
  valor = buscarListaCiclica (lista, valor);
  printf ("POS = %i\n", valor);
  mostrarListaCiclica (lista);
  println;
  eliminarListaCiclica (lista, aleatorio (0, tamanno - 1));
  mostrarListaCiclica (lista);
  println;
  lista = destruirListaCiclica (lista);
  mostrarListaCiclica (lista);
  println;
}

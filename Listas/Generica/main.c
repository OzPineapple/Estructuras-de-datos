#include <Listas/Generica/Nodo.h>
#include <Listas/Generica/Lista.h>
#include <lib/util.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void probarNodo (void);
void probarLista (void);

int
main (void)
{
  srand (getpid ());
  probarNodo ();
  probarLista ();
  return 0;
}

void
probarNodo (void)
{
  Nodo *nodo = NULL;
  Nodo *nodo2 = NULL;
  nodo = nuevoNodo (aleatorio (-100, 100), aleatorio (1, 5));
  nodo2 = nuevoNodo (aleatorio (-100, 100), aleatorio (1, 5));
  mostrarNodo (nodo);
  println;
  mostrarNodo (nodo2);
  println;
  enlazarNodo (nodo, nodo2, 0);
  enlazarNodo (nodo2, nodo, 0);
  mostrarNodo (nodo);
  println;
  mostrarNodo (nodo2);
  println;
  nodo = destruirNodo (nodo);
  nodo2 = destruirNodo (nodo2);
  mostrarNodo (nodo);
  println;
  mostrarNodo (nodo2);
  println;
}

void
probarLista (void)
{
  Lista *lista = NULL;
  Nodo *nodo = NULL;
  int camino = 0;
  camino = aleatorio (0, 2);
  lista = crearNodos (aleatorio (1, 5), camino + 1, camino);
  nodo = ultimoNodo (lista, camino);
  enlazarNodo (nodo, lista->nodo, camino);
  mostrarNodos (lista, camino);
  println;
  nodo = nuevoNodo (aleatorio (-100, 100), 4);
  annadirNodo (lista, nodo, aleatorio (0, tamannoNodos (lista, camino) - 1),
	       camino);
  mostrarNodos (lista, camino);
  println;
  nodo =
    eliminarNodo (lista, aleatorio (0, tamannoNodos (lista, camino) - 1),
		  camino);
  destruirNodo (nodo);
  mostrarNodos (lista, camino);
  println;
  lista = destruirNodos (lista, 0);
  mostrarNodos (lista, camino);
  println;
}

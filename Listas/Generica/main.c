#include <Listas/Generica/Nodo.h>
#include <Listas/Generica/Lista.h>
#include <lib/util.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void probarNodo (void);
void probarLista (void);

int
main (void)
{
  srand (time (NULL));
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
  Nodo *lista = NULL;
  Nodo *nodo = NULL;
  int camino = 0;
  int tamanno = 0;
  int posicion = 0;
  camino = aleatorio (0, 5);
  tamanno = aleatorio (1, 10);
  lista = crearNodos (tamanno, camino + 1, camino);
  mostrarNodos (lista, camino);
  println;
  nodo = siguienteNodo (lista, camino);
  mostrarNodo (nodo);
  println;
  nodo = obtenerNodo (lista, aleatorio (0, tamanno - 1), camino);
  mostrarNodo (nodo);
  println;
  posicion = aleatorio (0, tamanno - 1);
  nodo = lista;
  if (posicion == 0)
    lista = siguienteNodo (lista, camino);
  nodo = eliminarNodo (nodo, posicion, camino);
  mostrarNodo (nodo);
  println;
  destruirNodo (nodo);
  mostrarNodos (lista, camino);
  println;
  nodo = ultimoNodo (lista, camino);
  mostrarNodo (nodo);
  println;
  enlazarNodo (nodo, lista, camino);
  mostrarNodos (lista, camino);
  println;
  lista = destruirNodos (lista, 0);
  mostrarNodos (lista, camino);
  println;
}

#include <Listas/Sencilla/ListaSencilla.h>
#include <Listas/Generica/Lista.h>
#include <Listas/Generica/Nodo.h>
#include <lib/validar.h>
#include <stdio.h>
#include <stdlib.h>

ListaSencilla *
nuevaListaSencilla (int tamanno)
{
  Nodo *nodo = NULL;
  ListaSencilla *lista = NULL;
  valTam (tamanno);
  nodo = crearNodos (tamanno, 1, 0);
  valMem (nodo);
  lista = (ListaSencilla *) calloc (1, sizeof (ListaSencilla));
  lista->nodo = nodo;
  return lista;
}

ListaSencilla *
destruirListaSencilla (ListaSencilla * lista)
{
  if (lista == NULL)
    return NULL;
  destruirNodos (lista->nodo, 0);
  free (lista);
  return NULL;
}

void
mostarListaSencilla (ListaSencilla * lista)
{
  if (lista == NULL)
    {
      printf ("(nil)");
      return;
    }
  mostrarNodos (lista->nodo, 0);
}

void
insertarListaSencilla (ListaSencilla * lista, int posicion, int valor)
{
  Nodo *nodo = NULL;
  if (lista == NULL)
    return;
  valNeg (posicion);
  nodo = obtenerNodo (lista->nodo, posicion, 0);
  insertarNodo (nodo, valor);
}

void
eliminarListaSencilla (ListaSencilla * lista, int posicion)
{
  Nodo *nodo = NULL;
  Nodo *siguiente = NULL;
  if (lista == NULL)
    return;
  nodo = lista->nodo;
  if (posicion == 0)
    {
      siguiente = siguienteNodo (nodo, 0);
      lista->nodo = siguiente;
    }
  nodo = eliminarNodo (nodo, posicion, 0);
  destruirNodo (nodo);
}

int
buscarListaSencilla (ListaSencilla * lista, int valor)
{
  int pos = 0;
  Nodo *siguiente = NULL;
  Nodo *nodo = NULL;
  if (lista == NULL)
    return -1;
  nodo = lista->nodo;
  siguiente = siguienteNodo (nodo, 0);
  while (siguiente != NULL && siguiente != lista->nodo)
    {
      if (nodo->valor == valor)
	return pos;
      nodo = siguiente;
      siguiente = siguienteNodo (nodo, 0);
      pos++;
    }
  return pos;
}

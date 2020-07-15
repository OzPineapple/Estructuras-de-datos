#include <Listas/Sencilla/ListaSencilla.h>
#include <Listas/Generica/Lista.h>
#include <Listas/Generica/Nodo.h>
#include <lib/validar.h>
#include <stdio.h>
#include <stdlib.h>

Lista *
nuevaListaSencilla (int tamanno)
{
  Lista *lista = NULL;
  valTam (tamanno);
  lista = crearNodos (tamanno, 1, 0);
  valMem (lista);
  return lista;
}

Lista *
destruirListaSencilla (Lista * lista)
{
  if (lista == NULL)
    return NULL;
  lista = destruirNodos (lista, 0);
  return NULL;
}

void
mostarListaSencilla (Lista * lista)
{
  if (lista == NULL)
    {
      printf ("(nil)");
      return;
    }
  mostrarNodos (lista, 0);
}

void
insertarListaSencilla (Lista * lista, int posicion, int valor)
{
  Nodo *nodo = NULL;
  if (lista == NULL)
    return;
  valNeg (posicion);
  nodo = nuevoNodo (valor, 1);
  annadirNodo (lista, nodo, posicion, 0);
}

void
eliminarListaSencilla (Lista * lista, int posicion)
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
  nodo = eliminarNodo (lista, posicion, 0);
  destruirNodo (nodo);
}

int
buscarListaSencilla (Lista * lista, int valor)
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

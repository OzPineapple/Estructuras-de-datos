#include <lib/validar.h>
#include <Listas/Generica/Lista.h>
#include <Listas/Generica/Nodo.h>
#include <stdlib.h>

Lista *
nuevaListaDoble (int tamanno)
{
  int i = 0;
  Lista *lista = NULL;
  valTam (tamanno);
  lista = crearNodos (tamanno, 2, 0);
  Nodo *start = NULL;
  Nodo *next = NULL;
  for (i = tamanno - 1; i > 0; i--)
    {
      start = obtenerNodo (lista, i, 0);
      next = obtenerNodo (lista, i - 1, 0);
      enlazarNodo (start, next, 1);
    }
  return lista;
}

Lista *
destruirListaDoble (Lista * lista)
{
  return destruirNodos (lista, 0);
}

void
mostrarListaDoble (Lista * lista)
{
  conextion_characther = "⇄";
  mostrarNodos (lista, 0);
}

void
insertarListaDoble (Lista * lista, int posicion, int valor)
{
  int tamanno = 0;
  Nodo *nodo = NULL;
  Lista *ultima = NULL;
  valNeg (posicion);
  tamanno = tamannoNodos (lista, 0);
  ultima = (Lista *) malloc (sizeof (Lista));
  valMem (ultima);
  ultima->nodo = ultimoNodo (lista, 0);
  nodo = nuevoNodo (valor, 2);
  annadirNodo (lista, nodo, posicion, 0);
  annadirNodo (ultima, nodo, tamanno - posicion, 1);
  free (ultima);
}

void
eliminarListaDoble (Lista * lista, int posicion)
{
  int tamanno = 0;
  Lista *ultima = NULL;
  valNeg (posicion);
  tamanno = tamannoNodos (lista, 0);
  ultima = (Lista *) malloc (sizeof (Lista));
  valMem (ultima);
  ultima->nodo = ultimoNodo (lista, 0);
  eliminarNodo (lista, posicion, 0);
  eliminarNodo (ultima, tamanno - posicion, 1);
}

int
buscarListaDoble (Lista * lista, int valor)
{
  return buscarNodos (lista, valor, 0);
}

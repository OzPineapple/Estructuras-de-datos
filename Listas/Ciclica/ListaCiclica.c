#include <Listas/Ciclica/ListaCiclica.h>
#include <Listas/Sencilla/ListaSencilla.h>
#include <lib/validar.h>
#include <stdlib.h>
#include <stdio.h>

Lista *
nuevaListaCiclica (int tamanno)
{
  Lista *lista = NULL;
  valTam (tamanno);
  lista = nuevaListaSencilla (tamanno);
  enlazarNodo (ultimoNodo (lista, 0), lista->nodo, 0);
  return lista;
}

Lista *
destruirListaCiclica (Lista * lista)
{
  if (lista == NULL)
    return NULL;
  return destruirListaSencilla (lista);
}

void
mostrarListaCiclica (Lista * lista)
{
  if (lista == NULL)
    {
      printf ("(nil)");
      return;
    }
  mostarListaSencilla (lista);
}

void
insertarListaCiclica (Lista * lista, int posicion, int valor)
{
  insertarListaSencilla (lista, posicion, valor);
}

void
eliminarListaCiclica (Lista * lista, int posicion)
{
  eliminarListaSencilla (lista, posicion);
}

int
buscarListaCiclica (Lista * lista, int valor)
{
  return buscarListaSencilla (lista, valor);
}

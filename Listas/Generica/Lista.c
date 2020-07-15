#include <Listas/Generica/Lista.h>
#include <Listas/Generica/Nodo.h>
#include <lib/validar.h>
#include <stdlib.h>
#include <stdio.h>

Lista *
crearNodos (int tamanno, int n_enlaces, int camino)
{
  int i = 0;
  Nodo *atras = NULL;
  Nodo *nodo = NULL;
  Nodo *cabecera = NULL;
  Lista *lista = NULL;
  valTam (tamanno);
  valTam (n_enlaces);
  valNeg (camino);
  cabecera = nuevoNodo (0, n_enlaces);
  valMem (cabecera);
  nodo = cabecera;
  for (i = 0; i < tamanno; i++)
    {
      atras = nodo;
      nodo = nuevoNodo (0, n_enlaces);
      valMem (nodo);
      enlazarNodo (atras, nodo, camino);
    }
  lista = (Lista *) calloc (1, sizeof (Lista));
  lista->nodo = cabecera;
  return lista;
}

Lista *
destruirNodos (Lista * lista, int camino)
{
  Nodo *siguiente = NULL;
  Nodo *nodo = NULL;
  if (lista->nodo == NULL)
    return NULL;
  nodo = lista->nodo;
  siguiente = siguienteNodo (lista->nodo, camino);
  while (siguiente != NULL && siguiente != lista->nodo)
    {
      siguiente = siguienteNodo (nodo, camino);
      destruirNodo (nodo);
      nodo = siguiente;
    }
  return NULL;
}

void
mostrarNodos (Lista * lista, int camino)
{
  Nodo *nodo = NULL;
  Nodo *siguiente = NULL;
  if (lista == NULL)
    {
      printf ("(nil)");
      return;
    }
  nodo = lista->nodo;
  siguiente = siguienteNodo (nodo, camino);
  while (nodo != NULL)
    {
      mostrarNodo (nodo);
      printf ("\e[93m→\e[0m");
      if (siguiente == lista->nodo)
	{
	  printf ("\e[91m{\e[93m⥀\e[91m}\e[0m");
	  return;
	}
      nodo = siguiente;
      siguiente = siguienteNodo (nodo, camino);
    }
}

Nodo *
ultimoNodo (Lista * lista, int camino)
{
  Nodo *nodo = NULL;
  Nodo *siguiente = NULL;
  if (lista == NULL)
    return NULL;
  valTamPos (lista->nodo->n_enlaces, camino);
  nodo = lista->nodo;
  siguiente = siguienteNodo (nodo, camino);
  while (siguiente != NULL && siguiente != lista->nodo)
    {
      nodo = siguiente;
      siguiente = siguienteNodo (nodo, camino);
    }
  return nodo;
}

int
tamannoNodos (Lista * lista, int camino)
{
  int tamanno = 0;
  Nodo *nodo = NULL;
  Nodo *siguiente = NULL;
  if (lista->nodo == NULL)
    return 0;
  valTamPos (lista->nodo->n_enlaces, camino);
  nodo = lista->nodo;
  siguiente = siguienteNodo (nodo, camino);
  while (siguiente != NULL && siguiente != lista->nodo)
    {
      nodo = siguiente;
      siguiente = siguienteNodo (nodo, camino);
      tamanno++;
    }
  return tamanno;
}

Nodo *
siguienteNodo (Nodo * nodo, int camino)
{
  if (nodo == NULL)
    return NULL;
  valNeg (camino);
  valTamPos (nodo->n_enlaces, camino);
  return *(nodo->enlace + camino);
}

Nodo *
obtenerNodo (Lista * lista, int posicion, int camino)
{
  int i = 0;
  Nodo *nodo = NULL;
  if (lista == NULL || lista->nodo == NULL)
    return NULL;
  if (posicion < 0)
    return NULL;
  valTamPos (lista->nodo->n_enlaces, camino);
  nodo = lista->nodo;
  for (i = 0; i < posicion && nodo != NULL; i++)
    {
      nodo = siguienteNodo (nodo, camino);
    }
  return nodo;
}

Nodo *
eliminarNodo (Lista * lista, int posicion, int camino)
{
  Nodo *atras = NULL;
  Nodo *medio = NULL;
  Nodo *frente = NULL;
  if (lista == NULL || lista->nodo == NULL)
    return NULL;
  atras = obtenerNodo (lista, posicion - 1, camino);
  medio = obtenerNodo (lista, posicion, camino);
  frente = obtenerNodo (lista, posicion + 1, camino);
  enlazarNodo (atras, frente, camino);
  enlazarNodo (medio, NULL, camino);
  lista->nodo = (medio == lista->nodo) ? frente : lista->nodo;
  return medio;
}

void
annadirNodo (Lista * lista, Nodo * nodo, int posicion, int camino)
{
  Nodo *atras = NULL;
  Nodo *frente = NULL;
  if (nodo == NULL)
    return;
  atras = obtenerNodo (lista, posicion - 1, camino);
  frente = obtenerNodo (lista, posicion, camino);
  enlazarNodo (atras, nodo, camino);
  enlazarNodo (nodo, frente, camino);
  lista->nodo = (frente == lista->nodo) ? nodo : lista->nodo;
}

#include <Listas/Generica/Lista.h>
#include <Listas/Generica/Nodo.h>
#include <lib/validar.h>
#include <lib/util.h>
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
  free (lista);
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
  siguiente = lista->nodo;
  do
    {
      nodo = siguiente;
      siguiente = siguienteNodo (nodo, camino);
    }
  while (siguiente != NULL && siguiente != lista->nodo);
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
  siguiente = lista->nodo;
  do
    {
      nodo = siguiente;
      siguiente = siguienteNodo (nodo, camino);
      tamanno++;
    }
  while (siguiente != NULL && siguiente != lista->nodo);
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
  Nodo *ultimo_s = NULL;
  ultimo_s = siguienteNodo (ultimoNodo (lista, camino), camino);
  if (lista == NULL || (posicion < 0 && ultimo_s != lista->nodo))
    return NULL;
  valTamPos (lista->nodo->n_enlaces, camino);
  posicion =
    (ultimo_s == lista->nodo) ? mod (posicion,
				     tamannoNodos (lista, camino)) : posicion;
  nodo = lista->nodo;
  for (i = 0; i < posicion && nodo != NULL; i++)
    nodo = siguienteNodo (nodo, camino);
  return nodo;
}

Nodo *
eliminarNodo (Lista * lista, int posicion, int camino)
{
  Nodo *atras = NULL;
  Nodo *medio = NULL;
  Nodo *frente = NULL;
  if (lista == NULL )
    return NULL;
  atras = obtenerNodo (lista, posicion - 1, camino);
  medio = obtenerNodo (lista, posicion, camino);
  frente = obtenerNodo (lista, posicion + 1, camino);
  enlazarNodo (atras, frente, camino);
  enlazarNodo (medio, NULL, camino);
  lista->nodo = (posicion == 0) ? frente : lista->nodo;
  return medio;
}

void
annadirNodo (Lista * lista, Nodo * nodo, int posicion, int camino)
{
  Nodo *atras = NULL;
  Nodo *frente = NULL;
  if (nodo == NULL || lista == NULL)
    return;
  atras = obtenerNodo (lista, posicion - 1, camino);
  frente = obtenerNodo (lista, posicion, camino);
  enlazarNodo (atras, nodo, camino);
  enlazarNodo (nodo, frente, camino);
  lista->nodo = (posicion == 0) ? nodo : lista->nodo;
}

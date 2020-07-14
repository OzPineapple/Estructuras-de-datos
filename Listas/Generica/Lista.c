#include "Lista.h"
#include "Nodo.h"
#include <lib/validar.h>
#include <stddef.h>
#include <stdio.h>

Nodo *
crearNodos (int tamanno, int n_enlaces, int camino)
{
  int i = 0;
  Nodo *atras = NULL;
  Nodo *nodo = NULL;
  Nodo *cabecera = NULL;
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
  return cabecera;
}

Nodo *
destruirNodos (Nodo * nodo, int camino)
{
  Nodo *siguiente = NULL;
  Nodo *cabecera = NULL;
  if (nodo == NULL)
    return NULL;
  cabecera = nodo;
  siguiente = siguienteNodo (nodo, camino);
  while (siguiente != NULL && siguiente != cabecera)
    {
      siguiente = siguienteNodo (nodo, camino);
      destruirNodo (nodo);
      nodo = siguiente;
    }
  return NULL;
}

void
mostrarNodos (Nodo * cabecera, int camino)
{
  Nodo *nodo = NULL;
  Nodo *siguiente = NULL;
  if (cabecera == NULL)
    {
      printf ("(nil)");
      return;
    }
  nodo = cabecera;
  siguiente = siguienteNodo (nodo, camino);
  while (nodo != NULL)
    {
      mostrarNodo (nodo);
      printf ("\e[93m→\e[0m");
      if (siguiente == cabecera)
	{
	  printf ("\e[91m{\e[93m⥀\e[91m}\e[0m");
	  return;
	}
      nodo = siguiente;
      siguiente = siguienteNodo (nodo, camino);
    }
}

Nodo *
ultimoNodo (Nodo * cabecera, int camino)
{
  Nodo *nodo = NULL;
  Nodo *siguiente = NULL;
  if (cabecera == NULL)
    return NULL;
  valTamPos (cabecera->n_enlaces, camino);
  nodo = cabecera;
  siguiente = siguienteNodo (nodo, camino);
  while (siguiente != NULL && siguiente != cabecera)
    {
      nodo = siguiente;
      siguiente = siguienteNodo (nodo, camino);
    }
  return nodo;
}

int
tamannoNodos (Nodo * cabecera, int camino)
{
  int tamanno = 0;
  Nodo *nodo = NULL;
  Nodo *siguiente = NULL;
  if (cabecera == NULL)
    return 0;
  valTamPos (cabecera->n_enlaces, camino);
  nodo = cabecera;
  siguiente = siguienteNodo (nodo, camino);
  while (siguiente != NULL && siguiente != cabecera)
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
obtenerNodo (Nodo * nodo, int posicion, int camino)
{
  int i = 0;
  if (nodo == NULL)
    return NULL;
  if (posicion < 0)
    return NULL;
  valTamPos (nodo->n_enlaces, camino);
  for (i = 0; i < posicion && nodo != NULL; i++)
    {
      nodo = siguienteNodo (nodo, camino);
    }
  return nodo;
}

Nodo *
eliminarNodo (Nodo * nodo, int posicion, int camino)
{
  Nodo *atras = NULL;
  Nodo *medio = NULL;
  Nodo *frente = NULL;
  if (nodo == NULL)
    return NULL;
  atras = obtenerNodo (nodo, posicion - 1, camino);
  medio = obtenerNodo (nodo, posicion, camino);
  frente = obtenerNodo (nodo, posicion + 1, camino);
  enlazarNodo (atras, frente, camino);
  enlazarNodo (medio, NULL, camino);
  return medio;
}

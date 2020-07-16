#include <Listas/Generica/Nodo.h>
#include <lib/validar.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

Nodo *
nuevoNodo (int valor, int n_enlaces)
{
  valTam (n_enlaces);
  Nodo *nodo = (Nodo *) calloc (1, sizeof (Nodo));
  valMem (nodo);
  nodo->valor = valor;
  nodo->enlace = (Nodo **) calloc (n_enlaces, sizeof (Nodo *));
  valMem (nodo->enlace);
  nodo->n_enlaces = n_enlaces;
  return nodo;
}

Nodo *
destruirNodo (Nodo * nodo)
{
  if (nodo == NULL)
    return NULL;
  free (nodo->enlace);
  free (nodo);
  return NULL;
}

void
insertarNodo (Nodo * nodo, int valor)
{
  valPtr (nodo);
  nodo->valor = valor;
}

void
enlazarNodo (Nodo * nodo, Nodo * enlace, int camino)
{
  if (nodo == NULL)
    return;
  *(nodo->enlace + camino) = enlace;
}

void
mostrarNodo (Nodo * nodo)
{
  int i = 0;
  if (nodo == NULL)
    {
      printf ("(nil)");
      return;
    }
  printf
    ("\e[91m❲\e[92m➲\e[91m:\e[0m%p\e[91m, \e[92m⛁\e[91m:\e[0m%i\e[91m, \e[92m#⚯\e[91m:\e[0m%i\e[91m, \e[92m⚯\e[91m:\e[0m",
     nodo, nodo->valor, nodo->n_enlaces);
  for (i = 0; i < nodo->n_enlaces; i++)
    printf ("\e[91m⟨\e[0m%p\e[91m⟩\e[0m", *(nodo->enlace + i));
  printf ("\e[91m❳\e[0m");
}

#include <stdio.h>
#include <stdlib.h>
#include "validar.h"

void
validarTamanno_definicion (int numero, const char *numero_nombre,
			   const char *archivo_nombre,
			   const char *funcion_nombre, const int linea_numero)
{
  if (numero < 1)
    {
      fprintf (stderr,
	       "EXCEPCIÓN - %s:%i: Número cero ó menor, es ilegal como argumento en %s( %s:%i ), %i  < 1\n",
	       archivo_nombre, linea_numero, funcion_nombre, numero_nombre,
	       numero, numero);
      exit (EXIT_FAILURE);
    }
}

void
validarNegativo_definicion (int numero, const char *numero_nombre,
			    const char *archivo_nombre,
			    const char *funcion_nombre,
			    const int linea_numero)
{
  if (numero < 0)
    {
      fprintf (stderr,
	       "EXCEPCIÓN - %s:%i: Número negativo, ilegal como argumento en %s( %s:%i ), %i < 0 )\n",
	       archivo_nombre, linea_numero, funcion_nombre, numero_nombre,
	       numero, numero);
      exit (EXIT_FAILURE);
    }
}

void
validarTamannoPosicion_definicion (int tamanno, const char *tamanno_nombre,
				   int posicion, const char *posicion_nombre,
				   const char *archivo_nombre,
				   const char *funcion_nombre,
				   const int linea_numero)
{
  validarTamanno_definicion (tamanno, tamanno_nombre, archivo_nombre,
			     funcion_nombre, linea_numero);
  validarNegativo_definicion (posicion, posicion_nombre, archivo_nombre,
			      funcion_nombre, linea_numero);

  if (posicion > (tamanno - 1))
    {
      fprintf (stderr,
	       "EXCEPCIÓN - %s:%i: Número mayor al solicitado, ilegal como argumento en %s( %s:%i, %s:%i ), %i > %i\n",
	       archivo_nombre, linea_numero, funcion_nombre, tamanno_nombre,
	       tamanno, posicion_nombre, posicion, posicion, (tamanno - 1));
      exit (EXIT_FAILURE);
    }
}

void
validarMemoria_definicion (void *puntero, const char *puntero_nombre,
			   const char *archivo_nombre,
			   const char *funcion_nombre, const int linea_numero)
{
  if (puntero == 0x0)
    {
      fprintf (stderr,
	       "ERROR - %s:%i: Couldn\'t allocate memory, gotted NULL %s( %s )\n",
	       archivo_nombre, linea_numero, funcion_nombre, puntero_nombre);
      exit (EXIT_FAILURE);
    }
}

void
validarPuntero_definicion (void *puntero, const char *puntero_nombre,
			   const char *archivo_nombre,
			   const char *funcion_nombre, const int linea_numero)
{
  if (puntero == 0x0)
    {
      fprintf (stderr,
	       "EXCEPCIÓN - %s:%i: Puntero nulo, ilegal como argumento en %s( %s:␀ )\n",
	       archivo_nombre, linea_numero, funcion_nombre, puntero_nombre);
      exit (EXIT_FAILURE);
    }
}

void
validarDoblePuntero_definicion (void * *puntero,
				const char *puntero_nombre,
				const char *archivo_nombre,
				const char *funcion_nombre,
				const int linea_numero)
{
  if (puntero == 0x0)
    {
      fprintf (stderr,
	       "EXCEPCIÓN - %s:%i: Puntero nulo, ilegal como argumento en %s( %s:␀ )\n",
	       archivo_nombre, linea_numero, funcion_nombre, puntero_nombre);
      exit (EXIT_FAILURE);
    }
  if ((*puntero) == 0x0)
    {
      fprintf (stderr,
	       "EXCEPCIÓN - %s:%i: Puntero nulo, ilegal como argumento en %s( %s:%p → ␀ )\n",
	       archivo_nombre, linea_numero, funcion_nombre, puntero_nombre,
	       puntero);
      exit (EXIT_FAILURE);
    }
}

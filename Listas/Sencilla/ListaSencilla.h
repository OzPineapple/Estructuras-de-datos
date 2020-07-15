#include <Listas/Generica/Nodo.h>

#ifndef _LISTSIMPLE_H
#define _LISTSIMPLE_H

typedef struct ListaSencilla_s
{
  Nodo *nodo;
} ListaSencilla;

ListaSencilla *nuevaListaSencilla (int);

ListaSencilla *destruirListaSencilla (ListaSencilla *);

void mostarListaSencilla (ListaSencilla *);

void insertarListaSencilla (ListaSencilla *, int, int);

void eliminarListaSencilla (ListaSencilla *, int);

int buscarListaSencilla (ListaSencilla *, int);

#endif //_LISTSIMPLE_H

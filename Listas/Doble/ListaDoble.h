#include <Listas/Generica/Lista.h>

#ifndef _LISTADOBLE_H
#define _LISTADOBLE_H

Lista *nuevaListaDoble (int);

Lista *destruirListaDoble (Lista *);

void mostrarListaDoble (Lista *);

void insertarListaDoble (Lista *, int, int);

void eliminarListaDoble (Lista *, int);

int buscarListaDoble (Lista *, int);

#endif // _LISTADOBLE_H

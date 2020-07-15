#include <Listas/Generica/Lista.h>

#ifndef _LISTSIMPLE_H
#define _LISTSIMPLE_H

Lista *nuevaListaSencilla (int);

Lista *destruirListaSencilla (Lista *);

void mostarListaSencilla (Lista *);

void insertarListaSencilla (Lista *, int, int);

void eliminarListaSencilla (Lista *, int);

int buscarListaSencilla (Lista *, int);

#endif //_LISTSIMPLE_H

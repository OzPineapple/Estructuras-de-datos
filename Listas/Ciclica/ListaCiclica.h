#include <Listas/Generica/Lista.h>

#ifndef LISTCYCLIC_H
#define LISTCYCLIC_H

typedef struct ListaCiclica_s ListaCiclica;

Lista *nuevaListaCiclica (int);

Lista *destruirListaCiclica (Lista *);

void mostrarListaCiclica (Lista *);

void insertarListaCiclica (Lista *, int, int);

void eliminarListaCiclica (Lista *, int);

int buscarListaCiclica (Lista *, int);

#endif // LISTCYCLIC_H

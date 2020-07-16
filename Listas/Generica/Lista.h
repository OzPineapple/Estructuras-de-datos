#include <Listas/Generica/Nodo.h>

#ifndef _LISTA_H
#define _LISTA_H

struct Lista_s
{
    Nodo * nodo;
};

typedef struct Lista_s Lista;

extern char * conextion_characther;

Lista * crearNodos( int, int, int );

Lista * destruirNodos( Lista *, int );

void mostrarNodos( Lista * , int );

Nodo * ultimoNodo( Lista *, int );

int tamannoNodos( Lista *, int);

Nodo * siguienteNodo( Nodo *, int);

Nodo * obtenerNodo( Lista *, int, int );

int buscarNodos( Lista *, int, int );

Nodo * eliminarNodo( Lista *, int, int);

void annadirNodo( Lista *, Nodo *, int, int);

#endif //_LISTA_H
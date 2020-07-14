#include <Listas/Generica/Nodo.h>

#ifndef _LISTA_H
#define _LISTA_H

struct Lista_s
{
    Nodo * nodo;
};

typedef struct Lista_s Lista;

Nodo * crearNodos( int, int, int );

Nodo * destruirNodos( Nodo *, int );

void mostrarNodos( Nodo * , int );

Nodo * ultimoNodo( Nodo *, int );

int tamannoNodos( Nodo *, int);

Nodo * siguienteNodo( Nodo *, int);

Nodo * obtenerNodo( Nodo *, int, int );

Nodo * eliminarNodo( Nodo *, int, int);

#endif //_LISTA_H
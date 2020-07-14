#ifndef _NODO_H
#define _NODO_H

struct Nodo_s
{
  int valor;
  int n_enlaces;
  struct Nodo_s **enlace;
};

typedef struct Nodo_s Nodo;

Nodo *nuevoNodo (int, int);

Nodo *destruirNodo (Nodo *);

void insertarNodo (Nodo *, int);

void enlazarNodo (Nodo *, Nodo *, int);

void mostrarNodo (Nodo *);

#endif /* _NODO_H */

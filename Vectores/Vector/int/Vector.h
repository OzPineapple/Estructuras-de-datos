#ifndef _VECTOR_H
#define _VECTOR_H

struct Vector_s
{
	int * arreglo;
	int tamanno;
};

typedef struct Vector_s Vector;

Vector * nuevoVector( int );

Vector * destruirVector( Vector * );

void mostrarVector( Vector * );

void insertarVector( Vector * , int, int );

void eliminarVector( Vector *, int );

int buscarVector (Vector *, int);

int leerVector( Vector *, int);

#endif //_VECTOR_H

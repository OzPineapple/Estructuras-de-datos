#ifndef _ARREGLO_H
#define _ARREGLO_H

int *nuevoArreglo (int size);

int *destruirArreglo (int *);

void mostrarArreglo (int *arreglo, int tamanno);

int leerArreglo (int *arreglo, int posicion);

void insertarArreglo (int *arreglo, int posicion, int dato);

void eliminarArreglo (int *arreglo, int posicion);

int buscarArreglo (int *arreglo, int tamanno, int dato);

#endif //_ARREGLO_H

#include <stddef.h>

#ifndef _ARRAY_H
#define _ARRAY_H

int * newArray( size_t size);

int * destroyArray(int * array);

int * resizeArray( int * array, int size, int newSize);

void seeArray(int * array, int size, char * * arrayPhotography, int * arrayPhotographySize);

void printArray(int * array, int size);

int readOnArray( int * array, int size, int pos );

void printFromArray(int * array, int size, int pos);

void writeOnArray(int * array, int size, int pos, int data);

void deleteOnArray(int * array, int size, int pos);

void deleteArray(int * array, int size);

void cloneArray(int * originalArray, int * cloneArray, int size);


#endif //_ARRAY_H

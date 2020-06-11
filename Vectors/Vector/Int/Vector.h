#include <stddef.h>

#ifndef _VECTOR_H
#define _VECTOR_H


struct Vector{
	int * array;
	size_t size;
};

typedef struct Vector Vector_t;

Vector_t * newVector( size_t size );

Vector_t * destroyVector( Vector_t * vector );

void seeVector( Vector_t * vector, char * * vectorPhotography, size_t * vectorPhotographySize);

void printVector(Vector_t * vector);

int readOnVector( Vector_t * vector, size_t pos );

void writeOnVector( Vector_t * vector, size_t pos, int data);

void deleteOnVector( Vector_t * vector, size_t pos);

void deleteVector( Vector_t * vector);

void resizeVector( Vector_t * vector, size_t newSize);

void cloneVector( Vector_t * original, Vector_t * clone );

#endif //_VECTOR_H

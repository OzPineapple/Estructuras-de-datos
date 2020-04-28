#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"

//Struct
struct GenericVector_Struct {
	int length;
	void* array;
};

typedef struct GenericVector_Struct GenericVector;

//Create & destroy
void initGenericVector(GenericVector * generic_vector, int length, int size){
	validateNegative(size);
	generic_vector->length = length;
	generic_vector->array = (int*) calloc(length, size);
	validatePointer(generic_vector->array);
}

void initGenericVectorPointer(GenericVector** generic_vector, int length, int size){
	*generic_vector = (GenericVector*) calloc(1, sizeof(GenericVector));
	initGenericVector(*generic_vector, length, size);
}

void destroyGenericVector(GenericVector * generic_vector){
	free(generic_vector->array);
	free(generic_vector);
}

//Lookers
/* seeGenericVector( GenericVector * generic_vector, char ** generic_vectorPhotography, int * generic_vectorPhotographySize, char* format, type) */
#define seeGenericVector(GenericVector, generic_vectorPhotography, generic_vectorPhotographySize, format, type) ({ \
	validateNegative( generic_vector->length ); \
	\
	*generic_vectorPhotographySize = 1; \
	*generic_vectorPhotography = (char*) calloc(1, sizeof(char)); \
	\
	int elementPhotographySize = 1; \
	char * elementPhotography = 0x0; \
	\
	for(int i = 0; i < generic_vector->length; i++){ \
		elementPhotographySize = snprintf(0x0, 0, format, *( (type*) generic_vector->array + i ) ); \
		elementPhotography = (char*) calloc( elementPhotographySize++, sizeof(char) ); \
		\
		sprintf( elementPhotography, format, *( (type*) generic_vector->array + i ) ); \
		\
		*generic_vectorPhotographySize += elementPhotographySize; \
		*generic_vectorPhotography = (char*) realloc( *generic_vectorPhotography, sizeof(char) * (*generic_vectorPhotographySize) ); \
		validatePointer( *generic_vectorPhotography ); \
		\
		strcat( *generic_vectorPhotography, elementPhotography ); \
		free( elementPhotography ); \
		elementPhotography = 0x0; \
	} \
	free( elementPhotography ); \
})

/* printGenericVector( GenericVector * generic_vector, char* format, type ) */
#define printGenericVector( generic_vector, format, type ) ({ \
	int generic_vectorPhotographySize = 0; \
	char* generic_vectorPhotography = 0x0; \
	seeGenericVector(generic_vector, &generic_vectorPhotography, &generic_vectorPhotographySize, format, type ); \
	printf( "GenericVector:{Length:%i, Array: %s}\n", generic_vector->length, generic_vectorPhotography); \
	free( generic_vectorPhotography ); \
})

/* readFromGenericVector( GenericVector * generic_vector, int pos, int * reader, type ) */
#define readFromGenericVector( generic_vector, pos, reader, type ) ({ \
	validateSizePos( generic_vector->length, pos ); \
	*reader = *( (type*) generic_vector->array + pos ); \
})

/* printFromGenericVector(GenericVector * generic_vector, int pos, type) */
#define printFromGenericVector( generic_vector, pos, format, type ) ({ \
	type reader; \
	readFromGenericVector( generic_vector, pos, &reader, type); \
	printf( format , reader); \
})

//Modifyers
/* writeOnGenericVector( GenericVector * generic_vector, int pos, data) */
#define writeOnGenericVector( generic_vector, pos, data, type) ({ \
	*( (type*) generic_vector->array + pos ) = data; \
})

/* resizeGenericVector( GenericVector * generic_vector, int newLength ) */
#define resizeGenericVector( generic_vector, newLength, type ) ({ \
	validateNegative(newLength); \
	generic_vector->array = (type*) realloc( generic_vector->array, sizeof(type) * newLength ); \
	validatePointer(generic_vector->array); \
})

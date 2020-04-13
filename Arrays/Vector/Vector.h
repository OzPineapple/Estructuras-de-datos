/*Vector Struct
 * by Oz Pinneaple
 *
 * Usage:
 * Include this header file on your program and call the functions you need
*/

#include <stdlib.h>
#include <string.h>
#include "../Array/Array.h"
#include "../../lib/util.h"

typedef struct Vector{
	int * array;
	int size;
} Vector;

int initVector(Vector** vector, int size){
	validateNegative(size);
	*vector = (Vector*) malloc(sizeof(Vector));
	validatePointer(*vector);
	initArray( &((*vector)->array) , size);
	(*vector)->size = size;
	return 0; 	
}

int destroyVector(Vector* vector){
	destroyArray(vector->array);
	free(vector);
	return 0;
}

//Lookers
int seeVector(Vector vector, char** vectorPhotography, int* vectorPhotographySize){
	int vectorSizeStrSize = 0;
	char* vectorSizeStr;
	integerToString(vector.size, &vectorSizeStr, &vectorSizeStrSize);

	int arrayPhotographySize = 0;
	char* arrayPhotography = 0x0; 
	seeArray(vector.array, vector.size, &arrayPhotography, &arrayPhotographySize);

	*vectorPhotographySize = sizeof("{\n\tSize:,\n\tArray:\n}") + arrayPhotographySize + vectorSizeStrSize + 1; 
	*vectorPhotography = (char *) calloc( *vectorPhotographySize, sizeof(char) );
	validatePointer(*vectorPhotography);

	strcat(*vectorPhotography, "{\n\tSize:");		
	strcat(*vectorPhotography, vectorSizeStr);		
	strcat(*vectorPhotography, ",\n\tArray:");		
	strcat(*vectorPhotography, arrayPhotography);		
	strcat(*vectorPhotography, "\n}");		

	free(vectorSizeStr);
	free(arrayPhotography);
	return 0;
}

int printVector(Vector vector){
	int vectorPhotographySize = 0;
	char* vectorPhotography = 0x0;
	seeVector(vector, &vectorPhotography, &vectorPhotographySize);
	printf("Vector:%s\n", vectorPhotography);
	free(vectorPhotography);
	return 0;
}

int readFromVector(Vector vector, int pos, int* reader){
	readFromArray(vector.array, vector.size, pos, reader);
	return 0;
}
//Modifyers
int writeOnVector(Vector** vector, int pos, int data){
	writeOnArray(&((*vector)->array), (*vector)->size, pos, data);
	return 0;
}

int deleteOnVector(Vector** vector, int pos){
	writeOnVector(vector, pos, 0);
	return 0;
}

int deleteVector(Vector** vector){
	for(int i=0; i<(*vector)->size; i+=1){
		deleteOnVector(vector, i);
	}
	return 0;
}

int resizeVector(Vector** vector, int newSize){
	resizeArray( &((*vector)->array), (*vector)->size, newSize);
	(*vector)->size = newSize;
	return 0;
}

int cloneVector(Vector** origin, Vector** clone){
	cloneArray( &((*origin)->array), &((*clone)->array), (*origin)->size);
	return 0;
}

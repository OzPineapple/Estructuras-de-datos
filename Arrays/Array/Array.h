#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../lib/validate.h"

//Create & destroy
int initArray(int * * array, int size){
	valPtr( array );
	valNeg( size );
	*array = (int*) calloc(size, sizeof(int));
	valMem( *array );
	return 0;
}

int destroyArray(int * array){
	valPtr( array );
	free(array);
	return 0;
}

//Lookers
int seeArray(int * array, int size, char * * arrayPhotography, int * arrayPhotographySize){
	valPtr( array );
	valSize( size );
	valPtr( arrayPhotography );
	valPtr( arrayPhotographySize );

	int dataSize = 0;
	char* data = 0x0;

	*arrayPhotographySize = 1; 		
	*arrayPhotography = (char *) calloc(*arrayPhotographySize, sizeof(char));

	for(int i = 0; i < size; i++){
		integerToString(*(array+i), &data, &dataSize);

		*arrayPhotographySize += sizeof(char) * ( 2 + dataSize ); 		
		*arrayPhotography = (char *) realloc(*arrayPhotography,sizeof(char)*(*arrayPhotographySize));
		validatePointer(*arrayPhotography);

		strcat(*arrayPhotography, "[");
		strcat(*arrayPhotography, data);
		strcat(*arrayPhotography, "]");

		free(data);
		data = 0x0;
		dataSize = 0;
	}

	free(data);
	return 0;
}

int printArray(int * array, int size){
	valPtr( array );
	valSize( size );

	int arrayPhotographySize = 0;
	char* arrayPhotography = 0x0;
	seeArray(array, size, &arrayPhotography, &arrayPhotographySize);
	printf("Array:%s\n", arrayPhotography);
	free(arrayPhotography);
	return 0;
}

int readFromArray(int * array, int size, int pos, int* reader){
	valPtr( array );
	valSize( size );
	valNeg( pos );
	valSizePos( size, pos );

	*reader = *(array + pos);
	return 0;	
}

int printFromArray(int * array, int size, int pos){
	valPtr( array );
	valSize( size );
	valNeg( pos );
	valSizePos( size, pos );

	int reader = 0;
	readFromArray(array, size, pos, &reader);
	printf("Arrat[%i]:%i\n", pos, reader);
	return 0;
}

//Modifyers
int writeOnArray(int * * array, int size, int pos, int data){
	val2Ptr( (void**) array );
	valSize( size );
	valNeg( pos );
	valSizePos( size, pos );

	*((*array)+pos) = data;
	return 0;
}

int deleteOnArray(int * * array, int size, int pos){
	val2Ptr( (void**) array );
	valSize( size );
	valNeg( pos );
	valSizePos( size, pos );

	writeOnArray(array,size,pos,0);
	return 0;
}

int deleteArray(int * * array, int size){
	val2Ptr( (void**) array );
	valSize( size );

	for(int i=0; i<size; i+=1){
		deleteOnArray(array,size,i);
	}
	return 0;
}

int cloneArray(int * * originalArray, int * * cloneArray, int size){
	val2Ptr( (void**) originalArray );
	val2Ptr( (void**) cloneArray );
	valSize( size );

	for(int i = 0; i < size; i++) *((*cloneArray)+i) = *((*originalArray)+i);
	return 0;
}

int resizeArray(int** array, int size, int newSize){
	val2Ptr( (void**) array );
	valSize( size );
	valSize( newSize );

	*array = (int*) realloc(*array,sizeof(int)*newSize);
	valMem( *array );

	for(int i = size; i < newSize; i+=1) *( (*array) + i ) = 0;
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../lib/util.h"

//Create & destroy
int initArray(int** array, int size){
	validateNegative(size);
	*array = (int*) calloc(size, sizeof(int));
	validatePointer(*array);
	return 0;
}

int destroyArray(int* array){
	free(array);
	return 0;
}

//Lookers
int seeArray(int* array, int size, char** arrayPhotography, int* arrayPhotographySize){
	validateNegative(size);

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

int printArray(int* array, int size){
	int arrayPhotographySize = 0;
	char* arrayPhotography = 0x0;
	seeArray(array, size, &arrayPhotography, &arrayPhotographySize);
	printf("Array:%s\n", arrayPhotography);
	free(arrayPhotography);
	return 0;
}

int readFromArray(int* array, int size, int pos, int* reader){
	validateSizePos(size, pos);
	*reader = *(array + pos);
	return 0;	
}

int printFromArray(int* array, int size, int pos){
	int reader = 0;
	readFromArray(array, size, pos, &reader);
	printf("Arrat[%i]:%i\n", pos, reader);
	return 0;
}

//Modifyers
int writeOnArray(int** array, int size, int pos, int data){
	*((*array)+pos) = data;
	return 0;
}

int deleteOnArray(int** array, int size, int pos){
	validateSizePos(size,pos);
	writeOnArray(array,size,pos,0);
	return 0;
}

int deleteArray(int** array, int size){
	for(int i=0; i<size; i+=1){
		deleteOnArray(array,size,i);
	}
	return 0;
}

int cloneArray(int** originalArray, int** cloneArray, int size){
	validateNegative(size);
	for(int i = 0; i < size; i++) *((*cloneArray)+i) = *((*originalArray)+i);
	return 0;
}

int resizeArray(int** array, int size, int newSize){
	validateNegative(size);
	*array = (int*) realloc(*array,sizeof(int)*newSize);
	validatePointer(*array);
	for(int i = size; i < newSize; i+=1) *( (*array) + i ) = 0;
	return 0;
}

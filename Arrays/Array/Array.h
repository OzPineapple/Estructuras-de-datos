#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../lib/util.h"

int initArray(int** array, int size){
	if(size<1){
		fprintf(stderr, "The array\'s size most be minimun one");
		exit(EXIT_FAILURE);
	}
	*array = (int*) calloc(size, sizeof(int));
	if(*array == NULL){
		fprintf(stderr, "Couldn\'t reserve memory for array");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int destroyArray(int** array){
	free(*array);
	return 0;
}

int seeArray(int* array, int size, char** arrayPhotography, int* arrayPhotographySize){
	int dataSize = 0;
	char* data = 0x0;

	*arrayPhotographySize = sizeof(char); 		
	*arrayPhotography = (char *) calloc(*arrayPhotographySize, sizeof(char));

	for(int i = 0; i < size; i++){
		integerToString(*(array+i), &data, &dataSize);

		*arrayPhotographySize += sizeof(char) * ( 2 + dataSize ); 		
		*arrayPhotography = (char *) realloc(*arrayPhotography,sizeof(char)*(*arrayPhotographySize));
		if(*arrayPhotography == 0x0){
			fprintf(stderr,"Not enoug memory for array\'s photography");
		       	exit(EXIT_FAILURE);
		}

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
	if(seeArray(array, size, &arrayPhotography, &arrayPhotographySize)){
		fprintf(stderr, "Fuction printArray");
		exit(EXIT_FAILURE);
	}
	printf("Array:%s\n", arrayPhotography);
	free(arrayPhotography);
	return 0;
}

int cloneArray(int** originalArray, int** cloneArray, int arraySize){
	if(arraySize<0){
		fprintf(stderr, "The size of the arrays can\'t be negative");
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < arraySize; i++) *((*cloneArray)+i) = *((*originalArray)+i);
	return 0;
}

int resizeArray(int** array, int arraySize, int newSize){
	if(newSize<0||arraySize<0){ 
		fprintf(stderr, "The size of the arrays can\'t be negative");
		exit(EXIT_FAILURE);
	}
	int * arrayRecovery;
	initArray(&arrayRecovery, arraySize);
	cloneArray(array, &arrayRecovery, arraySize);
	*array = (int*) realloc(*array,sizeof(int)*newSize);
	if(array == NULL){
		*array = (int*) malloc(sizeof(int)*newSize);
		cloneArray(&arrayRecovery, array, arraySize);
	}
	free(arrayRecovery);
	return 0;
}

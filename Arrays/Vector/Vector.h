/*Vector Struct
 * by Oz Pinneaple
 *
 * Usage:
 * Include this header file on your program and call the functions you need
 *
 * Code status can be see on documentation or the getError funtion
*/

#include <stdlib.h>
#include <string.h>
#include "../Array/Array.h"
#include "../../Globals/global_err_def.h"
#include "../../Globals/global_util_fun.h"

/* Vector struture */
typedef struct Vector{
	int * array;
	int size;
} Vector;

/* Vector funtions */
//Init vector with default values
int initVector(Vector * vector, int size){
	if(size < 0) return UNDERFLOW_VALUE;
	vector->array = (int*) malloc(sizeof(int)*size);
	if(vector->array==NULL) return RESERVE_MEMORY_FAIL; 
	vector->size = size; return 0; 	
}

//Change the size of the vector without delete data
int resizeVector(Vector * vector, int newSize, int size){
	if(size < 0) return UNDERFLOW_VALUE;
	int ErrorCode = resizeArray(vector->array, vector->size, newSize);
	if(ErrorCode>0) return ErrorCode;
	vector->size = newSize;
	return 0;
}
//Get a string with a visual inforamtion of the vector
int seeVector(Vector * vector, char ** vectorPhotography, int* vectorPhotographySize){
	int vectorSizeStrSize = 0;
	char * vectorSizeStr;
	
	int ERROR = integerToString(vector->size, &vectorSizeStr, &vectorSizeStrSize);
	if(ERROR>0) {
		free(vectorSizeStr);
		return ERROR;
	}

	int arrayPhotographySize = 0;
	char * arrayPhotography = (char *) calloc(0, sizeof(char));;

	ERROR = seeArray(vector->array, vector->size, &arrayPhotography, &arrayPhotographySize);
	if(ERROR>0){
		free(vectorSizeStr);
	 	free(arrayPhotography);	
		return ERROR;
	}

	free(*vectorPhotography); *vectorPhotography = 0x0;
	*vectorPhotographySize = sizeof("{\n\tSize:,\n\tArray:,\n}") + sizeof(arrayPhotographySize) + sizeof(vectorSizeStrSize); 
	*vectorPhotography = (char *) malloc( *vectorPhotographySize );
	if(*vectorPhotography == 0x0){
		free(vectorSizeStr);
	 	free(arrayPhotography);	
		return RESERVE_MEMORY_FAIL;
	}

	strcat(*vectorPhotography, "{\n\tSize:");		
	strcat(*vectorPhotography, vectorSizeStr);		
	strcat(*vectorPhotography, ",\n\tArray:");		
	strcat(*vectorPhotography, arrayPhotography);		
	strcat(*vectorPhotography, ",\n}");		

	free(vectorSizeStr);
	free(arrayPhotography);
	return 0;
}

int printVector(Vector* vector){
	int vectorPhotographySize = 0;
	char* vectorPhotography = 0x0;
	int err = seeVector(vector, &vectorPhotography, &vectorPhotographySize);
	if(err) {
		free(vectorPhotography);
		return err;
	}
	printf("Vector:%s\n", vectorPhotography);
	free(vectorPhotography);
	return 0;
}

//Read a value from the vector
int readFromVector(Vector * vector, int pos, int * reader){
	if(pos<0) return UNDERFLOW_VALUE;
	if(pos>vector->size-1) return OVERFLOW_VALUE;
	*reader=*( (vector->array) + pos);
	return 0;
}

//Write a value on the vector
int writeOnVector(Vector * vector, int pos, int data){
	if(pos<0) return UNDERFLOW_VALUE;
	if(pos>(vector->size - 1)) return OVERFLOW_VALUE;
	*((vector->array) + pos) = data;
	return 0;
}

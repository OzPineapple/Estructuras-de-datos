#include <stdlib.h>
#include <string.h>
#include "../../Globals/global_err_def.h"
#include "../../Globals/global_util_fun.h"

int initArray(int * array, int size){
	if(size<0) return UNDERFLOW_VALUE;
	array = (int*) malloc(sizeof(int)*size);
	if(array == NULL) return RESERVE_MEMORY_FAIL;
	for(int i = 0; i < size; i++) array[i] == 0;
	return 0;
}

int destroyArray(int * array){
	free(array);
	return 0;
}

int seeArray(int * array, int size, char** arrayPhotography, int* arrayPhotographySize){
	int ERROR = 0;
	int dataSize = 0;
	char* data = 0x0;
	*arrayPhotographySize = 0;

	for(int i = 0; i < size; i++){
		ERROR = integerToString(*(array+i), &data, &dataSize);
		if(ERROR) return ERROR;

		*arrayPhotographySize += sizeof(char) * ( 2 + dataSize ); 
		
		if(arrayPhotography == 0x0 ){
			*arrayPhotography = (char *) malloc(*arrayPhotographySize);
			if(*arrayPhotography == 0x0) return RESERVE_MEMORY_FAIL; 	
		}else{
			*arrayPhotography = (char *) realloc(*arrayPhotography, *arrayPhotographySize);
			if(*arrayPhotography == 0x0) return RESERVE_MEMORY_FAIL; 	
		}

		strcat(*arrayPhotography, "[");
		strcat(*arrayPhotography, data);
		strcat(*arrayPhotography, "]");
	}

	free(data);
	return 0;
}

int cloneArray(int * originalArray, int * cloneArray, int arraySize){
	if(arraySize<0) return UNDERFLOW_VALUE;
	for(int i = 0; i < arraySize; i++) cloneArray[i] = originalArray[i];
	return 0;
}

int resizeArray(int * array, int arraySize, int newSize){
	if(newSize<0||arraySize<0) return UNDERFLOW_VALUE;
	int ErrorCode;
	int * arrayRecovery;
	ErrorCode = initArray(arrayRecovery, arraySize);
	if(ErrorCode>0) return ErrorCode;
	ErrorCode = cloneArray( array, arrayRecovery, arraySize);
	if(ErrorCode>0) return ErrorCode;
	array = (int*) realloc(array,sizeof(int)*newSize);
	if(array == NULL){
		array = (int*) malloc(sizeof(int)*newSize);
		ErrorCode = cloneArray(arrayRecovery, array, arraySize);
		if(ErrorCode>0) return ErrorCode;
	}
	free(arrayRecovery);
	return 0;
}

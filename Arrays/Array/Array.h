#include <stdlib.h>
#include "../../Globals/global_err_def.h"

int initArray(int * array, int size){
	if(size<0) return UNDERFLOW_VALUE;
	array = (int*) malloc(sizeof(int)*size);
	if(array == NULL) return RESERVE_MEMORY_FAIL;
	return 0;
}

int destroyArray(int * array){
	free(array);
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
int cloneArray(int * originalArray, int * cloneArray, int arraySize){
	if(arraySize<0) return UNDERFLOW_VALUE;
	for(int i = 0; i < arraySize; i++) cloneArray[i] = originalArray[i];
	return 0;
}

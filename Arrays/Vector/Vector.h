/*Vector Struct
 * by Oz Pinneaple
 *
 * Usage:
 * Include this header file on your program and call the functions you need
 *
 * Code status can be see on documentation or the getError funtion
*/

#include <stdlib.h>
#include "../Array/Array.h"

/* Vector struture */
typedef struct Vector{
	int * array;
	int size;
} Vector;

int initVector(Vector * vector, int size){
	if(size < 0) return 401;
	vector->array = (int*) malloc(sizeof(int)*size);
	if(vector->array==NULL) return 510;
	vector->size = size;
	return 0;
}	

int resizeVector(Vector * vector, int newSize){
	if(size < 0) return 401;
	int ErrorCode = resizeArray(vector->array, vector->size, newSize);
	if(ErrorCode>0) return ErrorCode;
	vector->size = newSize;
	return 0;
}

int seeVector(Vector * vector, char * buffer){
	
}

int readFromVector(Vector * vector, int pos, int * reader){
	if(pos<0) return 401;
	if(pos>vector->size-1) return 402;
	*reader=vector->array[pos];
	return 0;
}

int writeOnVector(Vector * vector, int pos, int data){
	if(pos<0) return 401;
	if(pos>(vector->size - 1)) return 402;
	(vector->array)[pos] = data;
	return 0;
}

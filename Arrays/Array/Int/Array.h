// Include local
#include <lib/validate.h>
#include <lib/util.h>

//Include standar
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

//Create & destroy
int * newArray( size_t size){
	valNeg( size );
	int * array = ( int * ) calloc(size, sizeof( int )  );
	valMem( array );
	return array;
}

int * destroyArray(int * array){
	if( array == 0x0 ) return 0x0;
	free(array);
	return 0x0;
}

int * resizeArray( int * array, int size, int newSize){
	valPtr( array );
	valSize( size );
	valSize( newSize );

	array = ( int * ) realloc( array, sizeof( int ) * newSize);
	valMem( array );

	for(int i = size; i < newSize; i+=1)
		*( array  + i ) = 0;
	return array;
}

//Lookers
void seeArray(int * array, int size, char * * arrayPhotography, int * arrayPhotographySize){
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
		valPtr( *arrayPhotography );

		strcat(*arrayPhotography, "[");
		strcat(*arrayPhotography, data);
		strcat(*arrayPhotography, "]");

		free(data);
		data = 0x0;
		dataSize = 0;
	}

	free(data);
}

void printArray(int * array, int size){
	if( array == 0x0 ) {
		printf( "(nil)" );
		return;
	}
	valSize( size );

	int arrayPhotographySize = 0;
	char* arrayPhotography = 0x0;
	seeArray(array, size, &arrayPhotography, &arrayPhotographySize);
	printf("Array:%s", arrayPhotography);
	free(arrayPhotography);
}

int readOnArray( int * array, int size, int pos ){
	valPtr( array );
	valSize( size );
	valNeg( pos );
	valSizePos( size, pos );

	return *(array + pos);	
}

void printFromArray(int * array, int size, int pos){
	valPtr( array );
	valSize( size );
	valNeg( pos );
	valSizePos( size, pos );

	printf("Arrat[%i]:%i", pos, readOnArray( array, size, pos ) );
}

//Modifyers
void writeOnArray(int * array, int size, int pos, int data){
	valPtr( array );
	valSize( size );
	valNeg( pos );
	valSizePos( size, pos );

	*( array + pos ) = data;
}

void deleteOnArray(int * array, int size, int pos){
	valPtr( array );
	valSize( size );
	valNeg( pos );
	valSizePos( size, pos );

	writeOnArray( array, size, pos, 0);
}

void deleteArray(int * array, int size){
	valPtr( array );
	valSize( size );

	for(int i=0; i<size; i+=1){
		deleteOnArray( array, size, i );
	}
}

void cloneArray(int * originalArray, int * cloneArray, int size){
	valPtr( originalArray );
	valPtr( cloneArray );
	valSize( size );

	for(int i = 0; i < size; i++)
		*( cloneArray + i ) = *( originalArray + i );
}

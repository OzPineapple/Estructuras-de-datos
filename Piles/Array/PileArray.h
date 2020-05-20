// Include local
#include <lib/validate.h>
#include <Arrays/Array/Array.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>

#ifndef PILEARRAY_H
#define PILEARRAY_H

// Init & destroy

struct PileArray {
	size_t length;
	int * array;
};

typedef struct PileArray PileArray_t;

void initPileArray( PileArray_t * pile, size_t length ){
	valPtr( pile );
	valSize( length );
	pile -> length = length;
	initArray( &( pile -> array ), pile -> length );
}

void initPileArrayPointer( PileArray_t * * pile, size_t length ){
	valPtr( pile );
	valSize( length );
	*pile = ( PileArray_t * ) calloc( 1, sizeof( PileArray_t ) );
	initPileArray( *pile, length );
}

void destroyPileArray( PileArray_t * * pile ){
	valPtr( pile );
	if( *pile == 0x0 ) return;
	destroyArray( (*pile) -> array );
	free( *pile );
	*pile =	0x0;
	return;
}

// Lookers

void printPileArray( PileArray_t * pile ){
	if( pile == 0x0 ){
		printf( "{(nil)}\n" );
		return;
	}
	int size;
	char * photo;
	seeArray( pile -> array, pile -> length, &photo, &size );
	printf( "Pile{ length: %i, array:%s }\n", (int) pile -> length, photo );
}

int readOnPileArray( PileArray_t * pile, size_t pos ){
	valPtr( pile );
	valSizePos( pile -> length, pos );
	int reader;
	readFromArray( pile -> array, pile -> length, pos, &reader);
	return reader;
}

// Modifiers

void pileArrayPush( PileArray_t * pile, int value ){
	valPtr( pile );
	resizeArray( &(pile -> array), pile -> length, pile -> length + 1 ); 
	pile -> length ++;
	writeOnArray( &( pile -> array ), pile -> length, pile -> length - 1, value );
}

int pileArrayPop( PileArray_t * pile ){
	valPtr( pile );
	int value = 0;
	readFromArray( pile -> array, pile -> length, pile -> length - 1, & value );
	resizeArray( &( pile -> array ), pile -> length, pile -> length - 1 );
	pile -> length --;
	return value;	
}

void writeOnPileArray( PileArray_t * pile, size_t pos, int value ){
	valPtr( pile );
	valSizePos( pile -> length, pos );
	writeOnArray( & (pile -> array), pile -> length,  pos, value );
}

#endif //PILEARRAY_H

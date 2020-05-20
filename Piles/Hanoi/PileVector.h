// Include local
#include <lib/validate.h>
#include <Vectors/Vector/Vector.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>

#ifndef PILEVECTOR_H
#define PILEVECTOR_H

// Init & destroy

struct PileVector {
	size_t length;
	int * array;
};

typedef struct PileVector PileVector_t;

void newPileVector( size_t length ){
	valPtr( pile );
	valSize( length );
	*pile = ( PileVector_t * ) calloc( 1, sizeof( PileVector_t ) );
	initPileVector( *pile, length );
}

void destroyPileVector( PileVector_t * * pile ){
	valPtr( pile );
	if( *pile == 0x0 ) return;
	destroyVector( (*pile) -> array );
	free( *pile );
	*pile =	0x0;
	return;
}

// Lookers

void printPileVector( PileVector_t * pile ){
	if( pile == 0x0 ){
		printf( "{(nil)}\n" );
		return;
	}
	int size;
	char * photo;
	seeVector( pile -> array, pile -> length, &photo, &size );
	printf( "Pile{ length: %i, array:%s }\n", (int) pile -> length, photo );
}

int readOnPileVector( PileVector_t * pile, size_t pos ){
	valPtr( pile );
	valSizePos( pile -> length, pos );
	int reader;
	readFromVector( pile -> array, pile -> length, pos, &reader);
	return reader;
}

// Modifiers

void pileVectorPush( PileVector_t * pile, int value ){
	valPtr( pile );
	resizeVector( &(pile -> array), pile -> length, pile -> length + 1 ); 
	pile -> length ++;
	writeOnVector( &( pile -> array ), pile -> length, pile -> length - 1, value );
}

int pileVectorPop( PileVector_t * pile ){
	valPtr( pile );
	int value = 0;
	readFromVector( pile -> array, pile -> length, pile -> length - 1, & value );
	resizeVector( &( pile -> array ), pile -> length, pile -> length - 1 );
	pile -> length --;
	return value;	
}

void writeOnPileVector( PileVector_t * pile, size_t pos, int value ){
	valPtr( pile );
	valSizePos( pile -> length, pos );
	writeOnVector( & (pile -> array), pile -> length,  pos, value );
}

#endif //PILEVECTOR_H

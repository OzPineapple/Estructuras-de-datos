// Include local
#include <lib/validate.h>
#include <Lists/Simple/ListSimple.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>

#ifndef PILELIST_H
#define PILELIST_H

// Init & destroy

struct PileList {
	size_t length;
	Node_t * list;
};

typedef struct PileList PileList_t;

void initPileList( PileList_t * pile, size_t length ){
	valPtr( pile );
	valSize( length );
	pile -> length = length;
	initListSimplePointer( &( pile -> list ), pile -> length );
}

void initPileListPointer( PileList_t * * pile, size_t length ){
	valPtr( pile );
	valSize( length );
	*pile = ( PileList_t * ) calloc( 1, sizeof( PileList_t ) );
	initPileList( *pile, length );
}

void destroyPileList( PileList_t * * pile ){
	valPtr( pile );
	if( *pile == 0x0 ) return;
	destroyListSimple( (*pile) -> list );
	free( *pile );
	*pile =	0x0;
	return;
}

// Lookers

void printPileList( PileList_t * pile ){
	if( pile == 0x0 ){
		printf( "{(nil)}\n" );
		return;
	}
	printf( "Pile length: %i: ", (int) pile -> length );
	printListSimple( pile -> list );
}

int readOnPileList( PileList_t * pile, size_t pos ){
	valPtr( pile );
	valSizePos( pile -> length, pos );
	return readOnListSimple( pile -> list, pos );
}

// Modifiers

void pileListPush( PileList_t * pile, int value ){
	valPtr( pile );
	Node_t * node = 0x0;
	initNodePointer( &node, value, 1 );
	listSimpleInsert( &( pile -> list ), node );
	pile -> length ++;
}

int pileListPop( PileList_t * pile ){
	valPtr( pile );
	Node_t  * node =  popFirstNodeOnListSimpleNlink( &(pile -> list) );
	int value = node -> value;
	destroyNode( node );
	pile -> length --;
	return value;	
}

void writeOnPileList( PileList_t * pile, size_t pos, int value ){
	valPtr( pile );
	valSizePos( pile -> length, pos );
	writeOnListSimple( pile -> list, pos, value );
}

#endif //PILELIST_H

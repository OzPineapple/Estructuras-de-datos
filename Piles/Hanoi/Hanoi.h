// Include local
#include <lib/validate.h>
#include <lib/util.h>
#include <Piles/Vector/PileVector.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>

#ifndef PILEARRAY_H
#define PILEARRAY_H

struct Hanoi {
	size_t length;
	Vector_t * lv;
	Vector_t * mv;
	Vector_t * rv;
};

typedef struct Hanoi Hanoi_t;

Hanoi_t * newHanoi( size_t length ){
	valSize( length );
	Hanoi_t * hanoi = ( Hanoi_t * ) calloc( 1, sizeof( Hanoi_t ) );
	valMem( hanoi );
	hanoi -> length = length;
	hanoi -> rv = 0x0;
	hanoi -> mv = 0x0;
	hanoi -> lv = newVector( length );
	for( size_t i = 0, j = length; i < length; i++, j-- )
		writeOnVector( hanoi -> lv, i, j );
	return hanoi;
}

Hanoi_t * destroyHanoi( Hanoi_t * hanoi ){
	if( hanoi == 0x0 ) return 0x0;
	hanoi -> lv = destroyVector( hanoi -> lv );
	hanoi -> mv = destroyVector( hanoi -> mv );
	hanoi -> rv = destroyVector( hanoi -> rv );
	free( hanoi );
	return 0x0;
}

void printHanoi( Hanoi_t * hanoi ){
	if( hanoi == 0x0 ){
		printf( "(nil)" );
		return;
	}

	printf( "{ length: %i\n", (int) hanoi -> length );
	printtb;
	printVector( hanoi -> lv );
	println;
	printtb;
	printVector( hanoi -> mv );
	println;
	printtb;
	printVector( hanoi -> rv );
	println;
	printf( "}" );
}


static void solve_hanoi_recursive( Hanoi_t * hanoi, size_t discs, Vector_t * * origin, Vector_t * * meta, Vector_t * * aux ){
	if( discs == 0 ) return;
	solve_hanoi_recursive( hanoi, discs - 1, origin, aux, meta );
 	* meta = pileVectorPush( * meta, pileVectorPop( origin ) );
	printHanoi( hanoi );
	println;
	solve_hanoi_recursive( hanoi, discs - 1, aux, meta, origin );
}

void solveHanoi( Hanoi_t * hanoi ){
	valPtr( hanoi );
	solve_hanoi_recursive( hanoi, hanoi -> length , &( hanoi -> lv ), &( hanoi -> rv ) , &( hanoi -> mv ) );
}

#endif //PILEARRAY_H

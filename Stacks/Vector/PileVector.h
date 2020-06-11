// Include local
#include <lib/validate.h>
#include <Arrays/Vector/Int/Vector.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>

#ifndef PILEVECTOR_H
#define PILEVECTOR_H

Vector_t * pileVectorPush( Vector_t * pile, int value ){
	if( pile == 0x0 ){
		pile = newVector( 1 );
		writeOnVector( pile, 0, value );
		return pile;
	}
	resizeVector( pile, pile -> size + 1 );
	writeOnVector( pile, pile -> size - 1, value );
	return pile;
}

int pileVectorPop( Vector_t * * pile_ptr ){
	Vector_t * pile = * pile_ptr;
	if( pile == 0x0 ){
		return 0;
	}
	if( pile -> size == 1 ){
		int value = readOnVector( pile, 0 );
		 * pile_ptr = destroyVector( pile );
		 return value;
	}
	int value = readOnVector( pile, pile -> size - 1 );
	resizeVector( pile,  pile -> size - 1 );
	return value;
}

#endif //PILEVECTOR_H

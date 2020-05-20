// Local headers
#include <lib/validate.h>
#include <lib/util.h>
#include "PileArray.h"

// Standar headers
#include <time.h>
#include <stdio.h>

int main( int argc, char * argv[] ){
	srand( time(NULL) );
	printf( "PileArray tester\n" );
	
	printf( "\nPileArray.h - Init\n" );
	PileArray_t * pile_array = 0x0;
	initPileArrayPointer( &pile_array, randomInRange( 1, 3 ) );

	printf( "\nPileArray.h - Print\n" );
	printPileArray( pile_array );

	printf( "\nPileArray.h - Push\n" );
	for( size_t index = 0; index < 4; index++)
		pileArrayPush( pile_array, randomInRange( -100, 100 ) );
	printPileArray( pile_array );

	printf( "\nPileArray.h - Pop\n" );
	for( size_t index = 0; index < 4; index++)
		printf( "[%i]" , pileArrayPop( pile_array ) );
	printf( "\n" );
	printPileArray( pile_array );

	printf( "\nPileArray.h - Write\n" );
	for( size_t index = 0; index < 7; index++)
		writeOnPileArray( pile_array, randomInRange( 0, pile_array -> length - 1 ), randomInRange( -100, 100 ) );
	printPileArray( pile_array );

	printf( "\nPileArray.h - Read\n" );
	for( size_t index = 0; index < 7; index++)
		printf( "[%i]",	readOnPileArray( pile_array, randomInRange( 0, pile_array -> length - 1 ) ) );
	printf( "\n" );
	printPileArray( pile_array );

	printf( "\nPileArray.h - Destroy\n" );
	destroyPileArray( &pile_array );
	printPileArray( pile_array );
}

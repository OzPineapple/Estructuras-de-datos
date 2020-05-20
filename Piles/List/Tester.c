// Local headers
#include <lib/validate.h>
#include <lib/util.h>
#include "PileList.h"

// Standar headers
#include <time.h>
#include <stdio.h>

int main( int argc, char * argv[] ){
	srand( time(NULL) );
	printf( "PileList tester\n" );
	
	printf( "\nPileList.h - Init\n" );
	PileList_t * pile_list = 0x0;
	initPileListPointer( &pile_list, randomInRange( 1, 3 ) );

	printf( "\nPileList.h - Print\n" );
	printPileList( pile_list );

	printf( "\nPileList.h - Push\n" );
	for( size_t index = 0; index < 4; index++)
		pileListPush( pile_list, randomInRange( -100, 100 ) );
	printPileList( pile_list );

	printf( "\nPileList.h - Pop\n" );
	for( size_t index = 0; index < 4; index++)
		printf( "[%i]" , pileListPop( pile_list ) );
	printf( "\n" );
	printPileList( pile_list );

	printf( "\nPileList.h - Write\n" );
	for( size_t index = 0; index < 7; index++)
		writeOnPileList( pile_list, randomInRange( 0, pile_list -> length - 1 ), randomInRange( -100, 100 ) );
	printPileList( pile_list );

	printf( "\nPileList.h - Read\n" );
	for( size_t index = 0; index < 7; index++)
		printf( "[%i]",	readOnPileList( pile_list, randomInRange( 0, pile_list -> length - 1 ) ) );
	printf( "\n" );
	printPileList( pile_list );

	printf( "\nPileList.h - Destroy\n" );
	destroyPileList( &pile_list );
	printPileList( pile_list );
}

// Local headers
#include <lib/util.h>
#include "PileVector.h"

// Standar headers
#include <time.h>
#include <stdio.h>

int main( int argc, char * argv[] ){
	srand( time(NULL) );
	printf( "Pile vector tester\n" );
	
	printf( "\nPileVector.h - Init\n" );
	Vector_t * pile = newVector( randomInRange( 1, 10 ) );
	printVector( pile );
	println;

	printf( "\nPileVector.h - Push\n" );
	for( size_t i = 0; i < randomInRange( 1, 10 ); i++ )
		pile = pileVectorPush( pile, randomInRange( -100, 100 ) );
	printVector( pile );
	println;

	printf( "\nPileVector.h - Pop\n" );
	for( size_t i = 0; i < randomInRange( 1, 10 ); i++ )
		printf( "[%i]", pileVectorPop( & pile ) ); 
	println;
	printVector( pile );
	println;

	printf( "\nPileVector.h - Destroy\n" );
	pile = destroyVector( pile );
	printVector( pile );
	println;
}

// Local headers
#include <lib/validate.h>
#include <lib/util.h>
#include " Hanoi.h"

// Standar headers
#include <time.h>
#include <stdio.h>

int main( int argc, char * argv[] ){
	srand( time(NULL) );
	printf( "Hanoi tester\n" );
	
	printf( "\nHanoi.h - Init\n" );
	int size = 0;
	scanf( "%i", size );
	Hanoi_t * hanoi = newHanoi( size );
	printHanoi( hanoi );

	printf( "\nPileArray.h - Destroy\n" );
	hanoi =	destroyHanoi( hanoi );
	printHanoi( hanoi );
}

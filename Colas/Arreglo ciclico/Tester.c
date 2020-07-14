// Local headers
#include <lib/validate.h>
#include <lib/util.h>
#include "QueueArrayCyclic.h"

// Standar headers
#include <time.h>
#include <stdio.h>

int main( int argc, char * argv[] ){
	srand( time(NULL) );
	printf( "QueueArrayCyclic tester\n" );
	
	printf( "\nQueueArrayCyclic.h - Init\n" );
	QueueArrayCyclic_t * queue_array = newQueueArrayCyclic( randomInRange( 1, 5 ) );

	printf( "\nQueueArrayCyclic.h - Write and print\n" );
	for( size_t index = 0; index < queue_array -> length; index++)
		writeOnArray( queue_array -> array, queue_array -> length, index, randomInRange( -100, 100 ) );
	printQueueArrayCyclic( queue_array );
	println;

	printf( "\nQueueArrayCyclic.h - Write\n" );
	for( size_t index = 0; index < randomInRange( 1,5 ); index++)
		writeOnQueueArrayCyclic( queue_array, randomInRange( 0, queue_array -> length - 1 ), randomInRange( -100, 100 ) );
	printQueueArrayCyclic( queue_array );
	println;

	printf( "\nQueueArrayCyclic.h - Read\n" );
	for( size_t index = 0; index < randomInRange( 1,5 ); index++)
		printf( "[%i]",	readOnQueueArrayCyclic( queue_array, randomInRange( 0, queue_array -> length - 1 ) ) );
	printf( "\n" );
	printQueueArrayCyclic( queue_array );
	println;


	printf( "\nQueueArrayCyclic.h - Push\n" );
	for( size_t index = 0; index < randomInRange( 1, 5 ); index++)
		queueArrayPush( queue_array, randomInRange( -100, 100 ) );
	printQueueArrayCyclic( queue_array );
	println;

	printf( "\nQueueArrayCyclic.h - Pop\n" );
	for( size_t index = 0; index < randomInRange( 1,5 ); index++)
		printf( "[%i]" , queueArrayPop( queue_array ) );
	printf( "\n" );
	printQueueArrayCyclic( queue_array );
	println;

	printf( "\nQueueArrayCyclic.h - Destroy\n" );
	queue_array = destroyQueueArrayCyclic( queue_array );
	printQueueArrayCyclic( queue_array );
	println;
}

// Local headers
#include <lib/validate.h>
#include <lib/util.h>
#include "QueueList.h"

// Standar headers
#include <time.h>
#include <stdio.h>

int main( int argc, char * argv[] ){
	srand( time(NULL) );
	printf( "QueueList tester\n" );
	
	printf( "\nQueueList.h - Init\n" );
	QueueList_t * queue_list = 0x0;
	initQueueListPointer( &queue_list, randomInRange( 1, 3 ) );

	printf( "\nQueueList.h - Print\n" );
	printQueueList( queue_list );

	printf( "\nQueueList.h - Push\n" );
	for( size_t index = 0; index < 4; index++)
		queueListPush( queue_list, randomInRange( -100, 100 ) );
	printQueueList( queue_list );

	printf( "\nQueueList.h - Pop\n" );
	for( size_t index = 0; index < 4; index++)
		printf( "[%i]" , queueListPop( queue_list ) );
	printf( "\n" );
	printQueueList( queue_list );

	printf( "\nQueueList.h - Write\n" );
	for( size_t index = 0; index < 7; index++)
		writeOnQueueList( queue_list, randomInRange( 0, queue_list -> length - 1 ), randomInRange( -100, 100 ) );
	printQueueList( queue_list );

	printf( "\nQueueList.h - Read\n" );
	for( size_t index = 0; index < 7; index++)
		printf( "[%i]",	readOnQueueList( queue_list, randomInRange( 0, queue_list -> length - 1 ) ) );
	printf( "\n" );
	printQueueList( queue_list );

	printf( "\nQueueList.h - Destroy\n" );
	destroyQueueList( &queue_list );
	printQueueList( queue_list );
}

// Include local
#include <lib/validate.h>
#include <Lists/Simple/ListSimple.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>

#ifndef QUEUELIST_H
#define QUEUELIST_H

// Init & destroy

struct QueueList {
	size_t length;
	Node_t * list;
};

typedef struct QueueList QueueList_t;

void initQueueList( QueueList_t * queue, size_t length ){
	valPtr( queue );
	valSize( length );
	queue -> length = length;
	initListSimplePointer( &( queue -> list ), queue -> length );
}

void initQueueListPointer( QueueList_t * * queue, size_t length ){
	valPtr( queue );
	valSize( length );
	*queue = ( QueueList_t * ) calloc( 1, sizeof( QueueList_t ) );
	initQueueList( *queue, length );
}

void destroyQueueList( QueueList_t * * queue ){
	valPtr( queue );
	if( *queue == 0x0 ) return;
	destroyListSimple( (*queue) -> list );
	free( *queue );
	*queue =	0x0;
	return;
}

// Lookers

void printQueueList( QueueList_t * queue ){
	if( queue == 0x0 ){
		printf( "{(nil)}\n" );
		return;
	}
	printf( "Queue length: %i: ", (int) queue -> length );
	printListSimple( queue -> list );
}

int readOnQueueList( QueueList_t * queue, size_t pos ){
	valPtr( queue );
	valSizePos( queue -> length, pos );
	return readOnListSimple( queue -> list, pos );
}

// Modifiers

void queueListPush( QueueList_t * queue, int value ){
	valPtr( queue );
	Node_t * node = 0x0;
	initNodePointer( &node, value, 1 );
	listSimpleInsert( &( queue -> list ), node );
	queue -> length ++;
}

int queueListPop( QueueList_t * queue ){
	valPtr( queue );
	Node_t  * node =  popLastNodeOnListSimpleNlink( queue -> list );
	int value = node -> value;
	destroyNode( node );
	queue -> length --;
	return value;	
}

void writeOnQueueList( QueueList_t * queue, size_t pos, int value ){
	valPtr( queue );
	valSizePos( queue -> length, pos );
	writeOnListSimple( queue -> list, pos, value );
}

#endif //QUEUELIST_H

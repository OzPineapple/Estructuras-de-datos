// Include local
#include <lib/validate.h>
#include <Array/Array/Int/Array.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>

#ifndef QUEUEARRAYCYCLIC_H
#define QUEUEARRAYCYCLIC_H

// Init & destroy

struct QueueArrayCyclic {
	size_t length;
	int * array;
};

typedef struct QueueArrayCyclic QueueArrayCyclic_t;

QueueArrayCyclic_t * newQueueArrayCyclic( size_t length ){
	valSize( length );
	QueueArrayCyclic_t * queue = ( QueueArrayCyclic_t * ) calloc( 1, sizeof( QueueArrayCyclic_t ) );
	queue -> length = length;
	queue -> array = newArrayCyclic( queue -> length );
	return queue;
}

QueueArrayCyclic_t * destroyQueueArrayCyclic( QueueArrayCyclic_t * queue ){
	if( queue == 0x0 ) return 0x0;
	destroyArrayCyclic( queue -> array );
	free( queue );
	return 0x0;
}

// Lookers

void printQueueArrayCyclic( QueueArrayCyclic_t * queue ){
	if( queue == 0x0 ){
		printf( "(nil)" );
		return;
	}
	if( queue -> array == 0x0 ){
		printf( "{ length: 0, array: (nil) }\n" );
		return;
	}
	int size;
	char * photo;
	seeArrayCyclic( queue -> array, queue -> length, &photo, &size );
	printf( "{ length: %i, array:%s }", (int) queue -> length, photo );
}

int readOnQueueArrayCyclic( QueueArrayCyclic_t * queue, size_t pos ){
	valPtr( queue );
	valSizePos( queue -> length, pos );
	return readOnArrayCyclic( queue -> array, queue -> length, pos );
}

// Modifiers

QueueArrayCyclic_t * queueArrayCyclicPush( QueueArrayCyclic_t * queue, int value ){
	if( queue == 0x0 ){
		queue -> array = newArrayCyclic( 1 );
		writeOnArrayCyclic( queue -> array, queue -> length, 0, value );
		return queue;
	}
	queue -> array = resizeArrayCyclic( queue -> array, queue -> length, queue -> length + 1 ); 
	queue -> length ++;
	writeOnArrayCyclic( queue -> array, queue -> length, queue -> length - 1, value );
	return queue;
}

int queueArrayCyclicPop( QueueArrayCyclic_t * queue ){
	if( queue -> array == 0x0 ){
		return 0;
	}
	if( queue -> length == 1 ){
		int value = readOnArrayCyclic( queue -> array, queue -> length, 0 );
		queue -> array = destroyArrayCyclic( queue -> array );
		queue -> length = 0;
		return value;
	}
	int value = readOnArrayCyclic( queue -> array, queue -> length, 0 );
	for( size_t i = 0, j = 1; j < queue -> length; i++, j++ ){
		writeOnArrayCyclic( queue -> array, queue -> length, i, readOnArrayCyclic( queue -> array, queue -> length, j ) );
	}
	resizeArrayCyclic(  queue -> array , queue -> length, queue -> length - 1 );
	queue -> length --;
	return value;	
}

void writeOnQueueArrayCyclic( QueueArrayCyclic_t * queue, size_t pos, int value ){
	valPtr( queue );
	valSizePos( queue -> length, pos );
	writeOnArrayCyclic( queue -> array, queue -> length,  pos, value );
}

#endif //QUEUEARRAYCYCLIC_H

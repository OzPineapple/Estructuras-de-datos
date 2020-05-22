// Include local
#include <lib/validate.h>
#include <Arrays/Array/Int/Array.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

// Init & destroy

struct QueueArray {
	size_t length;
	int * array;
};

typedef struct QueueArray QueueArray_t;

QueueArray_t * newQueueArray( size_t length ){
	valSize( length );
	QueueArray_t * queue = ( QueueArray_t * ) calloc( 1, sizeof( QueueArray_t ) );
	queue -> length = length;
	queue -> array = newArray( queue -> length );
	return queue;
}

QueueArray_t * destroyQueueArray( QueueArray_t * queue ){
	if( queue == 0x0 ) return 0x0;
	destroyArray( queue -> array );
	free( queue );
	return 0x0;
}

// Lookers

void printQueueArray( QueueArray_t * queue ){
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
	seeArray( queue -> array, queue -> length, &photo, &size );
	printf( "{ length: %i, array:%s }", (int) queue -> length, photo );
}

int readOnQueueArray( QueueArray_t * queue, size_t pos ){
	valPtr( queue );
	valSizePos( queue -> length, pos );
	return readOnArray( queue -> array, queue -> length, pos );
}

// Modifiers

QueueArray_t * queueArrayPush( QueueArray_t * queue, int value ){
	if( queue == 0x0 ){
		queue -> array = newArray( 1 );
		writeOnArray( queue -> array, queue -> length, 0, value );
		return queue;
	}
	queue -> array = resizeArray( queue -> array, queue -> length, queue -> length + 1 ); 
	queue -> length ++;
	writeOnArray( queue -> array, queue -> length, queue -> length - 1, value );
	return queue;
}

int queueArrayPop( QueueArray_t * queue ){
	if( queue -> array == 0x0 ){
		return 0;
	}
	if( queue -> length == 1 ){
		int value = readOnArray( queue -> array, queue -> length, 0 );
		queue -> array = destroyArray( queue -> array );
		queue -> length = 0;
		return value;
	}
	int value = readOnArray( queue -> array, queue -> length, 0 );
	for( size_t i = 0, j = 1; j < queue -> length; i++, j++ ){
		writeOnArray( queue -> array, queue -> length, i, readOnArray( queue -> array, queue -> length, j ) );
	}
	resizeArray(  queue -> array , queue -> length, queue -> length - 1 );
	queue -> length --;
	return value;	
}

void writeOnQueueArray( QueueArray_t * queue, size_t pos, int value ){
	valPtr( queue );
	valSizePos( queue -> length, pos );
	writeOnArray( queue -> array, queue -> length,  pos, value );
}

#endif //QUEUEARRAY_H

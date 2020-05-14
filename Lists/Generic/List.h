/* Local proyect headers */
#include "../../lib/validate.h"
#include "Node.h"

/* Standar headers */
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifndef LIST_H
#define LIST_H

/* Sings */

void listpp( size_t way, Node_t * * list );
Node_t * getNodeOnList( size_t way, Node_t * list, size_t pos );

/* Lookers  */

int isWayOnNodes( size_t way, size_t count, ... ){
	valNeg( way );
	va_list args;
	va_start( args, count );

	for( size_t index = 0; index < count; index += 1){
		Node_t * node = va_arg( args, Node_t * );
		if( way >= node -> length ){
			va_end( args );
			return 0;
		}
	}

	va_end( args );
	return 1;

}

int lengthOfList( size_t way, Node_t * list ){
	valNeg( way );
	valPtr( list );
	valSizePos( list -> length, way );
	Node_t * node = list;
	int count = 0;
	while( node != 0x0 ){
		listpp( way, &node );
		count += 1;
	}
	return count;
}

int readOnList( size_t way, Node_t * list, size_t pos ){
	valNeg( way );
	valNeg( pos );
	valPtr( list );
	valSizePos( list -> length, way );
	valSizePos( lengthOfList( way, list ), pos );
	Node_t * node = getNodeOnList( way, list, pos );
	return node -> value;
}

void seeListWay( size_t way, Node_t * list, char * * listPhotography, int * listPhotographySize ){
	char * photography = "[%p]→";

	*( listPhotographySize ) = 1;
	*( listPhotography ) = ( char * ) calloc( *( listPhotographySize ), sizeof( char ) );

	int elementPhotographySize = 0;
	char * elementPhotography = 0x0;

	Node_t * node = list;
	while( node != 0x0 ){
		valSizePos( node -> length, way );

		elementPhotographySize = snprintf( 0x0, 0, photography, node );
		elementPhotography = ( char * ) calloc( elementPhotographySize, sizeof( char ) );
		valMem( elementPhotography );
		sprintf( elementPhotography , photography, node );

		*( listPhotographySize ) += elementPhotographySize;
		*( listPhotography ) = ( char * ) realloc( *( listPhotography ), *( listPhotographySize ) * sizeof( char ) );
		valMem( *( listPhotography ) );
		
		strcat( *( listPhotography ), elementPhotography );
		free( elementPhotography );
		elementPhotographySize = 0;
		elementPhotography = 0x0;

		node = ( Node_t * ) *( node -> way + way );

		if( node == list ){
			return;
		}
	}
}

void printListWay( size_t way, Node_t * list ){
	Node_t * node = list;
	
	while( node != 0x0 ){
		valSizePos( node -> length, way );
		printf( "[%p]→", node );
		node = (Node_t *) *( node -> way + way );
		if( node == list ){
			printf( "[⥀]\n" );
			return;
		}
	}
	printf( "[(nil)]\n" );
}

void printList( size_t way, Node_t * list ){
	valNeg( way );
	valPtr( list );
	valSizePos( list -> length, way );
	Node_t * node = list;
	while( node != 0x0 ){
		valSizePos( node -> length, way );
		printf( "{ V:%i D:%p }→", node -> value, node );
		node = * ( node -> way + way );
		if( node == list ){
			printf( "{ ⥀ }\n" );
			return;
		}
	}
	printf( "{(nil)}\n" );
}

/* Linkers  */

void linkNode( size_t way, Node_t * node_one, Node_t * node_two ){
	valNeg( way );
	valPtr( node_one );
	valPtr( node_two );
	valSizePos( node_one -> length, way );
	writeOnNodeWay( node_one, way, node_two );
}

void linkNodes(size_t way, size_t count,  Node_t * node, ...){
	valNeg( way );

	va_list args;
	va_start( args, node );
	
	Node_t * node_one = node;
	Node_t * node_two = va_arg( args, Node_t * );
	
	valPtr( node_one );
	valPtr( node_two );
	valSizePos( node_one -> length, way );

	
	count -= 1;
	for( size_t index = 0; index < count ; index += 1){
		linkNode( way, node_one, node_two );
		
		node_one = node_two;
		node_two = va_arg( args, Node_t * );	

		valPtr( node_one );
		valPtr( node_two );
		valSizePos( node_one -> length, way );
	}

	va_end( args );
}

void unlinkNode( size_t way, Node_t * node_one ){
	valNeg( way );
	valPtr( node_one );
	valSizePos( node_one -> length, way );
	deleteOnNodeWay( node_one, way );
}

/* Getters */

Node_t * listPP( size_t way, Node_t * list ){
	valNeg( way );
	valPtr( list );
	valSizePos( list -> length, way );
	return *( list -> way + way );
}

Node_t * getNodeOnList( size_t way, Node_t * list, size_t pos ){
	valNeg( way );
	valNeg( pos );
	valPtr( list );
	valSizePos( list -> length, way );
	Node_t * node = list;
	for( size_t index = 0; index < pos && node != 0x0; index += 1 )
		node = listPP( way, node );
	return node;
}

Node_t * getLastNodeOnList( size_t way, Node_t * list ){
	valNeg( way );
	valPtr( list );
	valSizePos( list -> length, way );
	Node_t * node = list;
	while( node != 0x0 ){
		list = node;
		node = listPP( way, node );
	}
	return list;
}

Node_t * popFirstNodeOnListNlink( size_t way, Node_t * * list ){
	valNeg( way );
	valPtr( list );
	valSizePos( ( *list ) -> length, way );
	Node_t * popped = *list;
	listpp( way, list );
	unlinkNode( way, popped );
	return popped;
}

Node_t * popLastNodeOnListNlink( size_t way, Node_t * list ){
	valNeg( way );
	valPtr( list );
	valSizePos( list -> length, way );
	Node_t * last = getLastNodeOnList( way, list );
	Node_t * node = list;

	while( listPP( way, node ) != last ){
		listpp( way, &node );
	}

	unlinkNode( way, node );
	return last;
}

Node_t * popNodeOnListNlink( size_t way, Node_t * * list, size_t pos ){
	valNeg( way );
	valNeg( pos );
	valPtr( *list );
	valSizePos( (*list) -> length, way );
	
	if( pos == 0 ) return popFirstNodeOnListNlink( way, list );
	if( listPP( way, *list ) == 0x0 ) return popLastNodeOnListNlink( way, *list );

	Node_t * behind = getNodeOnList( way, *list, pos - 1); 
	Node_t * middle = getNodeOnList( way, *list, pos); 
	Node_t * front = getNodeOnList( way, *list, pos + 1); 

	unlinkNode( way, middle );
	linkNode( way, behind, front );
	return middle;
}



/* Adders */
void listInsert( size_t way, Node_t * * list, Node_t * node ){
	valNeg( way );
	valPtr( list );
	valPtr( node );
	valSizePos( ( *( list ) )-> length, way );
	valSizePos( node -> length, way );
	linkNode( way, node, *( list ) );
	*( list ) = node;
}

void listAppend( size_t way, Node_t * list, Node_t * node ){
	valNeg( way );
	valPtr( list );
	valPtr( node );
	valSizePos( list -> length, way );
	valSizePos( node -> length, way );
	Node_t * list_last = getLastNodeOnList( way, list );
	linkNode( way, list_last, node );
}

/* Modifyers */
void listpp( size_t way, Node_t * * list ){
	*( list ) = *( ( *list  ) -> way + way );
}

void writeOnList( size_t way, Node_t * list, size_t pos, int val ){
	valNeg( way );
	valNeg( pos );
	valPtr( list );
	valSizePos( lengthOfList( way, list ), pos );
	( getNodeOnList( way, list, pos ) ) -> value = val;
}

/* Create  */

Node_t * newLinkedList( size_t length, size_t ways ){
	valSize( length );
	valSize( ways );
	
	Node_t * list = 0x0;
	initNodePointer( &list, 0, ways );
	Node_t * head = list;
	
	Node_t * node = 0x0;

	for( size_t count = 0; count < length; count += 1 ){
		initNodePointer( &node, 0, ways );
		linkNode( 0, list, node );
		list = node;
	}

	return head;
}

/* Destroy */



#endif

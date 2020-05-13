#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "../../lib/validate.h"

#ifndef NODE_H
#define NODE_H

/* Init & Destroy  */
struct Node{
	int value;
	int length;
	struct Node * * way;
};

typedef struct Node Node_t;

void initNode( Node_t * node, int value, int length){	
	valSize( length );
	node -> value = value;
	node -> length = length;
	node -> way = ( Node_t * * ) calloc( length, sizeof(Node_t*) );
	valMem( node -> way );
}

void initNodePointer( Node_t * * node, int value, int length){
	*( node ) = ( Node_t * ) calloc( 1, sizeof(Node_t) );
	valMem( *( node ) );
	initNode( *( node ), value, length );
}

void destroyNode( Node_t * node ){
	free( node -> way );
	free( node );
}

/* Lookers  */
void seeNode( Node_t * node, char * * nodePhotography, int * nodePhotographySize ){
	char * photography = "direcction:%p, value:%i, length:%i, ways:";

	*( nodePhotographySize ) = snprintf( 0x0, 0, photography,( Node_t * ) node, node -> value, node -> length) + 1;
	*( nodePhotography ) = ( char * ) calloc( *( nodePhotographySize ), sizeof(char) );
	sprintf( *( nodePhotography ), photography, ( Node_t * ) node, node -> value, node -> length );

	char * elementPhotography = 0x0;
	int elementPhotographySize = 0;

	for( int i = 0; i < node -> length; i++ ){
		elementPhotographySize = snprintf( 0x0, 0, "[%p]" , *( ( Node_t * * ) ( node -> way + i ) ) ) + 1;
		elementPhotography = ( char * ) calloc( elementPhotographySize, sizeof(char) );
		validatePointer( elementPhotography );
		sprintf( elementPhotography, "[%p]", *( ( Node_t * * ) ( node -> way + i ) ) );

		*( nodePhotographySize ) += elementPhotographySize; 
		*( nodePhotography ) = ( char * ) realloc( *( nodePhotography ), sizeof(char) * *( nodePhotographySize ) );
		valMem( *( nodePhotography ) );

		strcat( *( nodePhotography ), elementPhotography );
		free( elementPhotography );
		elementPhotography = 0x0;
		elementPhotographySize = 0;
	}
}

void printNode( Node_t * node ){
	valPtr( node );
	char * nodePhotography = 0x0;
	int nodePhotographySize = 0;
	seeNode( node, &nodePhotography, &nodePhotographySize );
	printf( "Node:{%s}\n", nodePhotography );
}

void printNodes( size_t count, Node_t * node, ... ){
	va_list args;
	va_start( args, node );
	
	printNode( node );

	for( size_t index = 1; index < count; index += 1 ){
		printNode( va_arg( args, Node_t * ) );
	}

	va_end( args );
}

/* Modify  */
void changeNodeValue( Node_t * node, int value){
	node -> value = value;
}

void deleteNodeValue( Node_t * node ){
	changeNodeValue( node, 0);
}

void writeOnNodeWay( Node_t * node, int pos, Node_t * link){
	valSizePos( node -> length,  pos );
	*( node -> way + pos ) = link;
}

void deleteOnNodeWay( Node_t * node, int pos ){
	writeOnNodeWay( node, pos, 0x0 );
}

void resizeNodeWay( Node_t * node, int length ){
	valSize( length );
	node -> way = ( Node_t * * ) realloc( node -> way, sizeof(Node_t*) * length );
	valMem( node -> way );
	node -> length = length;
}

#endif

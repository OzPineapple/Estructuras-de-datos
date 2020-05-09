#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../lib/util.h"

/* Init & Destroy  */
struct List{
	int value;
	int length;
	struct List * * way;
};

typedef struct List List_t;

/* Node */
void initNode( List_t * node, int value, int length){	
	validateSize( length );
	node -> value = value;
	node -> length = length;
	node -> way = ( List_t * * ) calloc( length, sizeof(List_t*) );
	validatePointer( node -> way );
}

void initNodePointer( List_t * * node, int value, int length){
	*( node ) = ( List_t * ) calloc( 1, sizeof(List_t) );
	validatePointer( *( node ) );
	initNode( *( node ), value, length );
}

void destroyNode( List_t * node ){
	free( node -> way );
	free( node );
}

/* List_t */
/*void initList_t( List_t * list, int length, int size ){
	initNode( list, 0, length );
	
}

void initList_tPointer( List_t * * list, int length, int size ){
	*( list ) = ( List_t * ) calloc( 2, sizeof(List_t) );
	initList_t( *( list ), length, size );
}*/

/* Lookers  */

/* Node  */
void seeNode( List_t * node, char * * nodePhotography, int * nodePhotographySize ){
	*( nodePhotographySize ) = snprintf( 0x0, 0, "value:%i, length:%i, ways:", node -> value, node -> length) + 1;
	*( nodePhotography ) = ( char * ) calloc( *( nodePhotographySize ), sizeof(char) );
	sprintf( *( nodePhotography ), "value:%i, length:%i, ways:", node -> value, node -> length );

	char * elementPhotography = 0x0;
	int elementPhotographySize = 0;

	for( int i = 0; i < node -> length; i++ ){
		elementPhotographySize = snprintf( 0x0, 0, "[%p]" , *( ( List_t * * ) ( node -> way + i ) ) ) + 1;
		elementPhotography = ( char * ) calloc( elementPhotographySize, sizeof(char) );
		validatePointer( elementPhotography );
		sprintf( elementPhotography, "[%p]", *( ( List_t * * ) ( node -> way + i ) ) );

		*( nodePhotographySize ) += elementPhotographySize; 
		*( nodePhotography ) = ( char * ) realloc( *( nodePhotography ), sizeof(char) * *( nodePhotographySize ) );
		validatePointer( *( nodePhotography ) );

		strcat( *( nodePhotography ), elementPhotography );
		free( elementPhotography );
		elementPhotography = 0x0;
		elementPhotographySize = 0;
	}
}

void printNode( List_t * node ){
	char * nodePhotography = 0x0;
	int nodePhotographySize = 0;
	seeNode( node, &nodePhotography, &nodePhotographySize );
	printf( "Node:{%s}\n", nodePhotography );
}

/* Modify  */

/* Node */
void changeValueNode( List_t * node, int value){
	node -> value = value;
}

void deleteValueNode( List_t * node ){
	changeValueNode( node, 0);
}

void writeNodeWay( List_t * node, int pos, List_t * link){
	validateSizePos( node -> length,  pos );
	*( node -> way + pos ) = link;
}

void deleteNodeWay( List_t * node, int pos ){
	writeNodeWay( node, pos, 0x0 );
}

void resizeNodeWay( List_t * node, int length ){
	validateSize( length );
	node -> way = ( List_t * * ) realloc( node -> way, sizeof(List_t*) * length );
	validatePointer( node -> way );
	node -> length = length;
}

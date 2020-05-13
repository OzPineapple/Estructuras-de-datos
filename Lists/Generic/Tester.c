#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/util.h"
#include "Node.h"
#include "List.h"

int main(int argc, char * argv[]){
	srand( time( NULL ) );
	printf( "\nTest Node.h funtions\n" );
	Node_t * node = 0x0;
	initNodePointer( &node, randomInRange(-100, 100), randomInRange(1, 20) );
	printNode( node );
	changeNodeValue( node, randomInRange( -100, 100 ) );
	printNode( node );
	deleteNodeValue( node );
	printNode( node );
	Node_t * node_1 = 0x0;
	initNodePointer( &node_1, randomInRange( -100, 100), randomInRange(1, 20) );
	printNode( node_1 );
	Node_t * node_2 = 0x0;
	initNodePointer( &node_2, randomInRange( -100, 100), randomInRange(1, 20) );
	printNode( node_2 );
	writeOnNodeWay( node, randomInRange(0, node -> length - 1 ), node_1);
	printNode( node );
	writeOnNodeWay( node, randomInRange(0, node -> length - 1 ), node_2);
	printNode( node );
	for( int i = 0; i < 3; i++){
		resizeNodeWay( node, randomInRange(1, 20) );
		printNode( node );
	}

	printf( "\nTest List.h funtions\n" );

	linkNode( 0, node_1, node_2 );
	printNodes( 2, node_1, node_2 );

	linkNodes( 0, 3, node, node_1, node_2 );
	printNodes( 3, node, node_1, node_2 );

	destroyNode( node_1 );
	destroyNode( node_2 );
	destroyNode( node );	
}

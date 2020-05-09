#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/util.h"
#include "List.h"

int main(int argc, char * argv[]){
	srand( time( NULL ) );
	List_t * node = 0x0;
	initNodePointer( &node, randomInRange(-100, 100), randomInRange(1, 20) );
	printNode( node );
	changeValueNode( node, randomInRange( -100, 100 ) );
	printNode( node );
	deleteValueNode( node );
	printNode( node );
	List_t * node_1 = 0x0;
	initNodePointer( &node_1, randomInRange( -100, 100), randomInRange(1, 20) );
	printNode( node_1 );
	List_t * node_2 = 0x0;
	initNodePointer( &node_2, randomInRange( -100, 100), randomInRange(1, 20) );
	printNode( node_2 );
	writeNodeWay( node, randomInRange(0, node -> length - 1), node_1);
	printNode( node );
	writeNodeWay( node, randomInRange(0, node -> length - 1), node_2);
	printNode( node );
	for( int i = 0; i < 10; i++){
		resizeNodeWay( node, randomInRange(1, 20) );
		printNode( node );
	}
	destroyNode( node_1 );
	destroyNode( node_2 );
	destroyNode( node );	
}

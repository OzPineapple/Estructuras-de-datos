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

	printf( "isWayOnNodes( %i )\n", isWayOnNodes( 0, 3, node, node_1, node_2 ) );
	printf( "isWayOnNodes( %i )\n", isWayOnNodes( randomInRange(0 , node -> length -1), 3, node, node_1, node_2 ) );

	printListWay( 0, node );
	
	linkNode( 0, node_2, node );
	printListWay( 0, node );
	printList( 0, node );

	Node_t * list = newLinkedList( randomInRange( 1, 10 ), randomInRange( 1, 5 ) );
	printList( 0, list );

	printf( "\nList - insert append\n" );
	listInsert( 0, &list, node_1 );
	listAppend( 0, list, node_2 );
	printList( 0, list );
	printList( 0, node );

	printf( "\nList - pop\n" );
	Node_t * popped = popNodeOnListNlink( 0, &list, 0 );
	printNode( popped );
	printList( 0, list );
	popped = popFirstNodeOnListNlink( 0, &list );
	printNode( popped );
	printList( 0, list );
	popped = popLastNodeOnListNlink( 0, list );
	printNode( popped );
	printList( 0, list );
	
	printf( "\nList - listpp\n" );
	printList( 0, list );
	for( size_t index = 0; index < 3; index += 1){	
		listpp( 0, &list );
		if( list == 0x0 ){
			printf( " [ N ] → [ 0x0 ]  The list arrives on 0x0, the program gona fail, don't worry just re-run\n" );
		}
		printList(0, list );
	}

	printf( "\nList - write ramdomly\n" );
	printList( 0, list );	
	for( size_t index = 0; index < 3; index += 1){	
		writeOnList( 0, list, randomInRange( 0, lengthOfList( 0, list ) - 1 ), randomInRange( -100, 100 ) );
	}
	printList( 0, list );

	printf( "\nList - read randomly\n" );
	for( size_t index = 0; index < 3; index += 1){
		printf("[%i]", readOnList( 0, list, randomInRange( 0, lengthOfList( 0, list) - 1 ) ) );
	}
	printf("\n");

	destroyNode( node_1 );
	destroyNode( node_2 );
	destroyNode( node );	
}

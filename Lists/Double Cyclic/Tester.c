#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/util.h"
#include "ListCyclicDouble.h"

int main(int argc, char * argv[]){

	printf( "ListCyclicDouble.h - Init\n" );

	srand( time( NULL ) );
	Node_t * list_cyclic_double = 0x0;

	initListCyclicDoublePointer( &list_cyclic_double, randomInRange( 1, 7) );

	printListCyclicDouble( list_cyclic_double );

	printf( "\nListCyclicDouble.h - Insert\n" );

	Node_t * front = 0x0;

	initNodePointer( &front, 5, 2 );

	printNode( front );

	listCyclicDoubleInsert( &list_cyclic_double, front );

	printListCyclicDouble( list_cyclic_double );

	front = 0x0;

	front = popFirstNodeOnListCyclicDoubleNlink( &list_cyclic_double );

	destroyNode( front );

	printListCyclicDouble( list_cyclic_double );

	printf( "\nListCyclicDouble.h - Append\n" );

	Node_t * last = 0x0;

	initNodePointer( &last, 15, 2 );

	printNode( last );

	listCyclicDoubleAppend( list_cyclic_double, last );

	printListCyclicDouble( list_cyclic_double );

	last = 0x0;

	last = popLastNodeOnListCyclicDoubleNlink( list_cyclic_double );

	destroyNode( last );
	
	printListCyclicDouble( list_cyclic_double );

	printf( "\nListCyclicDouble.h - Get\n" );

	printListCyclicDouble( list_cyclic_double );

	printNode( getNextNodeOnListCyclicDouble( list_cyclic_double ) );

	printNode( getNodeOnListCyclicDouble( list_cyclic_double, randomInRange( 0, lengthOfListCyclicDouble( list_cyclic_double ) - 1 ) ) );
	
	printf( "\nListCyclicDouble.h - Write\n" );
	
	for( size_t i = 0; i < 10; i++)
		writeOnListCyclicDouble( list_cyclic_double, randomInRange( 0, lengthOfListCyclicDouble( list_cyclic_double ) - 1 ), randomInRange( -100, 100 ) );

	printListCyclicDouble( list_cyclic_double );

	printf( "\nListCyclicDouble.h - Read\n" );

	for( size_t i = 0; i < 10; i++)
		printf( "%i ", readOnListCyclicDouble( list_cyclic_double, randomInRange( 0, lengthOfListCyclicDouble( list_cyclic_double) - 1 ) ));
	printf("\n");	
	
	printf( "\nListCyclicDouble.h - Delete\n" );
	
	for( size_t i = 0; i < 10; i++)
		deleteOnListCyclicDouble( list_cyclic_double, randomInRange( 0, lengthOfListCyclicDouble( list_cyclic_double ) - 1 ) );

	printListCyclicDouble( list_cyclic_double );

	printf( "\nListCyclicDouble.h - Destroy\n" );

	printListCyclicDouble( list_cyclic_double );
	if( list_cyclic_double != 0x0 )
		destroyNodeOnListCyclicDoubleNlink( &list_cyclic_double, 0 );
	printListCyclicDouble( list_cyclic_double );
	if( list_cyclic_double != 0x0 )
		destroyNodeOnListCyclicDoubleNlink( &list_cyclic_double, lengthOfListCyclicDouble( list_cyclic_double ) - 1);
	printListCyclicDouble( list_cyclic_double );
	if( list_cyclic_double != 0x0 )
		destroyNodeOnListCyclicDoubleNlink( &list_cyclic_double, randomInRange( 0, lengthOfListCyclicDouble( list_cyclic_double ) - 1 ) );
	printListCyclicDouble( list_cyclic_double );

	destroyListCyclicDouble( list_cyclic_double );
	
	list_cyclic_double = 0x0;

	printListCyclicDouble( list_cyclic_double );
}

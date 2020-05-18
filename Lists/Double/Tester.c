#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/util.h"
#include "ListDouble.h"

int main(int argc, char * argv[]){

	printf( "ListDouble.h - Init\n" );

	srand( time( NULL ) );
	Node_t * list_double = 0x0;

	initListDoublePointer( &list_double, randomInRange( 1, 5) );

	printListDouble( list_double );

	printf( "\nListDouble.h - Insert\n" );

	Node_t * front = 0x0;

	initNodePointer( &front, 5, 2 );

	printNode( front );

	listDoubleInsert( &list_double, front );

	printListDouble( list_double );

	front = 0x0;

	front = popFirstNodeOnListDoubleNlink( &list_double );

	destroyNode( front );

	printListDouble( list_double );

	printf( "\nListDouble.h - Append\n" );

	Node_t * last = 0x0;

	initNodePointer( &last, 15, 2 );

	printNode( last );

	listDoubleAppend( list_double, last );

	printListDouble( list_double );

	last = 0x0;

	last = popLastNodeOnListDoubleNlink( list_double );

	destroyNode( last );
	
	printListDouble( list_double );

	printf( "\nListDouble.h - Get\n" );

	printListDouble( list_double );

	printNode( getNextNodeOnListDouble( list_double ) );

	printNode( getNodeOnListDouble( list_double, randomInRange( 0, lengthOfListDouble( list_double ) - 1 ) ) );
	
	printf( "\nListDouble.h - Write\n" );
	
	for( size_t i = 0; i < 10; i++)
		writeOnListDouble( list_double, randomInRange( 0, lengthOfListDouble( list_double ) - 1 ), randomInRange( -100, 100 ) );

	printListDouble( list_double );

	printf( "\nListDouble.h - Read\n" );

	for( size_t i = 0; i < 10; i++)
		printf( "%i ", readOnListDouble( list_double, randomInRange( 0, lengthOfListDouble( list_double) - 1 ) ));
	printf("\n");	
	
	printf( "\nListDouble.h - Delete\n" );
	
	for( size_t i = 0; i < 10; i++)
		deleteOnListDouble( list_double, randomInRange( 0, lengthOfListDouble( list_double ) - 1 ) );

	printListDouble( list_double );

	printf( "\nListDouble.h - Destroy\n" );

	destroyNodeOnListDoubleNlink( &list_double, randomInRange( 0, lengthOfListDouble( list_double ) - 1 ) );

	printListDouble( list_double );

	destroyListDouble( list_double );
	
	list_double = 0x0;

	printListDouble( list_double );
}

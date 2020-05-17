#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/util.h"
#include "ListSimple.h"

int main(int argc, char * argv[]){

	printf( "ListSimple.h - Init\n" );

	srand( time( NULL ) );
	Node_t * list_simple = 0x0;

	initListSimplePointer( &list_simple, randomInRange( 1, 5) );

	printListSimple( list_simple );

	printf( "\nListSimple.h - Insert\n" );

	Node_t * front = 0x0;

	initNodePointer( &front, 5, 1 );

	printNode( front );

	listSimpleInsert( &list_simple, front );

	printListSimple( list_simple );

	front = 0x0;

	front = popFirstNodeOnListSimpleNlink( &list_simple ); 

	destroyNode( front );

	printListSimple( list_simple );

	printf( "\nListSimple.h - Append\n" );

	Node_t * last = 0x0;

	initNodePointer( &last, 15, 1 );

	printNode( last );

	listSimpleAppend( list_simple, last );

	printListSimple( list_simple );

	last = 0x0;

	last = popLastNodeOnListSimpleNlink( list_simple );

	destroyNode( last );

	printf( "\nListSimple.h - Get\n" );

	printListSimple( list_simple );

	printNode( getNextNodeOnListSimple( list_simple ) );

	printNode( getNodeOnListSimple( list_simple, randomInRange( 0, lengthOfListSimple( list_simple ) - 1 ) ) );
	
	printf( "\nListSimple.h - Write\n" );
	
	for( size_t i = 0; i < 10; i++)
		writeOnListSimple( list_simple, randomInRange( 0, lengthOfListSimple( list_simple ) - 1 ), randomInRange( -100, 100 ) );

	printListSimple( list_simple );

	printf( "\nListSimple.h - Read\n" );

	for( size_t i = 0; i < 10; i++)
		printf( "%i ", readOnListSimple( list_simple, randomInRange( 0, lengthOfListSimple( list_simple) - 1 ) ));
	printf("\n");	
	
	printf( "\nListSimple.h - Delete\n" );
	
	for( size_t i = 0; i < 10; i++)
		deleteOnListSimple( list_simple, randomInRange( 0, lengthOfListSimple( list_simple ) - 1 ) );

	printListSimple( list_simple );

	printf( "\nListSimple.h - Destroy\n" );

	destroyNodeOnListSimpleNlink( &list_simple, randomInRange( 0, lengthOfListSimple( list_simple ) - 1 ) );

	printListSimple( list_simple );

	destroyListSimple( list_simple );
	
	list_simple = 0x0;

	printListSimple( list_simple );
}

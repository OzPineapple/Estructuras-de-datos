#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/util.h"
#include "ListSimple.h"

int main(int argc, char * argv[]){
	srand( time( NULL ) );
	Node_t * list_simple = 0x0;
	initListSimplePointer( &list_simple, randomInRange( 0, 20) );

	printListSimple( list_simple );

	Node_t * front = 0x0;

	initNodePointer( &front, 5, 1 );

	printNode( front );

	listSimpleInsert( &list_simple, front );

	printListSimple( list_simple );

	front = 0x0;

	front = popFirstNodeOnListSimpleNlink( &list_simple ); 

	destroyNode( front );

	printListSimple( list_simple );

	Node_t * last = 0x0;

	initNodePointer( &last, 15, 1 );

	printNode( last );

	listSimpleAppend( list_simple, last );

	printListSimple( list_simple );

	last = 0x0;

	last = popLastNodeOnListSimpleNlink( list_simple );

	destroyNode( last );

	printListSimple( list_simple );

	destroyListSimple( list_simple );
}

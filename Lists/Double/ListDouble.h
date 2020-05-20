/* Local proyect headers */
#include "../../lib/validate.h"
#include "../Generic/List.h" 

#ifndef LISTDOUBLE_H
#define LISTDOUBLE_H

void initListDoublePointer( Node_t * * list, size_t size ){
	valSize( size );
	*list = newList( size, 2);
	valMem( *list );

	Node_t * behind= 0x0;
	Node_t * front = *list;

	while( front != 0x0 ){
		linkNode( 1, front, behind );
		behind = front;
		listpp( 0, &front );
	}
}

#define destroyListDouble( list ) destroyList( 0, list )

#define listDoublepp( list ) listpp( 0, list )

#define lengthOfListDouble( list ) lengthOfList( 0, list )

// Lookers  

void printListDouble( Node_t * list ){
	if( list == 0x0) { printf( "{(nil)}\n" ); return;}
	Node_t * last = getLastNodeOnList( 0, list );
	printList( 0, list );
	printList( 1, last );
}

#define readOnListDouble( list, pos ) readOnList( 0, list, pos )

// Modifiers

void listDoubleInsert( Node_t * * list, Node_t * node ){
	val2Ptr( (void**) list );
	valPtr( node );
	listInsert( 0, list, node );
	Node_t * second = getNextNodeOnList( 0, *list );
	linkNode( 1, second, node );
}

void listDoubleAppend( Node_t * list, Node_t * node ){
	valPtr( list );
	Node_t * prelast = getLastNodeOnList( 0, list );
	listAppend( 0, list, node );
	linkNode( 1, node, prelast );
}

#define writeOnListDouble( list, pos, val ) writeOnList( 0, list, pos, val )

#define deleteOnListDouble( list, pos ) deleteOnList( 0, list, pos );

// Getters

#define getNextNodeOnListDouble( list ) getNextNodeOnList( 0, list )

#define getNodeOnListDouble( list, pos ) getNodeOnList( 0, list, pos )

// Poppers

Node_t * popFirstNodeOnListDoubleNlink( Node_t * * list ){
	val2Ptr( (void**) list );
	Node_t * second = getNextNodeOnList( 0, *list );
	unlinkNode( 1, second );
	return popFirstNodeOnListNlink( 0, list );
}

Node_t * popNodeOnListDoubleNlink( Node_t * * list, size_t pos ){
	val2Ptr( (void**) list );
	valNeg( pos );
	
	Node_t * list_2 = getLastNodeOnList( 0, *list );

	popNodeOnListNlink( 1, &list_2, lengthOfList( 1, list_2 ) -1 - pos );

	return popNodeOnListNlink( 0, list, pos );
}

Node_t * popLastNodeOnListDoubleNlink( Node_t * list ){
	Node_t * last = getLastNodeOnList( 0, list );
	Node_t * prelast = *( last -> way + 1 );
	unlinkNode( 0, prelast );
	unlinkNode( 1, last );
	return last;
}

// Destroy

void destroyNodeOnListDoubleNlink( Node_t * * list, size_t pos ){
	val2Ptr( (void**) list );
	valNeg( pos );
	valSizePos( lengthOfList( 0, *list ), pos );
	
	Node_t * list_2 = getLastNodeOnList( 0, *list );

	popNodeOnListNlink( 1, &list_2, lengthOfList( 1, list_2 ) -1 - pos );

	destroyNodeOnListNlink( 0, list, pos );
}

#endif // LISTDOUBLE_H

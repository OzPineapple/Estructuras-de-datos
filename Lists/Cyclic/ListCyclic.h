/* Local proyect headers */
#include "../../lib/validate.h"
#include "../Generic/List.h" 

#ifndef LISTCYCLIC_H
#define LISTCYCLIC_H

void initListCyclicPointer( Node_t * * list, size_t size ){
	valSize( size );
	*list = newList( size, 1);
	valMem( *list );
	Node_t * last = getLastNodeOnList( 0, *list );
	linkNode(0, last, *list);
}

#define destroyListCyclic( list ) destroyList( 0, list )

#define listCyclicpp( list ) listpp( 0, list )

#define lengthOfListCyclic( list ) lengthOfList( 0, list )

// Lookers  

#define printListCyclic( list ) printList( 0, list );

#define readOnListCyclic( list, pos ) readOnList( 0, list, pos )

// Modifiers

void listCyclicInsert( Node_t * * list, Node_t * node ){
	val2Ptr( (void**) list );
	valPtr( node );
	Node_t * last = getLastNodeOnList( 0, * list );

	listInsert( 0, list, node );
	linkNode( 0, last, *list );
}

void listCyclicAppend( Node_t * list, Node_t * node ){
	valPtr( list );
	valPtr( node );
	Node_t * prelast = getLastNodeOnList( 0, list );
	listAppend( 0, list, node );
	linkNode( 0, prelast, node );
	linkNode( 0, node, list);
}

#define writeOnListCyclic( list, pos, val ) writeOnList( 0, list, pos, val )

#define deleteOnListCyclic( list, pos ) deleteOnList( 0, list, pos );

// Getters

#define getNextNodeOnListCyclic( list ) getNextNodeOnList( 0, list )

#define getNodeOnListCyclic( list, pos ) getNodeOnList( 0, list, pos )

// Poppers

Node_t * popFirstNodeOnListCyclicNlink( Node_t * * list ){
	val2Ptr( (void**) list );
	Node_t * last = getLastNodeOnList( 0, * list );
	Node_t * next = getNextNodeOnList( 0, * list );
	linkNode( 0, last, next );
	return popFirstNodeOnListNlink( 0, list );
}

Node_t * popNodeOnListCyclicNlink( Node_t * * list, size_t pos ){
	val2Ptr( (void**) list );
	valNeg( pos );

	return popNodeOnListNlink( 0, list, pos );
}

Node_t * popLastNodeOnListCyclicNlink( Node_t * list ){
	Node_t * last = getLastNodeOnList( 0, list );
	Node_t * prelast = getLastNodeOnList( 0, last );
	linkNode( 0, prelast, list );
	unlinkNode( 0, last );
	return last;
}

// Destroy

void destroyNodeOnListCyclicNlink( Node_t * * list, size_t pos ){
	valPtr( list );
	if( *list == 0x0 ) return;
	valNeg( pos );
	valSizePos( lengthOfList( 0, *list ), pos );

	if( lengthOfList( 0, *list ) == 1 ){
		destroyNode( *list );
		*list = 0x0;
		return;
	}

	Node_t * last = getLastNodeOnList( 0, * list );

	destroyNodeOnListNlink( 0, list, pos );

	if( pos == 0 ){
		linkNode( 0, last, *list );
	}

	if( last != getLastNodeOnList( 0, * list ) ){
		linkNode( 0, getLastNodeOnList( 0, * list ), * list );		
	}
}

#endif // LISTCYCLIC_H

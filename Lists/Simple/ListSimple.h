/* Local proyect headers */
#include "../../lib/validate.h"
#include "../Generic/List.h" 
/* Standar headers */
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifndef LISTSIMPLE_H
#define LISTSIMPLE_H

void initListSimplePointer( Node_t * * list, size_t size ){
	valSize( size );
	*list = newList( size, 1);
}

#define destroyListSimple( list ) destroyList( 0, list )

#define listSimplepp( list ) listpp( list )

#define lengthOfListSimple( list ) lengthOfList( 0, list )

/* Lookers  */

#define printListSimple( list ) printList( 0, list )

#define readOnListSimple( list, pos ) readOnList( 0, list, pos )

/* Modifiers */

#define listSimpleInsert( list, node ) listInsert( 0, list, node )

#define listSimpleAppend( list, node ) listAppend( 0, list, node )

#define writeOnListSimple( list, pos, val ) writeOnList( 0, list, pos, val )

#define deleteOnListSimple( list, pos ) deleteOnList( 0, list, pos );

/* Getters  */

#define getNextNodeOnListSimple( list ) getNextNodeOnList( 0, list )

#define getNodeOnListSimple( list, pos ) getNodeOnList( 0, list, pos )

/* Poppers */

#define popFirstNodeOnListSimpleNlink( list ) popFirstNodeOnListNlink( 0, list )

#define popNodeOnListSimpleNlink( list, pos ) popNodeOnListNlink( 0, list, pos  )

#define popLastNodeOnListSimpleNlink( list ) popLastNodeOnListNlink( 0, list )

/* Destroy */

#define destroyNodeOnListSimpleNlink( list, pos ) destroyNodeOnListNlink( 0, list, pos );

#endif

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

#define destroyListSimple( list ) destroyList( 0, list );

/* Lookers  */

#define printListSimple( list ) printList( 0, list );

/* Modifiers */

#define listSimpleInsert( list, node ) listInsert( 0, list, node );

#define listSimpleAppend( list, node ) listAppend( 0, list, node );

/* Getters  */

/* Poppers */

#define popFirstNodeOnListSimpleNlink( list ) popFirstNodeOnListNlink( 0, list );

#define popNodeOnListSimpleNlink( list, pos ) popNodeOnListNlink( 0, list, pos  );

#define popLastNodeOnListSimpleNlink( list ) popLastNodeOnListNlink( 0, list );

#endif

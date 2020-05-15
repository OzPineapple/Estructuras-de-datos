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
	* list = newList( size, 1);
}

void destroyListSimple( Node_t * list ){
	valPtr( list );
	destroyList( 0, list );
}

#endif

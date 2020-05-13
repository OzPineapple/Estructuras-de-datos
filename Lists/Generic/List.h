/* Local proyect headers */
#include "../../lib/validate.h"
#include "Node.h"

/* Standar headers */
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifndef LIST_H
#define LIST_H

/* Init & Des */
/*
Node_t * createSimpleList( size_t length, size_t ways ){
	validateSize( length );
	validateSize( ways );
	
	Node_t * array_nodes = NULL;
	array_nodes = ( Node_t *) calloc( length, sizeof Node_t  );
	validatePointer( node );

	for( size_t index = 0; index < length; index += 1 ){
		initNode( array_nodes + index, 0, ways );
	}

	linkNodes( array_nodes, length, ways, 0 );

	return array_nodes;
}*/

void linkNode( size_t way, Node_t * node_one, Node_t * node_two ){
	valNeg( way );
	valPtr( node_one );
	valPtr( node_two );
	valSizePos( node_one -> length, way );
	writeOnNodeWay( node_one, way, node_two );
}

void linkNodes(size_t way, size_t count,  Node_t * node, ...){
	valNeg( way );

	va_list args;
	va_start( args, node);
	
	Node_t * node_one = node;
	Node_t * node_two = va_arg( args, Node_t * );
	
	valPtr( node_one );
	valPtr( node_two );
	valSizePos( node_one -> length, way );

	
	count -= 1;
	for( size_t index = 0; index < count ; index += 1){
		linkNode( way, node_one, node_two );
		
		node_one = node_two;
		node_two = va_arg( args, Node_t * );	

		valPtr( node_one );
		valPtr( node_two );
		valSizePos( node_one -> length, way );
	}

	va_end( args );
}

#endif

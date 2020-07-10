#include <Lists/Generic/List.h>
#include <Lists/Generic/Node.h>

#ifndef LISTDOUBLE_H
#define LISTDOUBLE_H

void initListDoublePointer (Node_t * *list, size_t size);

#define destroyListDouble( list ) destroyList( 0, list )

#define listDoublepp( list ) listpp( 0, list )

#define lengthOfListDouble( list ) lengthOfList( 0, list )

// Lookers  

void printListDouble (Node_t * list);

#define readOnListDouble( list, pos ) readOnList( 0, list, pos )

// Modifiers

void listDoubleInsert (Node_t * *list, Node_t * node);

void listDoubleAppend (Node_t * list, Node_t * node);

#define writeOnListDouble( list, pos, val ) writeOnList( 0, list, pos, val )

#define deleteOnListDouble( list, pos ) deleteOnList( 0, list, pos );

// Getters

#define getNextNodeOnListDouble( list ) getNextNodeOnList( 0, list )

#define getNodeOnListDouble( list, pos ) getNodeOnList( 0, list, pos )

// Poppers

Node_t *popFirstNodeOnListDoubleNlink (Node_t * *list);

Node_t *popNodeOnListDoubleNlink (Node_t * *list, size_t pos);

Node_t *popLastNodeOnListDoubleNlink (Node_t * list);

// Destroy

void destroyNodeOnListDoubleNlink (Node_t * *list, size_t pos);

#endif // LISTDOUBLE_H

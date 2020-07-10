#include "Node.h"

#ifndef LIST_H
#define LIST_H

/* Create  */

Node_t *newList (size_t length, size_t ways);

void destroyList (size_t way, Node_t * list);

void listpp (size_t way, Node_t * *list);

int lengthOfList (size_t way, Node_t * list);

/* Getters */

Node_t *getNextNodeOnList (size_t way, Node_t * list);

Node_t *getNodeOnList (size_t way, Node_t * list, size_t pos);

Node_t *getLastNodeOnList (size_t way, Node_t * list);

/* Poppers */

Node_t *popFirstNodeOnListNlink (size_t way, Node_t * *list);

Node_t *popLastNodeOnListNlink (size_t way, Node_t * list);

Node_t *popNodeOnListNlink (size_t way, Node_t * *list, size_t pos);

/* Cutters  */

Node_t *cutList (size_t way, Node_t * list, size_t pos);

/* Lookers  */

int readOnList (size_t way, Node_t * list, size_t pos);

void printList (size_t way, Node_t * list);


/* Modifyers */

void listInsert (size_t way, Node_t * *list, Node_t * node);

void listAppend (size_t way, Node_t * list, Node_t * node);

void writeOnList (size_t way, Node_t * list, size_t pos, int val);

void deleteOnList (size_t way, Node_t * list, size_t pos);

/* Destroy */

void destroyNodeOnListNlink (size_t way, Node_t * *list, size_t pos);

#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "../../lib/validate.h"

#ifndef NODE_H
#define NODE_H

struct Node
{
  int value;
  int length;
  struct Node **way;
};

typedef struct Node Node_t;

void initNode (Node_t * node, int value, int length);

void initNodePointer (Node_t * *node, int value, int length);

void destroyNode (Node_t * node);

/* Lookers  */
void seeNode (Node_t * node, char * *nodePhotography,
	      int *nodePhotographySize);

void printNode (Node_t * node);

void printNodes (size_t count, Node_t * node, ...);

/* Modify  */
void changeNodeValue (Node_t * node, int value);

void deleteNodeValue (Node_t * node);

void writeOnNodeWay (Node_t * node, int pos, Node_t * link);

void deleteOnNodeWay (Node_t * node, int pos);

void resizeNodeWay (Node_t * node, int length);

/* Linkres */

void linkNode (size_t way, Node_t * node_one, Node_t * node_two);

void linkNodes (size_t way, size_t count, Node_t * node, ...);

void unlinkNode (size_t way, Node_t * node_one);

#endif

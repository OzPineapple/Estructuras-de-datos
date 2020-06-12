#include <Lists/Generic/Node.h>

#ifndef LISTCYCLIC_H
#define LISTCYCLIC_H

void initListCyclicPointer (Node_t * *list, size_t size);

void destroyListCyclic (Node_t * list);

void listCyclicpp (Node_t * *list);

int lengthOfListCyclic (Node_t * list);

void printListCyclic (Node_t * list);

int readOnListCyclic (Node_t * list, int pos);

void listCyclicInsert (Node_t * *list, Node_t * node);

void listCyclicAppend (Node_t * list, Node_t * node);

void writeOnListCyclic (Node_t * list, int pos, int val);

void deleteOnListCyclic (Node_t * list, int pos);

Node_t *getNextNodeOnListCyclic (Node_t * list);

Node_t *getNodeOnListCyclic (Node_t * list, int pos);

void writeOnListCyclic (Node_t * list, int pos, int val);

void deleteOnListCyclic (Node_t * list, int pos);

Node_t *popFirstNodeOnListCyclicNlink (Node_t * *list);

Node_t *popNodeOnListCyclicNlink (Node_t * *list, size_t pos);

Node_t *popLastNodeOnListCyclicNlink (Node_t * list);

void destroyNodeOnListCyclicNlink (Node_t * *list, size_t pos);

#endif // LISTCYCLIC_H

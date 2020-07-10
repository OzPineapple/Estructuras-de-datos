#ifndef LISTCYCLICDOUBLE_H
#define LISTCYCLICDOUBLE_H

void initListCyclicDoublePointer (Node_t * *list, size_t size);

void destroyListCyclicDouble (Node_t * list);

void listCyclicDoublepp (Node_t * *list);

int lengthOfListCyclicDouble (Node_t * list);

void printListCyclicDouble (Node_t * list);

int readOnListCyclicDouble (Node_t * list, int pos);

// Modifiers

void listCyclicDoubleInsert (Node_t * *list, Node_t * node);

void listCyclicDoubleAppend (Node_t * list, Node_t * node);

void writeOnListCyclicDouble (Node_t * list, int pos, int val);

void deleteOnListCyclicDouble (Node_t * list, int pos);

// Getters

Node_t *getNextNodeOnListCyclicDouble (Node_t * list);

Node_t *getNodeOnListCyclicDouble (Node_t * list, int pos);

// Poppers

Node_t *popFirstNodeOnListCyclicDoubleNlink (Node_t * *list);


Node_t *popLastNodeOnListCyclicDoubleNlink (Node_t * list);

Node_t *popNodeOnListCyclicDoubleNlink (Node_t * *list, size_t pos);

// Destroy

void destroyNodeOnListCyclicDoubleNlink (Node_t * *list, size_t pos);

#endif // LISTCYCLICDOUBLE_H

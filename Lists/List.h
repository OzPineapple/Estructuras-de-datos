#include <stdlib.h>

struct Node{
	int value;
	struct Node * link;
} Node_t;

int initList( Node_t * list, int values, int size){	
	*list = (Node_t) malloc(sizeof(Node_t);	
	if(*list=NULL) return 510;
	Note_t * node = list;
	Node_t * newNode;
	for(int i = 0; i < size; i++){
		node->value = values[i];
		*newNode = (Node_t) malloc(sizeof(Node_t);	
		node->link = newNode;
		node = newNode;
	}
}

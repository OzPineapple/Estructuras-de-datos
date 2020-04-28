#include <stdlib.h>
#include <../lib/util.h>

typedef struct List{
	int value;
	int links;
	List_t** link;
} List_t;

int initList( List_t** list, int value, List_t** link, int links){	
	*list = (List_t*) malloc(sizeof(Node_t);	
	validatePointer(*list);
	Note_t * node = list;
	Node_t * newNode;
	for(int i = 0; i < size; i++){
		node->value = values[i];
		*newNode = (Node_t) malloc(sizeof(Node_t);	
		node->link = newNode;
		node = newNode;
	}
}

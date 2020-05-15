#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/util.h"
#include "ListSimple.h"

int main(int argc, char * argv[]){
	srand( time( NULL ) );
	Node_t * list_simple = 0x0;
	initListSimplePointer( &list_simple, randomInRange( 0, 20) );
	destroyListSimple( list_simple );
}

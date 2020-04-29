#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GenericVector.h"

int main(int argc, char * argv[]){
	srand(time(NULL));
	GenericVector * generic_vector = 0x0;

	initGenericVectorPointer(&generic_vector, randomInRange(1,80), sizeof(float) );
	printGenericVector(generic_vector,"[%f]", float);
	destroyGenericVector(generic_vector);	
	
	initGenericVectorPointer(&generic_vector, randomInRange(1,80), sizeof(char) );
	printGenericVector(generic_vector,"[%c]", char);
	destroyGenericVector(generic_vector);

	initGenericVectorPointer(&generic_vector, randomInRange(1,80), sizeof(char*) );
	printGenericVector(generic_vector,"[%p]", char*);
	destroyGenericVector(generic_vector);
	
	initGenericVectorPointer(&generic_vector, randomInRange(1,80), sizeof(int) );
	printGenericVector(generic_vector,"[%i]", int);

	printFromGenericVector( generic_vector, randomInRange(0, generic_vector->length - 1 ), "%i\n", int);

	writeOnGenericVector( generic_vector, randomInRange(0, generic_vector->length - 1) , randomInRange(1,10) , int);
	printGenericVector(generic_vector,"[%i]", int);

	resizeGenericVector( generic_vector, randomInRange(1,80), int);
	printGenericVector(generic_vector,"[%i]", int);

	resizeGenericVector( generic_vector, randomInRange(1,20), int);
	printGenericVector(generic_vector,"[%i]", int);

	resizeGenericVector( generic_vector, randomInRange(1,50), int);
	printGenericVector(generic_vector,"[%i]", int);

	destroyGenericVector(generic_vector);
	
	return 0;
}

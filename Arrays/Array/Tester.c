#include <stdio.h>
#include <time.h>
#include "Array.h"
#include "../../lib/util.h"

int main(int argc, char * argv[]){
	printf("Array tester by Oz Pineapple\n");

	srand(time(NULL));
	int arraySize = randomInRange(1,15);
	int* array = 0x0;

	initArray(&array, arraySize);
	printf("Array inited\n");

	printArray(array, arraySize);
	printf("Array printed\n");

	printArray(array, arraySize);
	printArray(array, arraySize);

//	printf("Rezise array");
//	resizeArray(&array, arraySize, randomInRange(1,20));
//      printArray(array, arraySize);	
	free(array);
}

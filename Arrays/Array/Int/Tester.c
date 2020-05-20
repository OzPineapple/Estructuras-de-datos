// Include local
#include "Array.h"
#include <lib/util.h>

// Include standar
#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[]){
	printf("Array tester by Oz Pineapple\n");

	srand(time(NULL));
	printf("RandomInRange test:");
	for(int i = 0; i < 10; i+=1){
		printf("%i ",randomInRange(1,20));
	}
	println;

	printf("Init array\n");
	
	int arraySize = randomInRange(1,20);
	int * array = newArray( arraySize );

	printf("Print array, size:%i\n", arraySize);
	printArray( array, arraySize );
	println;

	int data = randomInRange(-100,100);
	int pos = randomInRange(0,arraySize-1);
	
	printf("Write on position %i of array data %i\n", pos, data);
	writeOnArray(array, arraySize, pos, data);
	printArray(array, arraySize);
	println;

	printf("Write randomly on  array tweny times\n");
	for(int i = 0; i < 20; i+=1){
		data = randomInRange(-100,100);
		pos = randomInRange(0,arraySize-1);
		writeOnArray(array, arraySize, pos, data);
	}
	printArray(array, arraySize);
	println;

	pos = randomInRange(0,arraySize-1);
	printf("Delete on position %i of array\n", pos);
	deleteOnArray(array, arraySize, pos);
	printArray(array, arraySize);
	println;

	pos = randomInRange(0,arraySize-1);
	printf("Read pos %i of array\n", pos);
	printFromArray(array, arraySize, pos);
	println;
	
	int array2size = arraySize;
	int * array2 = newArray( array2size );

	for(int i = 0; i < 20; i+=1){
		data = randomInRange(-100,100);
		pos = randomInRange(0,arraySize-1);
		writeOnArray(array2, array2size, pos, data);
	}

	printf("Array 2 for testing, size:%i\n", array2size);
	printArray(array2, array2size);
	println;

	cloneArray(array, array2, arraySize);
	printf("Clone array on array2:\n\tArray:\n");
	printArray(array,arraySize);
	println;
	printf("\tArray 2:\n");
	printArray(array2,array2size);
	println;

	int newArraySize = randomInRange(1,20);
	printf("Rezise array, size:%i\n", newArraySize);
	array = resizeArray(array, arraySize, newArraySize);
	arraySize =  newArraySize;
	printArray(array, arraySize);	
	println;

	printf("Resize randomly array ten times\n");
	for(int i = 0; i < 10; i+=1){
		newArraySize = randomInRange(1,20);
		array = resizeArray(array, arraySize, newArraySize);
		arraySize = newArraySize;
		printf("\tSize: %i, ", arraySize);
		printArray(array, arraySize);
		println;
	}
	printf("Destroy array & array2\n");
	array2 = destroyArray(array2);
	printArray(array2, arraySize);
	println;
	array = destroyArray(array);
	printArray(array, arraySize);
	println;
}

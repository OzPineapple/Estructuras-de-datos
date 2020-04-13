#include <stdio.h>
#include <time.h>
#include "Vector.h"
#include "../../lib/util.h"

int main(int argc, char * argv[]){
	printf("Vector tester by Oz Pineapple\n");

	srand(time(NULL));

	printf("Init vector\n");
	Vector* vector = 0x0;
	initVector(&vector,randomInRange(1,20));
	
	printf("Print vector\n");
	printVector(*vector);

	int pos = randomInRange(0,vector->size - 1);
	int data = randomInRange(-100,100);
	printf("Write on position %i from vector data: %i\n", pos, data);
	writeOnVector(&vector, pos, data);
	printVector(*vector);

	printf("Write randomly on vector tweny times\n");
	for(int i=0; i<20; i+=1){
		writeOnVector(&vector, randomInRange(0, vector->size -1), randomInRange(-100,100));
	}
	printVector(*vector);

	printf("Delete vector\n");
	deleteVector(&vector);
	printVector(*vector);

	printf("Write randomly on vector tweny times\n");
	for(int i=0; i<20; i+=1){
		writeOnVector(&vector, randomInRange(0, vector->size -1), randomInRange(-100,100));
	}
	printVector(*vector);

	printf("Resize randomly vector three times\n");
	for(int i=0; i<3; i+=1){
		resizeVector(&vector,randomInRange(1,20));
		printVector(*vector);
	}

	Vector* vector2 = 0x0;
	initVector(&vector2, vector->size);

	printf("Print vector two\n");
	printVector(*vector2);

	printf("Clon vector to vector2, print vector 2\n");
	cloneVector(&vector,&vector2);
	printVector(*vector2);
	
	printf("Destroy vector\n");
	destroyVector(vector);
}

#include <stdlib.h>
#include <string.h>

#ifndef GLOBAL_UTIL_FUN
#define GLOBAL_UTIL_FUN 
void validateNegative(int num){
	if(num<0){
		fprintf(stderr,"Number can\'t be negative\n");
		exit(EXIT_FAILURE);
	}
}

void validateSizePos(int size, int pos){
	validateNegative(size);
	validateNegative(pos);
	if(pos>size){
		fprintf(stderr,"Position can\'t be bigger than size\n");
		exit(EXIT_FAILURE);
	}
}

void validatePointer(void* pointer){
	if(pointer == 0x0){
		fprintf(stderr, "Couldn\'t allocate memory\n");
		exit(EXIT_FAILURE);
	}
}

int randomInRange(int lower, int upper){
	return (random() % (upper - lower + 1)) + lower;
}

int countDigits(int num, int * numSize){
	do{
		(* numSize)++;
		num /= 10; 
	}while(num != 0);

        return 0;
}

int integerToString(int num, char** strNum, int* strNumSize){
	int isNegative = (num<0)? 1:0;
	if(isNegative){
		*strNumSize += 1;
		num *= -1;
	}
	countDigits(num, strNumSize);
	*strNumSize += 1;
	*strNum = (char *) calloc(*strNumSize, sizeof(char));
	if(*strNum == 0x0){
		fprintf(stderr, "No enough memory for convert interger to string");
		exit(EXIT_FAILURE);
	}

	for(int i = (*strNumSize-2); i > -1; i--){
		*( (*strNum) + i ) = num%10 + '0';
		if(i==0 & isNegative) *( (*strNum) ) = 45;
		num /= 10;
	}
	return 0;
}

#endif

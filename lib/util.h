#include <stdlib.h>
#include <string.h>

#ifndef GLOBAL_UTIL_FUN
#define GLOBAL_UTIL_FUN 

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
	countDigits(num, strNumSize);
	*strNumSize += 1;
	*strNum = (char *) calloc(*strNumSize, sizeof(char));
	if(*strNum == 0x0){
		fprintf(stderr, "No enough memory for convert interger to string");
		exit(EXIT_FAILURE);
	}

	for(int i = (*strNumSize-2); i > -1; i--){
		*( (*strNum) + i ) = num%10 + '0';
		num /= 10;
	}
	return 0;
}

#endif

#include "global_err_def.h"
#include <stdlib.h>
#include <string.h>

#ifndef GLOBAL_UTIL_FUN
#define GLOBAL_UTIL_FUN 

int countDigits(int num, int * numSize){
	do{
		(* numSize)++;
		num /= 10; 
	}while(num != 0);

        return 0;
}

int integerToString(int num, char ** strNum, int* strNumSize){
	*strNumSize = 0;

	countDigits(num, strNumSize);

	free(*strNum); *strNum = 0x0;
	*strNum = (char *) malloc(sizeof(char)*(*strNumSize));
	if(*strNum == 0x0) return RESERVE_MEMORY_FAIL;

	for(int i = (*strNumSize-1); i > -1; i--){
		*( (*strNum) + i ) = num%10 + '0';
		num /= 10;
	}

	return 0;
}

#endif

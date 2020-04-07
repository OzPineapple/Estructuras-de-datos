#include "global_err_def.h"

#ifndef GLOBAL_UTIL_FUN
#define GLOBAL_UTIL_FUN 
int countDigits(int num, int * numSize){
        int count = 0;
        while(num/10 > 0){
                count++;
                num /= 10;
        }
        *numSize = count;
        return 0;
}

int integerToString(int num, char * strNum){
	int strNumSize;
	countDigits(num, &strNumSize);
	strNum = (char *) malloc(sizeof(char) * strNumSize);
	if(strNum == NULL) return RESERVE_MEMORY_FAIL;
	for(int i = 0; i < strNumSize; i++){
		strNum[i] = num%10;
		num /= 10;
	}
	return 0;
}
#endif

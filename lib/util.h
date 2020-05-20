#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UTIL_H
#define UTIL_H 

#define	cpprintf( format , type , pointer ) snprintf( 0x0 , 0 , format , * ( (type*) pointer ));

#define	pprintf( string ,  format , type , pointer ) sprintf( string , format , * ( (type*) pointer ) );

#define println printf( "\n" )

#define printtb printf( "\t" )

int randomInRange(int lower, int upper){
	if( lower > upper ){
		fprintf( stderr, "%s(): lower bigger than upper %i > %i\n", __FUNCTION__, lower, upper);
		exit(EXIT_FAILURE);
	}
	return ( rand() % (upper - lower + 1) ) + lower;
}

void countDigits(int num, int * numSize){
	do{
		(* numSize)++;
		num /= 10; 
	}while(num != 0);
}

void integerToString(int num, char** strNum, int* strNumSize){
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
		if( (i==0) & (isNegative) ) *( (*strNum) ) = 45;
		num /= 10;
	}
}

#endif

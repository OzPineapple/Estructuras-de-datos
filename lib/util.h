#ifndef _UTIL_H
#define _UTIL_H 

#define	cpprintf( format , type , pointer ) snprintf( 0x0 , 0 , format , * ( (type*) pointer ));

#define	pprintf( string ,  format , type , pointer ) sprintf( string , format , * ( (type*) pointer ) );

#define println printf( "\n" )

#define printtb printf( "\t" )

int randomInRange(int lower, int upper);

void countDigits(int num, int * numSize);

void integerToString(int num, char** strNum, int* strNumSize);

#endif //_UTIL_H
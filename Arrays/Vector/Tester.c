#include <stdio.h>
#include "Vector.h"
#include "../../Globals/global_err_fun.h"

int main(int argc, char * argv[]){
	printf("Vector tester\nBy Oz Pineapple\n");
	Vector vector;
	GLOBAL_ERROR_CODE = initVector(&vector,20);
	if(GLOBAL_ERROR_CODE>0) return printGlobalError();
	printf("Vector inited\n");
	char * vectorPhotography;
	GLOBAL_ERROR_CODE = seeVector( &vector, vectorPhotography );
	if(GLOBAL_ERROR_CODE>0) return printGlobalError();
	printf("Vector:%s", vectorPhotography );
}

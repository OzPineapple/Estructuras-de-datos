#include <stdio.h>
#include "Vector.h"
#include "../../Globals/global_err_fun.h"

int main(int argc, char * argv[]){
	printf("Vector tester\nBy Oz Pineapple\n");

	Vector vector;
	GLOBAL_ERROR_CODE = initVector(&vector,2);
	if(GLOBAL_ERROR_CODE>0) return printGlobalError();
	printf("Vector inited\n");

	int vectorPhotographySize = 0;
	char * vectorPhotography = 0x0;
	GLOBAL_ERROR_CODE = seeVector( &vector, &vectorPhotography, &vectorPhotographySize );
	if(GLOBAL_ERROR_CODE>0) return printGlobalError();
	printf("Vector:%s\n", vectorPhotography );
	free(vectorPhotography);

	GLOBAL_ERROR_CODE = seeVector( &vector, &vectorPhotography, &vectorPhotographySize );
	if(GLOBAL_ERROR_CODE>0) return printGlobalError();
	printf("Vector:%s\n", vectorPhotography );

	GLOBAL_ERROR_CODE = printVector(&vector);
	if(GLOBAL_ERROR_CODE>0) return printGlobalError();

	GLOBAL_ERROR_CODE = writeOnVector(&vector, 7, 19);	
	if(GLOBAL_ERROR_CODE>0) return printGlobalError();
}

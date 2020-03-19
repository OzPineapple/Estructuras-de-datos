#include "../../Globals/global_err_def.h"

int initCharArray(char * buffer, int size){
	if(size<0) return OVEEFLOW_VALUE;
	buffer = (char*) malloc(sizeof(chat)*size);
}

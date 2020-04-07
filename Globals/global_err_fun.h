/*ERROR CODES*/
/*This header is used manage the error codes that be origened during runtime, user the global vireble on the main program*/

int GLOBAL_ERROR_CODE;

char * getError(int ErrorCode){
	switch(ErrorCode){
		case 400:
			return "Recived NULL where value was expected";
		break;
		case 401:
			return "Recived underflow value argument";
		break;
		case 402:
			return "Recived overflow value argument";
		break;
		case 500:
			return "Look for memory falied, NULL returned by system";
		break;
	}	
}

char * getGlobalError(){
	return getError(GLOBAL_ERROR_CODE);
}

int printGlobalError(){
	printf("ERROR %i: %s", GLOBAL_ERROR_CODE, getError(GLOBAL_ERROR_CODE));
	return GLOBAL_ERROR_CODE;
}


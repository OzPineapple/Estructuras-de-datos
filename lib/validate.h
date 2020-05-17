#include <stdio.h>
#include <stdlib.h>

#ifndef VALIDATE_H
#define VALIDATE_H

#define getVarName( var ) (#var)

void validateSize_definition( int number, const char * number_name, const char * file_name, const char * function_name, const int line_number ){
        if( number < 1 ){
                fprintf( stderr, "EXCEPTION - %s:%i: Ilegal zero number or less as argument %s( %s:%i ), %i  < 1\n", file_name, line_number, function_name, number_name, number, number );
                exit( EXIT_FAILURE );
        }
}

void validateNegative_definition( int number, const char * number_name, const char * file_name, const char * function_name, const int line_number ){
        if( number < 0 ){
                fprintf( stderr, "EXCEPTION - %s:%i: Ilegal negative number as argument %s( %s:%i ), %i < 0 )\n", file_name, line_number, function_name, number_name, number, number);
                exit( EXIT_FAILURE );
        }
}

void validateSizeAndPosition_definition( int size, const char * size_name, int position, const char * position_name, const char * file_name, const char * function_name, const int line_number ){
        validateSize_definition( size, size_name, file_name, function_name, line_number );
        validateNegative_definition( position, position_name, file_name, function_name, line_number );

        if( position > (size - 1) ){
                fprintf( stderr, "EXCEPTION - %s:%i: Ilegal number bigger than asked as argument %s( %s:%i, %s:%i ), %i > %i\n", file_name, line_number, function_name, size_name, size, position_name, position, position, (size-1) );
                exit( EXIT_FAILURE );
        }
}

void validateMemory_definition( void * pointer, const char * pointer_name, const char * file_name, const char * function_name, const int line_number ){
        if( pointer == 0x0 ){
                fprintf( stderr, "ERROR - %s:%i: Couldn\'t allocate memory, gotted NULL %s( %s )\n", file_name, line_number, function_name, pointer_name );
		exit( EXIT_FAILURE );
	}
}

void validatePointer_definition( void * pointer, const char * pointer_name, const char * file_name, const char * function_name, const int line_number ){
	if( pointer == 0x0 ){
		fprintf( stderr, "EXCEPTION - %s:%i: Ilegal null pointer as argument %s( %s:␀ )\n", file_name, line_number, function_name, pointer_name );
		exit( EXIT_FAILURE );
	}
}

void validatePointerToPointer_definition( void * * pointer, const char * pointer_name, const char * file_name, const char * function_name, const int line_number ){
	if( pointer == 0x0 ){
		fprintf( stderr, "EXCEPTION - %s:%i: Ilegal null pointer as argument %s( %s:␀ )\n", file_name, line_number, function_name, pointer_name );
		exit( EXIT_FAILURE );
	}
	if( ( * pointer ) == 0x0 ){
		fprintf( stderr, "EXCEPTION - %s:%i: Ilegal null pointer as argument %s( %s:%p → ␀ )\n", file_name, line_number, function_name, pointer_name, pointer );
		exit( EXIT_FAILURE );
	}
}

#define valSize( number ) validateSize_definition( number, getVarName( number ), __FILE__, __FUNCTION__, __LINE__ );

#define valNeg( number ) validateNegative_definition( number, getVarName( number ), __FILE__, __FUNCTION__, __LINE__ );

#define valSizePos( size, position ) validateSizeAndPosition_definition( size, getVarName( size ), position, getVarName( position ), __FILE__, __FUNCTION__, __LINE__ );

#define valMem( pointer ) validateMemory_definition( pointer, getVarName( pointer ), __FILE__, __FUNCTION__, __LINE__ );

#define valPtr( pointer ) validatePointer_definition( pointer, getVarName( pointer ), __FILE__, __FUNCTION__, __LINE__ );

#define val2Ptr( pointer ) validatePointerToPointer_definition( pointer, getVarName( pointer ), __FILE__, __FUNCTION__, __LINE__ );

#endif

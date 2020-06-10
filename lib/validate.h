#ifndef VALIDATE_H
#define VALIDATE_H

void validateSize_definition( int number, const char * number_name, const char * file_name, const char * function_name, const int line_number );

void validateNegative_definition( int number, const char * number_name, const char * file_name, const char * function_name, const int line_number );

void validateSizeAndPosition_definition( int size, const char * size_name, int position, const char * position_name, const char * file_name, const char * function_name, const int line_number );

void validateMemory_definition( void * pointer, const char * pointer_name, const char * file_name, const char * function_name, const int line_number );

void validatePointer_definition( void * pointer, const char * pointer_name, const char * file_name, const char * function_name, const int line_number );

void validatePointerToPointer_definition( void * * pointer, const char * pointer_name, const char * file_name, const char * function_name, const int line_number );

#define getVarName( var ) (#var)

#define valSize( number ) validateSize_definition( number, getVarName( number ), __FILE__, __FUNCTION__, __LINE__ );

#define valNeg( number ) validateNegative_definition( number, getVarName( number ), __FILE__, __FUNCTION__, __LINE__ );

#define valSizePos( size, position ) validateSizeAndPosition_definition( size, getVarName( size ), position, getVarName( position ), __FILE__, __FUNCTION__, __LINE__ );

#define valMem( pointer ) validateMemory_definition( pointer, getVarName( pointer ), __FILE__, __FUNCTION__, __LINE__ );

#define valPtr( pointer ) validatePointer_definition( pointer, getVarName( pointer ), __FILE__, __FUNCTION__, __LINE__ );

#define val2Ptr( pointer ) validatePointerToPointer_definition( pointer, getVarName( pointer ), __FILE__, __FUNCTION__, __LINE__ );

#endif

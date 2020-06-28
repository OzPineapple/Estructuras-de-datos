#ifndef _VALIDAR_H
#define _VALIDAR_H

void validarTamanno_definicion( int numero, const char * numero_nombre, const char * archivo_nombre, const char * function_nombre, const int linea_numero );

void validarNegativo_definicion( int numero, const char * numero_nombre, const char * archivo_nombre, const char * function_nombre, const int linea_numero );

void validarTamannoPosicion_definicion( int tamanno, const char * tamanno_nombre, int posicion, const char * posicion_nombre, const char * archivo_nombre, const char * function_nombre, const int linea_numero );

void validarMemoria_definicion( void * puntero, const char * puntero_nombre, const char * archivo_nombre, const char * function_nombre, const int linea_numero );

void validarPuntero_definicion( void * puntero, const char * puntero_nombre, const char * archivo_nombre, const char * function_nombre, const int linea_numero );

void validarDoblePuntero_definicion( void * * puntero, const char * puntero_nombre, const char * archivo_nombre, const char * function_nombre, const int linea_numero );

#define obtenerNombreVariable( var ) (#var)

#define valTam( numero ) validarTamanno_definicion( numero, obtenerNombreVariable( numero ), __FILE__, __FUNCTION__, __LINE__ );

#define valNeg( numero ) validarNegativo_definicion( numero, obtenerNombreVariable( numero ), __FILE__, __FUNCTION__, __LINE__ );

#define valTamPos( tamanno, posicion ) validarTamannoPosicion_definicion( tamanno, obtenerNombreVariable( tamanno ), posicion, obtenerNombreVariable( posicion ), __FILE__, __FUNCTION__, __LINE__ );

#define valMem( puntero ) validarMemoria_definicion( puntero, obtenerNombreVariable( puntero ), __FILE__, __FUNCTION__, __LINE__ );

#define valPtr( puntero ) validarPuntero_definicion( puntero, obtenerNombreVariable( puntero ), __FILE__, __FUNCTION__, __LINE__ );

#define val2Ptr( puntero ) validarDoblePuntero_definicion( puntero, obtenerNombreVariable( puntero ), __FILE__, __FUNCTION__, __LINE__ );

#endif //_VALIDAR_H
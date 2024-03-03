#pragma once

#include <iostream>
#include <string>


template< typename T >
void swap( T & a, T & b ) {
	T tmp = a;
	a = b;
	b = tmp;
}

template< typename T >
T & min( T & a, T & b ) {
	return ( a < b ) ? a : b;
}

template< typename T >
T & max( T & a, T & b ) {
	return ( a > b ) ? a : b;
}

template< typename T >
T & iter( T * array, size_t size, T (*f)( T & a, T & b ) ) {
	T & result = array[0];
	for ( size_t i = 1; i < size; i++ ) {
		result = f( result, array[i] );
	}
	return result;
}

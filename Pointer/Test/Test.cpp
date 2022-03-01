
//#undef _UNICODE

#include <stdio.h>
#include <utility>

#include <tchar.h>
#include "header.h"
#include "header.h"
#include <windows.h>

#define NDEBUG
#include <assert.h>

void func3( int& g )
{
	printf( "&g = %p\n", &g );
	++g;
}

void func2( int* g )
{
	printf( "g = %p\n", g );
	printf( "&g = %p\n", &g );
	++(*g);
}

void func( int g )
{
	printf( "&g = %p\n", &g );
	++g;
}


int main() 
{
	int b = 2;

	printf( "b = %d\n", b );
	printf( "&b = %p\n\n", &b );
	func( b );
	printf( "b = %d\n\n", b );
	func2( &b );
	printf( "b = %d\n\n", b );
	func3( b );
	printf( "b = %d\n\n", b );


	struct A
	{
		int a[3] = { 1,2,3 };
		int c = 9;
	};
	struct A a;

	printf( "a = %d\n", *(a.a+4) );

	return 0;
}


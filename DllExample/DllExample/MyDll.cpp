
#include <stdio.h>
#include "MyDll.h"

int MyClass::MyAdd( int a, int b )
{
	return a + b;
}

MyClass::~MyClass( void )
{
	printf( "MyClass Destroyed\n" );
}

int MY_DLL_CALL MyMultiple( int a, int b )
{
	return a * b;
}

int MyNumber = 4;

MyVirtualClass* MY_DLL_CALL MyCreateClass( void )
{
	return new MyClass();
}
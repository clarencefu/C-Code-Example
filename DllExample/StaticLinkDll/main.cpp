
#include <stdio.h>
#include <windows.h>
#include "..\DllExample\MyDll.h"

//add MyDll.lib into reference

int main( void )
{
	MyClass myClass;
	printf( "Call MyAdd(2,3) = %d\n", myClass.MyAdd( 2, 3 ) );

	printf( "Call MyMultiple(2,3) = %d\n", MyMultiple( 2, 3 ) );

	printf( "MyNumber = %d\n", MyNumber );

	system( "pause" );
	return 0;
}
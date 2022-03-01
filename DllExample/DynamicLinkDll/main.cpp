
#include <windows.h>
#include <stdio.h>


// do not need to add MyDll.lib into reference

// do not need to include MyDll.h into reference
//#define USING_HEADER
#ifdef USING_HEADER
#include "..\DllExample\MyDll.h"
typedef MyVirtualClass* ( __cdecl *MyCreateClassType )( void );
#endif

typedef int ( __cdecl *MyMultipleType)( int a, int b );


//----------------------------------------------------------
int main( void )
{
	HINSTANCE dllHandle = LoadLibrary( "MyDll.dll" );
	// If the handle is valid, try to get the function address. 
	if ( NULL == dllHandle )
	{
		printf( "DLL ""MyDll.dll"" not found\n" );
		system( "pause" );
		return 1;
	}

#ifdef USING_HEADER
	//Get pointer to class creator:
	MyCreateClassType MyCreateClass = (MyCreateClassType)GetProcAddress( dllHandle, "MyCreateClass" );
	if ( NULL == MyCreateClass )
	{
		printf( "Function ""MyCreateClass"" not found\n" );
	}
	else
	{
		MyVirtualClass* myClass = MyCreateClass();
		printf( "Call MyAdd(2,3) = %d\n", myClass->MyAdd( 2, 3 ) );
		delete myClass;
	}
#endif

	//Get pointer to function:
	MyMultipleType MyMultipleFunction = (MyMultipleType)GetProcAddress( dllHandle, "MyMultiple" );
	if ( NULL == MyMultipleFunction )
	{
		printf( "Function ""MyMultiple"" not found\n" );
	}
	else
	{
		printf( "Call MyMultiple(2,3) = %d\n", MyMultipleFunction( 2, 3 ) );
	}

	//Get pointer to dll variable
	int* MyNumber = (int*)GetProcAddress( dllHandle, "MyNumber" );
	if ( NULL == MyNumber )
	{
		printf( "Int ""MyNumber"" not found\n" );
	}
	else
	{
		printf( "MyNumber = %d\n", *MyNumber );
	}

	FreeLibrary( dllHandle );

	system( "pause" );
	return 0;
}
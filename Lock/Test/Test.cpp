// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>
#include <math.h>
#include <queue>
#include <typeinfo.h> 
#include <windows.h>
#include <conio.h>
#include <mutex>

//----------------------------------------------------------
// Try, catch, exception
// Ref: http://www.cplusplus.com/doc/tutorial/exceptions/
//----------------------------------------------------------
int g_a = 0;
std::mutex m;
bool isAddTurn = true;

#define TIME 0

DWORD WINAPI MyBackGroundAdd( LPVOID lpParam )
{
	while ( true )
	{
		m.lock();
		//if ( isAddTurn )
		//{
			printf( "1: %d\n", g_a++);
		//	isAddTurn = false;
		//}
		m.unlock();
		Sleep( TIME );
	}
	return 0;
}

DWORD WINAPI MyBackGroundSubtract( LPVOID lpParam )
{
	while ( true )
	{
		m.lock();
		//if ( !isAddTurn )
		//{
			printf( "2: %d\n", g_a++ );
		//	isAddTurn = true;
		//}
		m.unlock();
		Sleep( TIME );
		
	}
	return 0;
}

DWORD WINAPI MyBackGroundPrint( LPVOID lpParam )
{
	while ( true )
	{
		printf( "%d\n", g_a );
		Sleep( 1000 );
	}
	return 0;
}

int main()
{
	CreateThread( NULL,
				  NULL,
				  MyBackGroundAdd,
				  0,
				  0,
				  NULL
	);

	//Sleep( 50 );
	CreateThread( NULL,
				  NULL,
				  MyBackGroundSubtract,
				  0,
				  0,
				  NULL
	);
	/*Sleep( 50 );
	CreateThread( NULL,
				  NULL,
				  MyBackGroundPrint,
				  0,
				  0,
				  NULL
	);*/

	while ( !kbhit() )
	{
	}

	return 0;
}

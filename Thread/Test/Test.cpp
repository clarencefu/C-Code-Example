// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>
#include <math.h>
#include <queue>
#include <typeinfo.h> 
#include <windows.h>
#include <conio.h>

//----------------------------------------------------------
// Try, catch, exception
// Ref: http://www.cplusplus.com/doc/tutorial/exceptions/
//----------------------------------------------------------

bool g_threadRunning;
class CCallBack;
CCallBack* g_callback = nullptr;


class CCallBack 
{
public:
	virtual void MyPrint() 
	{ 
		printf( "123\n" ); 
	}
};

DWORD WINAPI MyBackGround( LPVOID lpParam )
{
	g_threadRunning = true;
	int* a = (int*)lpParam;
	
	while ( g_threadRunning )
	{
		printf( "%d: \n", *a );
		if ( nullptr != g_callback )
		{
			g_callback->MyPrint();
		}
		Sleep( 1000 );
	}
	return 0;
}

void Start( int& id ) 
{
	int* a = &id;
	HANDLE thread = CreateThread( NULL,
								  NULL,
								  MyBackGround,
								  a,
								  0,
								  NULL
	);
}

void AddCallback( CCallBack& callback )
{
	g_callback = &callback;
}

void Stop()
{
	g_threadRunning = false;
}
//==========================================================
// Header
//==========================================================
void Start( int& id );
void AddCallback( CCallBack& callback );
void Stop();

//==========================================================
// Cpp
//==========================================================
class CMyCallBack : public CCallBack
{
public:
	virtual void MyPrint()
	{
		printf( "321\n" );
	}
};

int main()
{
	int a = 4;
	CMyCallBack myCallback;
	
	Start( a );
	AddCallback( myCallback );
	Sleep( 10000 );
	Stop();

	return 0;
}

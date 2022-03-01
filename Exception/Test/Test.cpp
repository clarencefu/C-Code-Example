// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>
#include <math.h>
#include <queue>

//----------------------------------------------------------
// Try, catch, exception
// Ref: http://www.cplusplus.com/doc/tutorial/exceptions/
//----------------------------------------------------------

//----------------------------------------------------------
double MySqrt( double value )  throw ( MyException );
//----------------------------------------------------------

class MyException : std::exception
{
public:
	virtual char const* what() const
	{
		return "GG";
	}
};

double MySqrt( double value )  throw (MyException)
{
	if ( value < 0 )
	{
		throw MyException();
	}

	return sqrt( value );
}

double AnotherSqrt( double value ) throw( double )
{
	try 
	{
		if ( 0 == value )
		{
			throw std::exception( "I do not like 0" );
		}
		
		return MySqrt( value );
	}
	catch ( MyException e )
	{
		printf( "%s\n", e.what() );
		throw ( value );
	}
}

int main()
{
	try 
	{
		double a = AnotherSqrt( 2 );
		a = AnotherSqrt( -1 );
		AnotherSqrt( 0 );
	}
	catch ( double i )
	{
		printf( "%lf cannot be square rooted.\n", i );
	}
	catch ( MyException e )
	{
		printf( "%s\n", e.what() );
	}
	catch ( std::exception e )
	{
		printf( "%s\n", e.what() );
	}
	catch ( ... )
	{
		printf( "..." );
	}

    return 0;
}


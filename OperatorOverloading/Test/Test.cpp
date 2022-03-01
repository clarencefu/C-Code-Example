// Test.cpp : Defines the entry point for the console application.
//

//#define _USE_MATH_DEFINES
#include "stdafx.h"
#include <exception>
#include <queue>
#include <typeinfo.h> 
#include <windows.h>
#include <conio.h>
#include <mutex>
#include <math.h>
#include "targetver.h"


//----------------------------------------------------------
// Try, catch, exception
// Ref: http://www.cplusplus.com/doc/tutorial/exceptions/
//----------------------------------------------------------


class MyArray
{
public:
	//default constructor, auto generator
	MyArray()
		: value( SIZE )
	{
		value[0] = 0;
		value[1] = 0;
		value[2] = 0;
	}

	//value constructor
	MyArray( double a1, double a2, double a3 ) 
		: value( SIZE )
	{
		value[0] = a1;
		value[1] = a2;
		value[2] = a3;
	}

	MyArray( double rhs[3]  )
		: value( SIZE )
	{
		for ( int i = 0 ; i < SIZE ; ++i )
		{
			value[i] = rhs[i];
		}
	}

	//copy constructor, auto generator
	MyArray( const MyArray& rhs )
		: value( SIZE )
	{
		for ( int i = 0 ; i < SIZE ; ++i )
		{
			value[i] = rhs.value[i];
		}
	}

	void Print() 
	{
		printf( "value: " );
		for ( int i = 0 ; i < SIZE ; ++i )
		{
			printf( "%6f  ", value[i] );
		}
		printf( "\n" );
	}

	MyArray operator+ ( const MyArray& rhs )
	{
		MyArray result;
		for ( int i = 0 ; i < SIZE ; ++i )
		{
			result.value[i] = this->value[i] + rhs.value[i];
		}
		return result;
	}

	MyArray operator+ ( const double rhs )
	{
		MyArray result;
		for ( int i = 0 ; i < SIZE ; ++i )
		{
			result.value[i] = this->value[i] + rhs;
		}
		return result;
	}

	MyArray operator+ ( const double rhs[3] )
	{
		MyArray result;
		for ( int i = 0 ; i < SIZE ; ++i )
		{
			result.value[i] = this->value[i] + rhs[i];
		}
		return result;
	}

	double operator[] ( const int i )
	{
		if ( i < SIZE && i >= 0 ) 
		{
			return this->value[i];
		}
		return 0;
	}

	// assign operator, auto generator
	MyArray& operator= ( const MyArray& rhs )
	{
		for ( int i = 0 ; i < SIZE ; ++i )
		{
			this->value[i] = rhs.value[i];
		}
		return *this;
	}

private:
	enum { SIZE = 3 };
	std::vector<double> value;
};

int main()
{	
	MyArray a( 1, 2, 3 );
	MyArray b( 2, 4, 6 );
	double k[3] = { 1,11,1 };
	
	//a = b;	// a.operator=( b );
	//a.Print();
	
	MyArray c = a + k;	//copy constructor
	//c = a;	//assign operator
	c.Print();

	double v = a[1];	//a.operator[](1)

	MyArray d( k );
	d.Print();
	
	return 0;
}

// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>
#include <math.h>
#include <queue>
#include <typeinfo.h> 

//----------------------------------------------------------
// Try, catch, exception
// Ref: http://www.cplusplus.com/doc/tutorial/exceptions/
//----------------------------------------------------------

struct Base
{
	virtual ~Base() {}
	int base = 0;
};

struct Derived : Base
{
	virtual void name() {}
	int derived = 1;
};

int main()
{
	try
	{
		Base* b1 = new Base;
		Derived *c = dynamic_cast<Derived*>( b1 );
		//Derived &a = dynamic_cast<Derived&>( *b1 );


		Base* b2 = new Derived;
		Derived* b = dynamic_cast<Derived*>( b2 );

		delete b1;
		delete b2;
	}
	catch ( std::bad_cast b )
	{
		int a = 4;
	}
	catch ( ... )
	{
		int a = 3;
	}


	
	

    return 0;
}


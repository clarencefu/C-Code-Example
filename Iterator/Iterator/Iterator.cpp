// Iterator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	vector<int> vect( 5 );
	for ( int i = 0 ; i < 5 ; ++i )
	{
		vect[i] = i;
	}

	//declare iterator
	std::vector<int>::iterator it;

	//usage
	for ( it = vect.begin() ; it != vect.end() ; ++it )
	{
		printf( "%d\n", *it );
	}
	printf( "\n" );

	it = vect.begin();
	while ( 3 != *it )
	{
		++it;
	}

	vect.insert( it, 2, 0 );

	for ( it = vect.begin() ; it != vect.end() ; ++it )
	{
		printf( "%d\n", *it );
	}
	printf( "\n" );

	
	//it = vect.begin();
	//--it;
	//it = vect.end();
	//it++;


	return 0;
}


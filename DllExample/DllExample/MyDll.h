
//====================================================
// File: 
// data: 2018-08-02
// Ctor: Zipher
// Note: 
//====================================================
#pragma once
#ifndef MY_DLL_H
#define MY_DLL_H

#if defined MY_DLL_EXPORTS
#	define MY_DLL_DLL __declspec(dllexport)
#elif defined MY_DLL_INTERNAL
#	define MY_DLL_DLL
#else
#	define MY_DLL_DLL __declspec(dllimport)
#endif

#define MY_DLL_CALL __cdecl

//export class
class MY_DLL_DLL MyVirtualClass
{
public:
	virtual int MyAdd( int a, int b ) = 0;
	virtual ~MyVirtualClass() {};	//very important
};

class MY_DLL_DLL MyClass : public MyVirtualClass
{
public:
	int MyAdd( int a, int b );
	~MyClass();
};

#ifdef __cplusplus
// do not use c++ name mangling
extern "C"
{
	MY_DLL_DLL int MY_DLL_CALL MyMultiple( int a, int b );

	//export variable
	MY_DLL_DLL extern int MyNumber;

	MY_DLL_DLL MyVirtualClass* MY_DLL_CALL MyCreateClass( void );
}
#endif



#endif



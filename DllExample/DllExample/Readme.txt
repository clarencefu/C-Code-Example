
1. Project Property -> General -> Project Defaults -> Configuration Type = Dynamic Library (.dll)
2. Project Property -> C/C++ -> Prepropcessor -> Preprocessor Definitions += MY_DLL_EXPORTS 
3. Add macro into .h
	#if defined MY_DLL_EXPORTS
	#	define MY_DLL_DLL __declspec(dllexport)
	#elif defined MY_DLL_INTERNAL
	#	define MY_DLL_DLL
	#else
	#	define MY_DLL_DLL __declspec(dllimport)
	#endif

	#define MY_DLL_CALL __stdcall
4. 
#pragma once

/*
	__declspec(dllexport)		DLL Projesinde
	__declspec(dllimport)		EXE Projesinde
*/

#ifdef BE_EXPORT
	#define BE_API __declspec(dllexport)
#else
	#define BE_API __declspec(dllimport)
#endif

namespace bioengine {

	class BE_API Hello
	{
	public:
		static void SayHello();
	};

}
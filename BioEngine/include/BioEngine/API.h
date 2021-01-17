#pragma once

#ifdef BE_EXPORT
	#define BE_API __declspec(dllexport)
#else
	#define BE_API __declspec(dllimport)
#endif
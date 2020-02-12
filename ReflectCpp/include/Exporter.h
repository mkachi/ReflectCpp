#pragma once

#ifdef _MSC_VER
	#ifdef DLL_EXPORTS
		#define DLL_API __declspec(dllexport)
	#else
		#define DLL_API __declspec(dllimport)
	#endif
#else
	#define DLL_API
#endif

#if defined(DLL_API)
	#define RF_API DLL_API
#endif
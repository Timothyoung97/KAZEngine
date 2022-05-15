#pragma once

#ifdef KE_PLATFORM_WINDOWS
	#ifdef KE_BUILD_DLL
		#define KAZENGINE_API __declspec(dllexport)
	#else 
		#define KAZENGINE_API __declspec(dllimport)
	#endif
#else
	#error KAZEngine only supports WINDOWS!
#endif

#define BIT(x) (1 << x)
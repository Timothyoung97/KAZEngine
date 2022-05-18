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

#ifdef KAZENGINE_ENABLE_ASSERTS
	#define KAZENGINE_ASSERT(x, ...) { if (!(x)) { KAZENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KAZENGINE_CORE_ASSERT(x, ...) {if (!(x)) { KAZENGINE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KAZENGINE_ASSERT(x, ...)
	#define KAZENGINE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
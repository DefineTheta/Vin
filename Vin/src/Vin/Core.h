#pragma once

#ifdef VIN_PLATFORM_WINDOWS
	#ifdef VIN_BUILD_DLL
		#define VIN_API __declspec(dllexport)
	#else
		#define VIN_API __declspec(dllimport)
	#endif // VIN_BUILD_DLL
#else
	#error Vin Engine only supports windows!
#endif // VIN_PLATFORM_WINDOWS
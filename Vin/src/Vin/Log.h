#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Vin {

	class VIN_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_AppLogger;
	
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return s_AppLogger; }
	};

}

#ifdef VIN_CONFIGURATION_DEBUG
	//Engine logging macros
	#define VIN_ENGINE_TRACE(...)       Vin::Log::GetEngineLogger()->trace(__VA_ARGS__)
	#define VIN_ENGINE_DEBUG(...)       Vin::Log::GetEngineLogger()->debug(__VA_ARGS__)
	#define VIN_ENGINE_INFO(...)        Vin::Log::GetEngineLogger()->info(__VA_ARGS__)
	#define VIN_ENGINE_WARN(...)        Vin::Log::GetEngineLogger()->warn(__VA_ARGS__)
	#define VIN_ENGINE_ERROR(...)       Vin::Log::GetEngineLogger()->error(__VA_ARGS__)
	#define VIN_ENGINE_CRITICAL(...)    Vin::Log::GetEngineLogger()->critical(__VA_ARGS__)


	//Engine logging macros
	#define VIN_TRACE(...)              Vin::Log::GetAppLogger()->trace(__VA_ARGS__)
	#define VIN_DEBUG(...)              Vin::Log::GetAppLogger()->debug(__VA_ARGS__)
	#define VIN_INFO(...)               Vin::Log::GetAppLogger()->info(__VA_ARGS__)
	#define VIN_WARN(...)               Vin::Log::GetAppLogger()->warn(__VA_ARGS__)
	#define VIN_ERROR(...)              Vin::Log::GetAppLogger()->error(__VA_ARGS__)
	#define VIN_CRITICAL(...)           Vin::Log::GetAppLogger()->critical(__VA_ARGS__)
#else
	//Engine logging macros
	#define VIN_ENGINE_TRACE(...)   
	#define VIN_ENGINE_DEBUG(...)   
	#define VIN_ENGINE_INFO(...)    
	#define VIN_ENGINE_WARN(...)    
	#define VIN_ENGINE_ERROR(...)   
	#define VIN_ENGINE_CRITICAL(...)


	//Engine logging macros
	#define VIN_TRACE(...)          
	#define VIN_DEBUG(...)          
	#define VIN_INFO(...)           
	#define VIN_WARN(...)           
	#define VIN_ERROR(...)          
	#define VIN_CRITICAL(...)
#endif // VIN_CONFIGURATION_DEBUG
#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace KAZEngine 
{

	class KAZENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


}

// Core log marcos
#define KAZENGINE_CORE_TRACE(...)	::KAZEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KAZENGINE_CORE_INFO(...)	::KAZEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KAZENGINE_CORE_WARN(...)	::KAZEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KAZENGINE_CORE_ERROR(...)	::KAZEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KAZENGINE_CORE_FATAL(...)	::KAZEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log marcos
#define KAZENGINE_TRACE(...)		::KAZEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KAZENGINE_INFO(...)			::KAZEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define KAZENGINE_WARN(...)			::KAZEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KAZENGINE_ERROR(...)		::KAZEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define KAZENGINE_FATAL(...)		::KAZEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
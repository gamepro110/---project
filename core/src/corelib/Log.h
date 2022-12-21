#pragma once

#include "base.h"

// this ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

#include <memory>

namespace ABC_Name {
	class Log {
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ABC_Core_TRACE(...)		::ABC_Name::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ABC_Core_INFO(...)		::ABC_Name::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ABC_Core_WARN(...)		::ABC_Name::Log::GetCoreLogger()->warning(__VA_ARGS__)
#define ABC_Core_ERROR(...)		::ABC_Name::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ABC_Core_CRITICAL(...)	::ABC_Name::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ABC_TRACE(...)			::ABC_Name::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ABC_INFO(...)			::ABC_Name::Log::GetClientLogger()->info(__VA_ARGS__)
#define ABC_WARN(...)			::ABC_Name::Log::GetClientLogger()->warning(__VA_ARGS__)
#define ABC_ERROR(...)			::ABC_Name::Log::GetClientLogger()->error(__VA_ARGS__)
#define ABC_CRITICAL(...)		::ABC_Name::Log::GetClientLogger()->critical(__VA_ARGS__)

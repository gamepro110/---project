#pragma once

#include "base.h"
#include "Log.h"

#include <filesystem>

#if defined(ABC_ENABLE_ASSERTS)
#	define ABC_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) {ABC##type##ERROR(msg, __VA_ARGS__); ABC_DEBUGBREAK();}}
#	define ABC_INTERNAL_ASSERT_WITH_MSG(type, check, ...) ABC_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#	define ABC_INTERNAL_ASSERT_NO_MSG(type, check) ABC_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", ABC_STRINGIFY_MACRO(check). std::filesystem::path(__FILE__).filename().string(), __LINE__)

#	define ABC_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#	define ABC_INTERNAL_ASSERT_GET_MACRO(...) ABC_EXPAND_MACRO(ABC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, ABC_INTERNAL_ASSERT_WITH_MSG, ABC_INTERNAL_ASSERT_NO_MSG))

#	define ABC_ASSERT(...) ABC_EXPAND_MACRO(ABC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__)(_,__VA_ARGS__))
#	define ABC_CORE_ASSERT(...) ABC_EXPAND_MACRO(ABC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__)(_CORE_, __VA_ARGS__))
#else
#	define ABC_ASSERT(...)
#	define ABC_CORE_ASSERT(...)
#endif

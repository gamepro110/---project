#pragma once

#if defined(ABC_DEBUG)
#	if defined(ABC_WINDOWS)
#		define ABC_DEBUGBREAK() __debugbreak()
#	elif defined(ABC_LINUX)
#		include <signal.h>
#		define ABC_DEBUGBREAK() raise(SIGTRAP)
#	else
#		error "Platform does not suported debug yet!"
#	endif
#	define ABC_ENABLE_ASSERTS
#else
#	define ABC_DEBUGBREAK()
#endif

#define ABC_EXPAND_MACRO(x) x
#define ABC_STRINGIFY_MACRO(x) #x

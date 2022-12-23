# global config
cmake_minimum_required(VERSION 3.16)

project(ABC_Project)

# find packages
find_package(Threads REQUIRED)
if(WIN32)
	find_package(Vulkan REQUIRED)
elseif(UNIX)
	if(APPLE)
		find_package(Metal REQUIRED)
	else()
		find_package(Vulkan REQUIRED)
	endif()
endif()

# project wide defines
## config defines
set(currentPreset ${CMAKE_BUILD_TYPE})
if(currentPreset STREQUAL "Debug")
	add_definitions(
		-DABC_DEBUG
		#-DABC_ENABLE_ASSERTS
	)
elseif(currentPreset STREQUAL "Release")
	add_definitions(-DABC_RELEASE)
elseif(currentPreset STREQUAL "MinSizeRel")
	add_definitions(-DABC_DIST)
endif()

## os defines
if(WIN32)
	add_definitions(-DABC_WINDOWS)
elseif(UNIX)
	if(APPLE)
		add_definitions(-DABC_MACOS)
	else()
		add_definitions(-DABC_LINUX)
	endif()
endif()
# project wide defines

add_definitions(
    -DWall # turn on a pool of warnings
    -DWerror # see warnings as errors
    -DWextra # enables flags not enabled by -Wall
    -DWconversion # shows conversion errors
    -DWunnused
)

set(CMAKE_CXX_STANDARD 20)
set(vendorPath "${PROJECT_SOURCE_DIR}/vendor")

add_subdirectory(vendor)
add_subdirectory(core)
add_subdirectory(app)
#add_subdirectory(docs)

enable_testing()
add_subdirectory(tests)

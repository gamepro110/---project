# core lib config
file(
    GLOB_RECURSE
    CORELIB_SRC
    "src/*.cpp"
    "src/*.h"
)

add_library(
    CoreLib
    STATIC
    ${CORELIB_SRC}
)

target_link_libraries(
    CoreLib
    PUBLIC spdlog
    PUBLIC glfw
    PUBLIC IMGUI_LIB
)

target_include_directories(
    CoreLib
    PUBLIC
    "${vendorPath}/dear-imgui/"
    "${vendorPath}/GLFW/include"
    "${vendorPath}/spdlog/include"

    "${Vulkan_INCLUDE_DIRS}"
)

set_target_properties(
    CoreLib
    PROPERTIES
    VERSION 1.0
    POSITION_INDEPENDENT_CODE ON
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED TRUE
    FOLDER "ABC_PROJECT FOLDER"
)

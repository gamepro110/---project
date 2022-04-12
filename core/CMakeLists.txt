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

set_target_properties(
    CoreLib
    PROPERTIES
    VERSION 1.0
    POSITION_INDEPENDENT_CODE ON
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED TRUE
    FOLDER "---PROJECT FOLDER"
)

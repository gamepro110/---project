# app config
file(
    GLOB_RECURSE
    App_SRC
    "src/*.cpp"
    "src/*.h"
)

add_executable(
    App
    WIN32
    ${App_SRC}
)

set_target_properties(
    App
    PROPERTIES
    VERSION 1.0
    POSITION_INDEPENDENT_CODE ON
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED TRUE
    FOLDER "---PROJECT FOLDER"
)

target_link_libraries(
    App
    PUBLIC
    CoreLib
)

target_include_directories(
    App
    PUBLIC
    "${PROJECT_SOURCE_DIR}/core/src/"
)
    
# app config
file(
    GLOB_RECURSE
    App_SRC
    "src/*.cpp"
    "src/*.h"
)

if(WIN32 AND ${CMAKE_BUILD_TYPE} STREQUAL "MinSizeRel")
    # windows dist specification
    add_executable(
        App
        WIN32
        ${App_SRC}
    )
else()
    add_executable(
        App
        ${App_SRC}
    )
endif()


set_target_properties(
    App
    PROPERTIES
    VERSION 1.0
    POSITION_INDEPENDENT_CODE ON
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED TRUE
    FOLDER "ABC_PROJECT FOLDER"
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
    
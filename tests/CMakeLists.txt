# tests config
find_package(Catch2 REQUIRED)

include(AddTests.cmake)

add_library(catch_main OBJECT catch/catch_main.cpp)
target_link_libraries(
    catch_main
    PUBLIC
    Catch2::Catch2
    Catch2::Catch2WithMain
)
set_target_properties(
    catch_main
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    FOLDER "unittests/"
)

add_custom_target(
    CompileTests
    DEPENDS ALL_BUILD #RUN_TESTS
)

AddTests("Example" "src/example/example.cpp" "")

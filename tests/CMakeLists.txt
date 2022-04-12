# tests config

enable_testing()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

# https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html
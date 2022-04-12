# global config
cmake_minimum_required(VERSION 3.16)

project(---Project)

set(vendorPath "${PROJECT_SOURCE_DIR}/vendor")

add_subdirectory(vendor)
add_subdirectory(core)
add_subdirectory(app)
add_subdirectory(tests)

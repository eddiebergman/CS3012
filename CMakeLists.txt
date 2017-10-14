# Cmake lowest-common-ancestor
#

#---------------
# Cmake settings
#---------------
cmake_minimum_required(VERSION 3.9.0)
project(lowest-common-ancestor)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/")

#---------------
# lowest-common-ancestor @header only library
#---------------
set(PROJ_NAME "lowest-common-ancestor")
set(PROJ_SOURCES_PATH "${PROJECT_SOURCE_DIR}/src")
set(PROJ_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")

file(GLOB PROJ_SOURCES "${PROJ_SOURCES_PATH}/*.cpp")
file(GLOB PROJ_HEADERS "${PROJ_INCLUDE_PATH}/*.hpp")

##set up the actual library

#
# Cmake lowest-common-ancestor : test
#

#---------------
# Catch
#---------------
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE "${PROJECT_SOURCE_DIR}/test/lib/catch")


#---------------
# test-lowest-common-ancestor @test executable
#---------------
set(TEST_NAME "test-${PROJ_NAME}")
set(TEST_SOURCES_PATH "${PROJECT_SOURCE_DIR}/test/src")

file(GLOB TEST_SOURCES "${TEST_SOURCES_PATH}/*.cpp")

add_executable(${TEST_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_NAME} Catch)

#---------------
# Ctest
#---------------
enable_testing()
add_test(NAME test_runner COMMAND ${TEST_NAME})
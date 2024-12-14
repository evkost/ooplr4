cmake_minimum_required(VERSION 3.28)
project(ooplr4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")


add_library(ooplr4_include INTERFACE)
target_include_directories(ooplr4_include INTERFACE ${INCLUDE_DIR})

add_executable(ooplr4_exe "${SRC_DIR}/main.cpp")
target_link_libraries(ooplr4_exe ooplr4_include)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/0953a17a4281fc26831da647ad3fcd5e21e6473b.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

file(GLOB TEST_SOURCES "${TEST_DIR}/*.cpp")
add_executable(ooplr4_tests ${TEST_SOURCES})
target_link_libraries(ooplr4_tests
        ooplr4_include
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ooplr4_tests)

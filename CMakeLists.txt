# Builds and runs the GoogleTest suite on macOS and Linux. The Visual Studio solution is unchanged.
cmake_minimum_required(VERSION 3.20)
project(multi_type_orderbook CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

# GoogleTest is fetched at configure time (pinned by hash)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    URL_HASH SHA256=1f357c27ca988c3f7c6b4bf68a9395005ac6761f034046e9dde0896e3aba00e4
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(Threads REQUIRED)

enable_testing()
# Same files as the Visual Studio test project: test.cpp #includes the book's .cpp files
add_executable(OrderbookTests
    OrderbookTest/test.cpp
    OrderbookTest/MatchingContractTests.cpp
)
target_include_directories(OrderbookTests PRIVATE OrderbookTest)
target_link_libraries(OrderbookTests PRIVATE GTest::gtest_main Threads::Threads)
include(GoogleTest)
# test.cpp reads TestFiles/ relative to the working directory; the timeout turns a deadlock into a failure
gtest_discover_tests(OrderbookTests
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/OrderbookTest
    PROPERTIES TIMEOUT 20
)

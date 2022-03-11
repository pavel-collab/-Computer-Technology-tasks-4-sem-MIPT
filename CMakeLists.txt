# CMAKE MINIMAL VERSION
cmake_minimum_required (VERSION 3.11)

# PROJECT PROPERTIES
project ("Fractions" LANGUAGES C CXX)

# THE 17TH STANDART
set(CMAKE_CXX_STANDARD 17)

# EXECUTABLE FILE PROPERTIES
set(MAIN "main")
set(TEST "test")

set(HEADERS
    frac_class.hpp
)

# SRC FILES
set(SRC_MAIN main.cpp)
set(SRC_TEST test.cpp)

# EXECUTABLES
add_executable(${MAIN} ${SRC_MAIN})

################################
# GTest
################################
# ADD_SUBDIRECTORY(gtest-1.6.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable(runUnitTests test.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main pthread)
add_test(runUnitTests runUnitTests)

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wnarrowing 
    -Wwrite-strings 
    -Wcast-qual 
    -Wundef 
    -Wstrict-prototypes 
    -Wbad-function-cast
)
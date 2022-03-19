# CMAKE MINIMAL VERSION
cmake_minimum_required (VERSION 3.11)

# PROJECT PROPERTIES
project ("Fractions" LANGUAGES C CXX)

# THE 17TH STANDART
set(CMAKE_CXX_STANDARD 17)

# EXECUTABLE FILE PROPERTIES
set(MAIN "main")
set(TEST "runUnitTests")

set(HEADERS
    frac_class.hpp
)

# SRC FILES
set(SRC_MAIN src/main.cpp)
set(SRC_TEST test/test.cpp)

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
add_executable(runUnitTests ${SRC_TEST})
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main pthread)
add_test(runUnitTests runUnitTests)

# TARGETS INCLUDE DERICTORIES
target_include_directories(${MAIN} PRIVATE include src)
target_include_directories(${TEST} PRIVATE include test)

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
cmake_minimum_required(VERSION 4.1.0)
project(HelloComputations LANGUAGES CXX)

option(CODE_COVERAGE "Enable coverage reporting" ON)

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Building with coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable warnings
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Source files
set(SOURCES
    Main.cpp
    Computation.cpp
)

# Header files (optional for IDEs)
set(HEADERS
    Computation.hpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Optional: organize in folders for IDEs
source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

# test
include(FetchContent)

# Fetch Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.9.1 # or latest stable
)
FetchContent_MakeAvailable(Catch2)

# Add test executable
add_executable(ComputationTests test_Computation.cpp Computation.cpp)
target_link_libraries(ComputationTests PRIVATE Catch2::Catch2WithMain)

# Enable CTest
include(CTest)
include(Catch)
catch_discover_tests(ComputationTests)
cmake_minimum_required(VERSION 3.16)
project(HelloComputations LANGUAGES CXX)

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
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

# Create static library from source
add_library(computation STATIC
    Computation.cpp
)

# Include headers
target_include_directories(computation PUBLIC
    ${PROJECT_NAME}/include
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_executable(test_app main.cpp)

target_include_directories(test_app PRIVATE
    ${PROJECT_NAME}/include
)

target_link_libraries(test_app PRIVATE computation)


# Optional: organize in folders for IDEs
source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
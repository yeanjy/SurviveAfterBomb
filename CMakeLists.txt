cmake_minimum_required(VERSION 2.8.5...3.27.5)
project(bomba)

# CMake settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# =-=-=-=-=-=-= EXECUTABLE =-=-=-=-=-=-=
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Source files
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(
    SOURCE_FILES
    ${SOURCE_DIR}/survivor.cpp
    ${SOURCE_DIR}/main.cpp
)

# Adding executables
add_executable(bomba ${SOURCE_FILES})

# Header files
target_include_directories(
    bomba
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/include
)

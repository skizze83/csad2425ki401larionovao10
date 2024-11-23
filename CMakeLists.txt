# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(RockPaperScissors VERSION 1.0)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for client
include_directories(${CMAKE_SOURCE_DIR}/client/include)

# Add executable for the RockPaperScissors application
add_executable(RockPaperScissors
    ${CMAKE_SOURCE_DIR}/client/src/main.cpp
    ${CMAKE_SOURCE_DIR}/client/src/serial.cpp
)

# Define preprocessor macros
add_definitions(-DUNICODE -D_UNICODE)

# Link the Windows specific library if on a Windows system
if(WIN32)
    target_link_libraries(RockPaperScissors PRIVATE ws2_32)
endif()

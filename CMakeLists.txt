# Minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(RockPaperScissors)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Specify directories with header files
include_directories(${CMAKE_SOURCE_DIR}/client/include)

# Add an executable file for the client with all the necessary files
add_executable(RockPaperScissors
    ${CMAKE_SOURCE_DIR}/client/src/main.cpp
    ${CMAKE_SOURCE_DIR}/client/src/game.cpp
    ${CMAKE_SOURCE_DIR}/client/src/game_logic.cpp
    ${CMAKE_SOURCE_DIR}/client/src/menu.cpp
    ${CMAKE_SOURCE_DIR}/client/src/serial.cpp
)

# Adding definitions for Unicode support
add_definitions(-DUNICODE -D_UNICODE)

# Specify that the Windows library should be used
if(WIN32)
    target_link_libraries(RockPaperScissors PRIVATE ws2_32)
endif()

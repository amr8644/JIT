# Minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Project name
project(rune)

file(GLOB SOURCES "src/*.c")

add_executable(rune ${SOURCES})
include_directories(includes)

set_property(TARGET rune PROPERTY C_STANDARD 11)

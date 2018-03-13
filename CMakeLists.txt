cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

include(Config.cmake)
project(ray)
add_executable(
        mygame

        src/main.cpp
)

include(raylibDependency.cmake)



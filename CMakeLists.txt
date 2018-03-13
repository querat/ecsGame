cmake_minimum_required(VERSION 3.10)
project(ray)
set(CMAKE_CXX_STANDARD 11)

include(Config.cmake)

add_executable(
        mygame

        src/main.cpp
)

include(raylibDependency.cmake)



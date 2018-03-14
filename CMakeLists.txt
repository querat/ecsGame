cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(ray)

include(ExternalProject)
include(Config.cmake)
include(Dependencies.cmake)

set(MY_EXE_NAME mygame)
set(MY_EXE_SOURCES
        src/main.cpp

        src/Engine.cpp
        src/Engine.h

)
add_executable(${MY_EXE_NAME} ${MY_EXE_SOURCES})

# Build raylib before my project
add_dependencies(${MY_EXE_NAME} raylib)


target_link_libraries(
        ${MY_EXE_NAME}
        PRIVATE glfw
        PRIVATE ${RAYLIB_LIBRARY_FILE}
)
target_include_directories(
        ${MY_EXE_NAME}
        PRIVATE ${EXTERNAL_INSTALL_LOCATION}/include/
)

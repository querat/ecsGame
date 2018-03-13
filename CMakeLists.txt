cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

include(ExternalProject)


# Where to store compiled libs and their headers
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
# Compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

project(ray)

set(MY_EXE_NAME mygame)
add_executable(
        ${MY_EXE_NAME}

        src/main.cpp
)

# Clone and build raylib
ExternalProject_Add(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}

        -DBUILD_EXAMPLES=OFF    # compile error if i build -
        -DBUILD_GAMES=OFF       # - either of those

        -DSTATIC=ON             # I want a .a static library
)

add_dependencies(${MY_EXE_NAME} raylib)

#find_library(
#        RAYLIB_LIBRARY_FILE
#
#        NAMES raylib
#        PATHS ${EXTERNAL_INSTALL_LOCATION}/lib/
#)


target_include_directories(
        ${MY_EXE_NAME}
        PUBLIC ${EXTERNAL_INSTALL_LOCATION}/include/
)


target_link_libraries(
        ${MY_EXE_NAME}
        PUBLIC glfw
        PUBLIC ${RAYLIB_LIBRARY_FILE}
)

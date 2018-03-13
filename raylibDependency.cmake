include(ExternalProject)

# Clone and build raylib
ExternalProject_Add(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}

        -DBUILD_EXAMPLES=OFF    # compile error if i build -
        -DBUILD_GAMES=OFF       # - either of those

        -DSTATIC=ON             # I want a .a static library
)

add_dependencies(mygame raylib)


find_library(
    RAYLIB_LIBRARY_FILE

    NAMES raylib
    PATHS ${EXTERNAL_INSTALL_LOCATION}/lib/
)

target_include_directories(
        mygame
        INTERFACE ${EXTERNAL_INSTALL_LOCATION}/include/
)


target_link_libraries(
        mygame
        INTERFACE glfw
        INTERFACE ${RAYLIB_LIBRARY_FILE}
)
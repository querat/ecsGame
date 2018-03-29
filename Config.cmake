# Where to store compiled libs and their headers
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
# Compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# Better file path in traces
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILENAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
# Name of the to-be-built raylib library file (cross platform)
set(RAYLIB_STATIC_LIBRARY_FILE  ${CMAKE_STATIC_LIBRARY_PREFIX}raylib${CMAKE_STATIC_LIBRARY_SUFFIX})
# Full path of said file so I can link it against my project
set(RAYLIB_LIBRARY_FILE        "${EXTERNAL_INSTALL_LOCATION}/lib/${RAYLIB_STATIC_LIBRARY_FILE}")

# entt ECS engine
set(ENTT_INSTALL_PATH "${CMAKE_BINARY_DIR}/entt/src/entt")  # some CMake hacking
set(ENTT_INCLUDE_PATH "${ENTT_INSTALL_PATH}/src")
# Header-only library. no build step
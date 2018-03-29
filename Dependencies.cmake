# Clone and build raylib

# entt ECS engine
ExternalProject_Add(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt     # Clone this repository
        INSTALL_COMMAND ""                                  # Header-only library -> don't build it
        PREFIX  "${CMAKE_BINARY_DIR}/entt"                  # Define the install path
)

# SFML https://github.com/SFML/SFML/archive/2.4.2.zip
ExternalProject_Add(
        sfml
        URL https://github.com/SFML/SFML/archive/2.4.2.zip
        PREFIX "${CMAKE_BINARY_DIR}/sfml"
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
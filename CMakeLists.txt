cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

project(ray)

include(ExternalProject)
include(Config.cmake)
include(Dependencies.cmake)

#set(CMAKE_CXX_COMPILER clang++)
set(MY_EXE_NAME mygame)
set(
        MY_EXE_SOURCES

        src/main.cpp

        src/Core.h
        src/Core.cpp
        src/Display.h
        src/Display.cpp
        src/system/MovementSystem.h
        src/system/MovementSystem.cpp
        src/system/RenderSystem.h
        src/system/RenderSystem.cpp
        src/component/SpriteComponent.h
        src/component/PositionComponent.h
        src/component/VelocityComponent.h
        src/component/EventComponent.h
        src/utility/Utils.h
        src/utility/Timer.h
        src/utility/Timer.cpp
)
add_executable(${MY_EXE_NAME} ${MY_EXE_SOURCES})

# Build raylib before my project
add_dependencies(
        ${MY_EXE_NAME}
        sfml
        entt
)


target_link_libraries(
        ${MY_EXE_NAME}
        PRIVATE ${EXTERNAL_INSTALL_LOCATION}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}sfml-graphics${CMAKE_SHARED_LIBRARY_SUFFIX}
        PRIVATE ${EXTERNAL_INSTALL_LOCATION}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}sfml-window${CMAKE_SHARED_LIBRARY_SUFFIX}
        PRIVATE ${EXTERNAL_INSTALL_LOCATION}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}sfml-system${CMAKE_SHARED_LIBRARY_SUFFIX}
        PRIVATE ${EXTERNAL_INSTALL_LOCATION}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}sfml-audio${CMAKE_SHARED_LIBRARY_SUFFIX}
        PRIVATE ${EXTERNAL_INSTALL_LOCATION}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}sfml-network${CMAKE_SHARED_LIBRARY_SUFFIX}
)

target_include_directories(

        ${MY_EXE_NAME}
        PRIVATE ${EXTERNAL_INSTALL_LOCATION}/include/
        PRIVATE ${ENTT_INCLUDE_PATH}/
        PRIVATE src/
        PRIVATE src/system
)

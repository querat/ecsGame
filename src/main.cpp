
#include <iostream>
#include "entt/entt.hpp"
#include "Core.h"

struct myEvent {
    int data = 42;
};

struct eventEmitter : public entt::Emitter<eventEmitter> {};

int main()
{
    Core core;

    core.init();
    core.mainLoop();


    return EXIT_SUCCESS;
}

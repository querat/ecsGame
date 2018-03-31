
#include <iostream>
#include "entt/entt.hpp"
#include "Core.h"

int main()
{
    Core core;

    core.init();
    core.mainLoop();


    return EXIT_SUCCESS;
}

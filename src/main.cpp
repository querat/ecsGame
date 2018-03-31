
#include <iostream>
#include "entt/entt.hpp"
#include "Core.h"

int main()
{
    Core core;

    core.init();
    core.mainLoop();
    core.destroy();

    return EXIT_SUCCESS;
}

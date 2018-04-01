//
// Created by pasta on 31/03/18.
//

#ifndef RAY_INPUTSYSTEM_H
#define RAY_INPUTSYSTEM_H

#include "entt/entt.hpp"
#include "../component/InputComponent.h"
#include "Display.h"

class InputSystem {

private:
    Display &       mDisplay;

public:
    InputSystem(Display &display);
    ~InputSystem() = default;

    bool update(entt::DefaultRegistry & registry);
    void resetInputs(InputComponent &inputComponent);
};


#endif //RAY_INPUTSYSTEM_H

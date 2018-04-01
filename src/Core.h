//
// Created by pasta on 16/03/18.
//

#ifndef GAME_CORE_H
#define GAME_CORE_H

#include <deque>
#include <system/InputSystem.h>
#include "entt/entt.hpp"
#include "Display.h"
#include "system/MovementSystem.h"
#include "system/RenderSystem.h"

class Core {

private:
    bool                    mStopping = false;
    Display                 mDisplay;
    entt::DefaultRegistry   mRegistry;

    MovementSystem          mMovementSystem = MovementSystem();
    InputSystem             mInputSystem    = InputSystem(mDisplay);
    RenderSystem            mRenderSystem   = RenderSystem(mDisplay);

public:
    Core() = default;
    ~Core();

    void init();
    void destroy();
    void close();
    void update(float deltaTimeSeconds);
    int mainLoop();

    bool render();
};


#endif //GAME_CORE_H

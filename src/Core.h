//
// Created by pasta on 16/03/18.
//

#ifndef RAY_CORE_H
#define RAY_CORE_H

#include <deque>
#include "entt/entt.hpp"
#include "Display.h"
#include "system/MovementSystem.h"
#include "system/RenderSystem.h"

class Core {

private:
    bool                    mStopping = false;
    Display                 mDisplay;
    entt::DefaultRegistry   mEntityRegistry;

    MovementSystem          mMovementSystem = MovementSystem();
    RenderSystem            mRenderSystem   = RenderSystem(mDisplay);

public:
    Core() = default;
    ~Core();

    void init();
    void close();
    void update();
    int mainLoop();


};


#endif //RAY_CORE_H

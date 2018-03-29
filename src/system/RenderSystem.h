//
// Created by pasta on 26/03/18.
//

#ifndef RAY_RENDERSYSTEM_H
#define RAY_RENDERSYSTEM_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "entt/entt.hpp"
#include "component/SpriteComponent.h"
#include "../Display.h"

class RenderSystem {

private:
    Display &   mDisplay;

public:
    RenderSystem(Display & display);
    ~RenderSystem()                 = default;

    bool        init();
    bool        update(entt::DefaultRegistry &registry);



};


#endif //RAY_RENDERSYSTEM_H

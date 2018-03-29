//
// Created by pasta on 26/03/18.
//

#include "RenderSystem.h"
#include "../Utils.h"

RenderSystem::RenderSystem(Display & display)
    : mDisplay(display) {

}

bool RenderSystem::init() {
    return true;
}

bool RenderSystem::update(entt::DefaultRegistry &registry) {

    sf::RenderWindow * renderWindow = mDisplay.getRenderWindow();

    if (renderWindow == nullptr){
        LOG("Can't render: nullptr RenderWindow")
        return false;
    }

    registry.view<SpriteComponent>().each(
        [renderWindow](auto const &, SpriteComponent const &spriteComponent){
            renderWindow->draw(spriteComponent.sprite);
    });

    return true;
}

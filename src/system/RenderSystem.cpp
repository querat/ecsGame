//
// Created by pasta on 26/03/18.
//

#include <component/PositionComponent.h>
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
    if (renderWindow == nullptr) {
        LOG("called Core::render with no display !")
        return false;
    }

    renderWindow->clear();
    for (auto entity : registry.view<SpriteComponent, PositionComponent>()){
        auto & spriteComponent   = registry.get<SpriteComponent>(entity);
        auto & positionComponent = registry.get<PositionComponent>(entity);

        spriteComponent.sprite.setPosition(
            static_cast<float>(positionComponent.x)
          , static_cast<float>(positionComponent.y)
        );
        renderWindow->draw(spriteComponent.sprite);
    }
    renderWindow->display();

    return true;
}

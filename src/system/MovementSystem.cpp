//
// Created by pasta on 26/03/18.
//

#include <entt/entt.hpp>
#include <component/VelocityComponent.h>
#include "MovementSystem.h"
#include "component/PositionComponent.h"

bool MovementSystem::init() {
    return true;
}

bool MovementSystem::update(entt::DefaultRegistry &registry) {

    // filter entities containing the needed components
    for (auto entity : registry.view<PositionComponent, VelocityComponent>()) {

        // Get the components owned b   y the entity
        auto        & positionComponent = registry.get<PositionComponent>(entity);
        auto const  & velocityComponent = registry.get<VelocityComponent>(entity);

        // Apply movement
        positionComponent.x += velocityComponent.x;
        positionComponent.y += velocityComponent.y;
    }

    return true;
}

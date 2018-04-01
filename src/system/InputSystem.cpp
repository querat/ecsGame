//
// Created by pasta on 31/03/18.
//

#include <cstring>
#include "entt/entt.hpp"
#include "component/InputComponent.h"
#include "utility/Utils.h"
#include "InputSystem.h"

InputSystem::InputSystem(Display &display)
    : mDisplay(display)
{}

void InputSystem::resetInputs(InputComponent & inputComponent){
    memset(&inputComponent, 0, sizeof(InputComponent));
}

bool InputSystem::update(entt::DefaultRegistry & registry) {

        if (not mDisplay.isReady())
        return false;

    for (auto entity : registry.view<InputComponent>()){
        auto &      inputComponent = registry.get<InputComponent>(entity);
        sf::Event   event{};

        memset(&event, 0, sizeof(sf::Event));
        memset(&inputComponent, 0, sizeof(InputComponent));
        while (mDisplay.pollEvent(event)) {

            // todo: clean this shite
            switch (event.type) {

                case sf::Event::MouseButtonPressed:
                    inputComponent.type = InputComponent::InputType::MOUSE_CLICK;
                    inputComponent.click.x = event.mouseButton.x;
                    inputComponent.click.y = event.mouseButton.y;
                    LOG("mouse pressed (x: " << event.mouseButton.x << ", y: " << event.mouseButton.y << ").");
                    break;

                case sf::Event::KeyPressed:
                    LOG("Key pressed: " << event.key.code);
                    break;

                case sf::Event::Closed:
                    LOG("Exit requested.");
                    inputComponent.type = InputComponent::InputType::EXIT_REQUESTED;
                default:
                    break;
            }
        }
    }

    return true;
}

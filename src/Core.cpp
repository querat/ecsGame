//
// Created by pasta on 16/03/18.
//

#include <iostream>
#include "entt/entt.hpp"
#include "Core.h"
#include "utility/Utils.h"
#include "utility/Timer.h"
#include "component/InputComponent.h"
#include "component/SpriteComponent.h"
#include "component/PositionComponent.h"
#include "component/VelocityComponent.h"

Core::~Core() {
    destroy();
}

void Core::destroy() {
    mDisplay.close();
}

void Core::init() {
    mMovementSystem.init();
    mRenderSystem.init();

    auto entity = mRegistry.create(
            SpriteComponent{}, PositionComponent{100, 200}, VelocityComponent{50, 10} // pixels per second
    );
    auto img = new sf::Texture();
    img->loadFromFile("../res/heart.png");
    mRegistry.get<SpriteComponent>(entity).sprite.setTexture(*img);

    auto inputEntity = mRegistry.create(
            InputComponent{}
    );

}

void Core::close() {
    mDisplay.close();
    mStopping = true;
}

void Core::update(float deltaTimeSeconds) {
    mInputSystem.update(mRegistry);
    mMovementSystem.update(mRegistry, deltaTimeSeconds);
}

bool Core::render() {
    return mRenderSystem.update(mRegistry);
}

int Core::mainLoop() {
    Timer timer;
    sf::Event evt{};

    if (not mDisplay.init(1368, 768, "Game")) {
        CERR("Could not create display");
        return EXIT_FAILURE;
    }

    // TODO fix your timestep
    while (not mStopping) {
        update(timer.calcDeltaTimeInSeconds());
        render();

        // TODO prettier way
        mRegistry.view<InputComponent>().each(
            [this](auto /*entityId*/, InputComponent &inputComponent) {
                if (inputComponent.type == InputComponent::InputType::EXIT_REQUESTED) {
                    mDisplay.close();
                    mStopping = true;
                }
            }
        );
    }

    return EXIT_SUCCESS;
}





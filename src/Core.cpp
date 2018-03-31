//
// Created by pasta on 16/03/18.
//

#include <iostream>
#include "Core.h"
#include "utility/Utils.h"
#include "entt/entt.hpp"
#include "component/SpriteComponent.h"
#include "component/PositionComponent.h"
#include "component/VelocityComponent.h"
#include "utility/Timer.h"

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
        SpriteComponent{}
        , PositionComponent{100, 200}
        , VelocityComponent{50, 10} // pixels per second
    );
    auto img = new sf::Texture();
    img->loadFromFile("../res/heart.png");

    mRegistry.get<SpriteComponent>(entity).sprite.setTexture(*img);
}

void Core::close() {
    mDisplay.close();
    mStopping = true;
}

void Core::update(float deltaTimeSeconds) {

    mMovementSystem.update(mRegistry, deltaTimeSeconds);
}

bool Core::render() {
    return mRenderSystem.update(mRegistry);
}

int Core::mainLoop() {
    Timer       timer;
    sf::Event   evt{};

    if (not mDisplay.init(1368, 768, "Game")){
        CERR("Could not create display");
        return EXIT_FAILURE;
    }

    // TODO fix your timestep
    while (not mStopping){
        update(timer.calcDeltaTimeInSeconds());
        render();

        while (mDisplay.pollEvent(evt)){
            if (evt.type == sf::Event::Closed) {
                mDisplay.close();
                mStopping = true;
            }
        }

    }
    return EXIT_SUCCESS;
}





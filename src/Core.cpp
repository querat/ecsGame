//
// Created by pasta on 16/03/18.
//

#include <iostream>
#include "Core.h"
#include "Utils.h"
#include "entt/entt.hpp"
#include "SpriteComponent.h"

Core::~Core() {
    mDisplay.close();
}

void Core::init() {
    mMovementSystem.init();
    mRenderSystem.init();

    auto entity = mEntityRegistry.create(SpriteComponent{});
    auto img = new sf::Texture();
    img->loadFromFile("../res/heart.png");

    mEntityRegistry.get<SpriteComponent>(entity).sprite.setTexture(*img);

}

void Core::close() {
    mDisplay.close();
    mStopping = true;
}

void Core::update() {

    mMovementSystem.update();
    mRenderSystem.update(mEntityRegistry);
}

int Core::mainLoop() {
    if (not mDisplay.init(1368, 768, "Game")){
        CERR("Could not create display");
        return EXIT_FAILURE;
    }

    sf::Event evt;

    // TODO fix your timestep
    while (not mStopping){
        update();
        mDisplay.render();

        while (mDisplay.getRenderWindow()->pollEvent(evt)){
            if (evt.type == sf::Event::Closed) {
                mDisplay.close();
                mStopping = true;
            }
        }

    }
    return EXIT_SUCCESS;
}


